#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

//key value
#define IPC_KEY 0x12345678
//send and recive data
#define TYPE_S 1
#define TYPE_C 2

struct msgbuf{
    long mtype;
    char mtext[1024];
};

int main()
{
    //create msgque
    // msgget()
    int msgid = -1;
    
    msgid = msgget(IPC_KEY, IPC_CREAT | 0664);
    if(msgid < 0){
        perror("msgget error");
        return -1;
    }
    //get data and print by msgque
    // msgsnd()  msgrcv()
    while(1){
        struct msgbuf buf;
        // send data 
        memset(&buf, 0x00, sizeof(struct msgbuf));
        buf.mtype = TYPE_C;
        scanf("%s", buf.mtext);
        msgsnd(msgid, &buf, strlen(buf.mtext)-1, 0);

        // shou data
        msgrcv(msgid, &buf, sizeof(buf.mtext)-1, TYPE_S, 0);
        printf("server say: %s \n", buf.mtext);
    
    } 

    msgctl(msgid, IPC_RMID, NULL);
    //delete msgque
    // msgcrl()

}

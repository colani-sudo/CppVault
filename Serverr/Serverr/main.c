//
//  main.c
//  Serverr
//
//  Created by Colani Matsenjwa on 2022/8/4.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>

using namespace std;

#define MAX_NUM 30

struct Msgbuf
{
    int mtype;
    char context[20];
};

struct Table
{
    char id[20];
    char shmkey[20];
    char password[20];
};
struct Table student[MAX_NUM];

void set_table()
{
    int i=0;
    FILE *in_file;
    in_file=fopen("./students.txt","i");
}

void bzero(char *pointer, size_t size)
{
    int i=0;
    for(i=0; i<size; i++)
        pointer[i]=0;
}

int main(int argc, const char * argv[])
{
    int id, rcvlen, uid;
    int listenfd, connfd, acplen;
    FILE *out_file;
    struct sockaddr_in servaddr, acpaddr, newaddr;
    struct Msgbuf snd, buf;
    set_table();
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   /* for any one IP */
    servaddr.sin_port = htons(9999);                /* service port */
    if(bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr))<0)
    {
        perror("binding error");
        exit(1);
    }
    listen(listenfd, 10);
    for(;;)
    {
        acplen = sizeof(acpaddr);
        connfd = accept(listenfd, (struct sockaddr *) &acpaddr, &acplen);
        if((fork()) > 0)
            continue;
        getpeername(connfd, &servaddr, sizeof(servaddr));
        printf("local IP is %s port is %d\n", inet_ntoa(servaddr.sin_addr),
               ntohs(servaddr.sin_port));
        bzero((char *)&buf, sizeof(buf));
        bzero((char *)&snd, sizeof(snd));
        if((rcvlen=recv(connfd, (char *)&buf, sizeof(buf), 0)) < 0)
        {
            perror("recv error:");
            break;
        }
        if(buf.mtype!=101)  //registry
        {
            snd.mtype = 401;
            snd.context[0]='-';
            snd.context[1]='1';
            send(connfd, (char *)&snd, sizeof(snd),0);
            close(connfd);
            exit(0);
        }
        id=0;
        if((id=find_id(buf.context))>=0){
            printf("id is %d\n",id);
            strcpy(snd.context, student[id].shmkey);
            snd.mtype=201;      //student id correct
        }
        else{
            snd.mtype=402;      //student id error
            snd.context[0]='-';
            snd.context[1]='1';
            send(connfd, (char *)&snd, sizeof(snd), 0);
            close(connfd);
            exit(0);
        }
        if(strcmp(student[id].password, buf.context)==0){
            snd.mtype=203;      //password correct
            snd.context[0]='1';
            snd.context[1]='0';
            snd.context[2]='0';
            out_file=fopen("pass.txt","a");
            fprintf(out_file,"%s, %s, Pass",student[id].id, student[id].password);
            fprintf(out_file,"IP[%s][%d]\n",
                    inet_ntoa(acpaddr.sin_addr), ntohs(acpaddr.sin_port));
            fclose(out_file);
        }
        else
        {
            snd.mtype=404;          //password error
            snd.context[0]='-';
            snd.context[1]='1';
            send(connfd, (char *)&snd, sizeof(snd), 0);
        }
        send(connfd, (char *)&snd, sizeof(snd), 0);
        close(connfd);
        exit(0);
    }
    close(listenfd);
    return 0;
}


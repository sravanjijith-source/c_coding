#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node*link;
}*tos=NULL,*front=NULL,*rear=NULL,*t;
void push(){
    int data;
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->link=tos;
tos=temp;
printf("enter data:");
scanf("%d",&data);
tos->data=data;
}
void pop(){
    if(tos==NULL){
        printf("empty list");
        return ;
    }
    int data=tos->data;
    struct node*temp=tos;
    tos=tos->link;
    temp->link=NULL;
    free(temp);
    printf("removed:%d",data);
}
void display(){
    if(tos==NULL){
        printf("empty list");
        return ;
    }
    struct node*temp=tos;
    for(; temp!=NULL; temp=temp->link)
    printf("%d\n",temp->data);
}
void peek(){
    if(tos==NULL){
        printf("empty list");
        return ;
    }
    printf("%d",tos->data);
}
void enqueue(){
    int data;
    printf("enter data");
    scanf("%d",&data);
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->data=data;
    if(front==NULL)
    front=temp;
    else
    rear->link=temp;
    rear=temp;
}
void dequeue(){
    if(front==NULL){
        printf("empty list");
        return ;
    }
    if(front==rear)
    rear=NULL;
    int data=front->data;
    struct node*temp=front;
    front=front->link;
    temp->link=NULL;
    free(temp);
    printf("deleted:%d",data);
}
void queuedisplay(){
    if(front==NULL){
        printf("empty list");
        return ;
    }
    struct node*temp=front;
    for(; temp!=NULL; temp=temp->link)
    printf("%d ",temp->data);
}
int main(){
    int choice,c;
    bool flag=true,s,q;
    while(flag){
        printf("enter  1.stack 2.queuue 3.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:s=true;while(s){
                printf("enter 1.push 2.pop 3.diaplay 4.exit");
                scanf("%d",&c);
                switch(c){
                    case 1:push();break;
                    case 2:pop();break;
                    case 3:display();break;
                    case 4:s=false;while(tos!=NULL){
                        t=tos;
                        tos=tos->link;
                        t->link=NULL;
                        free(t);
                    }
                }
                }break;
            case 2:q=true;while(q){
                printf("enter 1.enqueue 2.dequeue 3.display 4.exit");
                scanf("%d",&c);
                switch(c){
                    case 1:enqueue();break;
                    case 2:dequeue();break;
                    case 3:queuedisplay();break;
                    case 4:q=false;
                           while(front!=NULL){
                               if(front==rear)
                               rear=NULL;
                            t=front;
                            front=front->link;
                            t->link=NULL;
                            free(t);
                           }
                           break;
                }
            }break;
            case 3:flag=false;
            while(tos!=NULL){
                t=tos;
                tos=tos->link;
                t->link=NULL;
                free(t);
            }
            while(front!=NULL){
                if(front==rear)
                rear=NULL;
                t=front;
                front=front->link;
                t->link=NULL;
                free(t);
            }
            break;
        }
    }
}
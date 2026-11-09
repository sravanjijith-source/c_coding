#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node*llink,*rlink;
}*head,*temp,*t;
void search();
struct node*search_insert();
bool checker();
struct node*getnode(){
    int data;
    printf("enter data");scanf("%d",&data);
    t=(struct node*)malloc(sizeof(struct node));
    t->rlink=NULL;
    t->llink=NULL;
    t->data=data;
    return t;
}
void ifront(){
    temp=getnode();
    if(head!=NULL)head->llink=temp;
    temp->rlink=head;
    head=temp;

}
void irear(){
     temp=getnode();
     if(head==NULL){
        head=temp;
        return ;
     }
     t=head;
     while(t->rlink!=NULL)t=t->rlink;
     t->rlink=temp;
     temp->llink=t;
}
void ikey(){
    t=search_insert;
    if(t==NULL){printf("key not found");return ;}
    temp=getnode();
    temp->rlink=t->rlink;
    t->rlink=temp;
    temp->llink=t;
    if(temp->rlink!=NULL)
    temp->rlink->llink=temp;
}
void dfront(){
    if(checker()){
        return ;
    }
    t=head->rlink;
    if(t!=NULL)t->llink=NULL;
    head->rlink=NULL;
    free(head);
    head=t;
}
void drear(){
    if(checker()){
        return ;
    }
    t=head;
    while(t->rlink!=NULL)
    t=t->rlink;
    temp=t->llink;
    if(temp==NULL)
    head=NULL;
    else
    temp->rlink=NULL;
    t->llink=NULL;
    free(t);
}
void dkey(){
    t=search_insert();
    if(t==NULL){
        printf("not found");
        return ;
    }
    temp=t->llink;
    if(temp==NULL)
    head=t->rlink;
    else
    temp->rlink=t->rlink;
    if(t->rlink!=NULL)
    t->rlink->llink=NULL;
    t->rlink=NULL;
    t->llink=NULL;
    free(t);
}
void display(){
    checker();
    t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->rlink;
    }
}
void displayrev(){
    if(checker())return ;
    t=head;
    while(t->rlink!=NULL)
    t=t->rlink;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->llink;
    }
}
struct node* search_insert(){
    int key;
    printf("enter key");
    scanf("%d",&key);
    t=head;
    while(t!=NULL&&t->data!=key)t=t->rlink;
    return t;
}
void search(){
    int key;
    printf("enter key");
    scanf("%d",&key);
    t=head;
    int i;
    for(i=0; t!=NULL&&t->data!=NULL; i++)t=t->rlink;
    if(t==NULL)printf("not found");
    else
    printf("found by %d",i);
    
}
bool checker(){
    head==NULL?printf("empty list");return true;:return false;
}
int main(){
    int choice,t,key;
    bool flag=true;
    while(flag){
        printf("\nenter  1.insertfront 2.insertrear 3.insertkey 4.deletefront 5.deleterear 6.deletekey 7.display 8.displayreverse 9.search 10.exit");
        scanf("%d",choice);
        switch(choice){
            case 1:ifront();break;
            case 2:irear();break;
            case 3:ikey();break;
            case 4:dfront();break;
            case 5:drear();break;
            case 6:dkey();break;
            case 7:display();break;
            case 8:displayrev();break;
            case 9:search();break;
            default:printf("*****thankyou*****");flag=false;
        }
    }
}
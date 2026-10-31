#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 100
char stack[MAX];
char infix[30];
int tos=-1;
bool flag=false;
void push(char t){
stack[++tos]=t;
}
char pop(){
    return stack[tos--];
}
void topostfix(){
    int n=strlen(infix),i,j=0;
    char  postfix[30];
    char t;
    for(i=0; i<n; i++)
    {
        if(infix[i]>=65&&infix[i]<=90||(infix[i]>=97&&infix[i]<=122))
            postfix[j++]=infix[i];
            else{
        if(infix[i]=='(')
        push(infix[i]);
        else if(infix[i]==')')
        {
            while(tos!=-1&&stack[tos]!='(')
            {
                postfix[j]=pop();
                j++;
            }
            if(tos!=-1)
            t=pop();
        }
        else{
            if(flag){
            if(infix[i]=='^')
            {
                if(tos!=-1&&stack[tos]=='^')
                postfix[j++]=pop();
                push(infix[i]);
            }
            else if(infix[i]=='*'||infix[i]=='%'||infix[i]=='/'){
                if(tos!=-1&&stack[tos]=='^')
                postfix[j++]=pop();
                push(infix[i]);
            }
            else{
            while(tos!=-1&&(stack[tos]=='*')||stack[tos]=='%'||stack[tos]=='/'||stack[tos]=='^')                
            postfix[j++]=pop();
                push(infix[i]);
            }

        }
        else{
            if(infix[i]=='^')
            push(infix[i]);
            else  if(infix[i]=='*'||infix[i]=='%'||infix[i]=='/'){
                while(tos!=-1&&(stack[tos]=='^'||stack[tos]=='*'||stack[tos]=='%'||stack[tos]=='/'))
                postfix[j++]=pop();
                push(infix[i]);
            }
            else{
                while(tos!=-1&&(stack[tos]=='^'||stack[tos]=='*'||stack[tos]=='%'||stack[tos]=='/'||stack[tos]=='+'||stack[tos]=='-'))
                postfix[j++]=pop();
                push(infix[i]);
            }
        }
        }
    }
    }
    while(tos!=-1)
    postfix[j++]=pop();
    postfix[j]='\0';
    if(flag){
        strrev(postfix);
    }
    printf("%s",postfix);
}
void toprefix(){
    flag=true;
    strrev(infix);
    int n=strlen(infix);
    for(int i=0; i<n; i++)
    {
        if(infix[i]=='(')
        infix[i]=')';
        else if(infix[i]==')')
        infix[i]='(';
    }
    topostfix();
}
int main(){
    int choice;
    printf("enter infix:");
    scanf("%s",infix);
    printf("enter 1.to postfix 2.toprefix 3.both");
    scanf("%d",&choice);
    if(choice==1)
    topostfix();
    else if(choice==2)
    toprefix();
    else {
    topostfix();
    toprefix();
    }
    return 0;
}
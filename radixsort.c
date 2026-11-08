#include<stdio.h>
#include<stdlib.h>
void radixsort(int exp,int largest,int *a,int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]/exp%10>a[j+1]/exp%10){
                a[j]+=a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]-=a[j+1];
            }
        }
    }
}
int main(){
    int n;
    printf("enter the size of the array");
    scanf("%d",&n);
    int a[n];
    printf("enter the array");
    int i,largest;
    for(i=0; i<n; i++){
        if(i==0||largest<a[i])
        largest=a[i];
        scanf("%d",&a[i]);
    }
    int exp=1;
    for(; largest/exp>0; exp*=10){
        radixsort(exp,largest,a,n);
    }
    for(i=0; i<n; i++)printf("%d ",a[i]);

}
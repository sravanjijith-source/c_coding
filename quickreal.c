#include<stdio.h>
#include<stdlib.h>
int partition(int,int,int*);
void quick(int low,int high,int*a){
if(low<high){
    int mid=partition(low,high,a);
    quick(low,mid-1,a);
    quick(mid+1,high,a);
}
}
int partition(int low,int high,int *a){
    int pivot=a[low];
    int i=low,j=high,t;
    while(i<j){
        while(i<high&&a[i]<=pivot)i++;
        while(j>=low&&a[j]>pivot)j--;
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        else{
            t=a[low];
            a[low]=a[j];
            a[j]=t;
        }
    }
    return j;
}
int main(){
    int n;
    printf("enter no. of elements in array:");
    scanf("%d",&n);
    int a[n],i;
    printf("enter elements:\n");
    for(i=0; i<n; i++)
    scanf("%d",&a[i]);
    quick(0,n-1,a);
    printf("sorted array");
    for(i=0; i<n; i++)
    printf("%d ",a[i]);
}
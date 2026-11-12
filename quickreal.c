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
    int i=low,j=high;
    while(i<j){
        while(i<high&&a[i]<=pivot)i++;
        while(j>=low&&a[j]>pivot)j--;
        if(i<j){
            a[j]+=a[i];
            a[i]=a[j]-a[i];
            a[j]-=a[i];
        }
        else{
            a[j]+=pivot;
            a[low]=a[j]-pivot;
            a[j]-=a[low];
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
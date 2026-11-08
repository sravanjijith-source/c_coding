#include<stdio.h>
#include<stdlib.h>
void radixsort(int exp,int largest,int *a,int n){
    int freq[largest+1]={0};
    for(int i=0; i<n; i++){
        freq[a[i]]++;
    }
    int k=0;
    for(int i=0; i<=largest; i++){
        while(freq[i]>0){
            a[k++]=i;
            freq[i]--;
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

}
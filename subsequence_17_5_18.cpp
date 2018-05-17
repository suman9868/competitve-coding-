/*
this is simple program to print all subsequence of given array

done by: SUMAN KUMAR(suman9868)
date : 17 may 18
time : 1:30 am

*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define max 10001

void subsequence(int a[],int n){
    for(int i=1; i<pow(2,n); ++i){
        for(int j=0; j<n; ++j){
            if(i & (1<<j))
                printf("%d ",a[j]);    //cout<<a[j]<<" "; 
        }
        printf("\n"); //cout<<endl;
    }
}
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[max];
        for(int i=0; i<n; ++i)
            scanf("%d",&a[i]);
        subsequence(a,n);
    }
    return 0;
}

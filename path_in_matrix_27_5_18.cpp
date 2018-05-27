/*
geeksforgeeks dynamic programming problem
problem url: 
https://practice.geeksforgeeks.org/problems/path-in-matrix/0

done by: SUMAN KUMAR(suman9868)
date : 27 may 2018
time : 6 pm

*/
#include <iostream>
#include <cstdio>    // for scanf(), printf()
#include <algorithm> // for sort(), min(), max(), swap()
#include <cstring>   // for memset() 
using namespace std;
#define max_size 21

int path(int a[][max_size],int i,int j,int n,int temp[][max_size]){

    if(i<0 or i>n or j<0 or j>n)
        return 0;
    if(temp[i][j]!= -1)
        return temp[i][j];
    temp[i][j] = a[i][j]+max(path(a,i+1,j,n,temp), max(path(a,i+1,j-1,n,temp), path(a,i+1,j+1,n,temp) ));

    return temp[i][j];
}

int call(int a[][max_size], int n,int temp[][max_size]){
    int sum = 0;
    for(int i=0; i<=n; i++){
        int t1 = path(a,0,i,n,temp);
        if(t1>sum)
            sum = t1;
    }
    return sum;
}

int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[max_size][max_size];
        int temp[max_size][max_size];
        memset(temp,-1,sizeof(temp));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        int val = call(a,n-1,temp);
        printf("%d\n",val);
    }
    return 0;
}

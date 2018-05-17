/*
subset sum problem:

time complexicity: O(n)

done by : SUMAN KUMAR(suman9868)
date : 17 may 2018
time : 1 am

*/
#include <iostream>
#include <cstdio>
using namespace std;

int subset(int a[], int value, int n){
    //int sum = a[0];
    int pos = 0;
    int sum = 0;
    for(int i=0; i<n; ++i){
        sum = sum + a[i];

        while(sum>value and pos<=i){
            sum = sum - a[pos];
            pos++;
        }

        if(sum == value)
            return 1;
    }
    return 0;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,value;
        scanf("%d%d",&n,&value);
        int a[n];
        for(int i=0; i<n; ++i)
            scanf("%d",&a[i]);
        if(subset(a,value,n))
            printf("Value found\n");
        else
            printf("Value not found\n");
    }
    return 0;
}

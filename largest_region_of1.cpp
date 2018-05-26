/*

geeksforgeeks problem
problem url:
https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0/?ref=self

done by: SUMAN KUMAR(suman9868)
date: 26 may 2018
time : 1am
*/
#include <iostream>
#include <cstdio>
using namespace std;
#define max_size 50
int n,m;
int counter;
int transform(int a[max_size][max_size],int i,int j){
    
    if(i<0 or i>=n or j<0 or j>=m)
        return 0;
    
    if(a[i][j]==0)
        return 0;

    if(a[i][j]==1){
        a[i][j] = 0;
        counter++;
        transform(a,i+1,j);
        transform(a,i-1,j);
        transform(a,i,j+1);
        transform(a,i,j-1);
        transform(a,i-1,j-1);
        transform(a,i+1,j+1);
        transform(a,i+1,j-1);
        transform(a,i-1,j+1);
    }
    return 0;
}

int main(){
    int t;    
    scanf("%d",&t);
    while(t--){
        //int n,m;
        scanf("%d%d",&n,&m);
        int a[max_size][max_size];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%d",&a[i][j]);
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]==1){
                    counter=0;
                    //int temp = transform(a,i,j);
                    transform(a,i,j);
                    //if(count<temp)
                    //    count = temp;
                    if(counter>count)
                        count = counter;
                    //cout<<counter<<" counter "<<endl;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

/*
this is trt problem of spoj problem
again i am doing to just practice again and again till my concept become very clear 

done by : SUMAN KUMAR(suman9868)
date : 22 may 2018
time : 2:50 pm

*/

#include <iostream> 
#include <cstdio>  // for scanf(), printf()
#include <vector> // for vetor <int> 
#include <algorithm> // for max(), min(), sort(), 
#include <cstring>  // for memset()
using namespace std;
#define max_size  101
int dp[max_size][max_size];
int trt(const vector <int>& v, int start, int end, int year){
    if(start > end)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];
    dp[start][end] = max(year*v[start]+trt(v,start+1,end,year+1), year*v[end]+trt(v,start,end-1,year+1));
    return dp[start][end];
}

int main(){
    int a[] = {2,3,5,1,4};
    vector <int > v(a,a+5);
    //int dp[v.size()+1][v.size()+1];
    memset(dp,-1,sizeof(dp));
     for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            printf("%d ",dp[i][j]);            
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<v.size(); i++)
        printf("%d ",v[i]);
    printf("\n");
    printf("%d ",trt(v,0,v.size()-1,1));
    printf("\n");
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            printf("%d ",dp[i][j]);            
        }
        printf("\n");
    }
    return 0;
}

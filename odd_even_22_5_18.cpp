/*
this is basic dp problme of hackeerarth 

done by :SUMAN KUMAR(suman9868)
date : 22 may 2018
time : 5:30 pm
*/
#include <iostream>
#include <cstdio> // for scanf(), printf()
#include <vector>  // for vector<>
#include <cstring> // for memset()
using namespace std;
//#define max_size 200001
#define max_size 201
int dp[max_size][max_size];

int odd_even(const vector <int>& v, int start, int end){
    
    if(start == end){
        dp[start][end] = 0;
        return 0;
    }
    if(start>end)
        return 0;
    if(v[start] != v[start+1]){
        //dp[start][end] = max(
        dp[start][end] = 1 + max(dp[start-1][end]+odd_even(v,start+1,end) , dp[start][end-1]+odd_even(v,start,end-1));   
    }
    if(v[start]==v[start+1]){
        dp[start][end] = max(dp[start-1][end]+odd_even(v,start+1,end) , dp[start][end-1]+odd_even(v,start,end-1));
    }
    return dp[start][end];
}

int main(){
    int n,temp;
    scanf("%d",&n);
    vector <int> v(n);
    for(int i=0; i<n; i++){
        scanf("%d",&temp);
        v[i] = temp % 2;
    }
    //for(int i=0; i<n; i++)
    //    printf("%d ",v[i]);
    //int dp[n][n];
    memset(dp,-1,sizeof(dp));
   
    printf("%d",odd_even(v,0,n-1));
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ",dp[i][j]);   //cout<<dp[i][j]<<" ";
        printf("\n");
    }
    
    return 0;
}

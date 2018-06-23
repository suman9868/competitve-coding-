/*
spoj dynamic programming problem
problem url: 
https://www.spoj.com/problems/COINS/

done by: SUMAN KUMAR
date: 24 june 2018
time: 2:44 am

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // for max()
using namespace std;

long long int coins(long long int n, vector <long long int> &dp){
    if(n<=3)
        return n;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = max(n, coins(n/2,dp)+coins(n/3,dp)+coins(n/4,dp));
    return dp[n];
}

int main(){
    string str;
    while(getline(cin,str) and !str.empty()){
        int num = stoi(str);
        long long int n = num;
        vector <long long int> dp(n+1, -1);
        long long int val = coins(n,dp);
        cout<<val<<endl;
    }
    return 0;
}

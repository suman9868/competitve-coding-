/*
knapsack dynamic programming problem
problem url:
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

done by: SUMAN KUMAR(suman9868)
date: 24 june 2018
time: 8:20 pm
*/
#include <iostream>
#include <cstdio>
#include <vector> // for vector<int> 
#include <algorithm> // for max(), min(), sort(), swap(a,b)
using namespace std;

int knapsack(vector <int> &n_val, vector <int> &w_weight, int n, int w){
    vector < vector<int> > dp(n+1, vector<int>(w+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(w_weight[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(n_val[i-1]+dp[i-1][j-w_weight[i-1]], dp[i-1][j]);
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=w; j++){
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[n][w];
}

int main()
 {
	//code
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int w;
	    scanf("%d",&w);
	    vector<int> n_val(n);
	    for(int i=0; i<n; i++)
	        scanf("%d",&n_val[i]);
	    vector <int> w_weight(n);
	    for(int i=0; i<n; i++)
	        scanf("%d",&w_weight[i]);
	    int val = knapsack(n_val, w_weight, n, w);
	    printf("%d\n",val);
	}
	return 0;
}

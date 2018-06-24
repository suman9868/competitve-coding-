/*
knapsack dynamic programming problem
problem url:
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

done by: SUMAN KUMAR(suman9868)
date: 24 june 2018
time: 8:20 pm
*/
#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <vector> // for vector<int> 
// #include <algorithm> // for max(), min(), sort(), swap(a,b)
using namespace std;

int knapsack(int start, int end, int W, vector < pair<int,int> >wt_val){
    if(start == end)
        return 0;
    if(W<=0)
        return 0;
    if(wt_val[start].first <= W)
        return max(wt_val[start].second+knapsack(start+1,end,W-wt_val[start].first,wt_val), knapsack(start+1, end, W,wt_val));
    else
        return knapsack(start+1,end,W,wt_val);
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
	    
	    vector < pair<int,int> > wt_val;
	    for(int i=0; i<n; i++){
	        wt_val.push_back(make_pair(w_weight[i],n_val[i]));
	    }
	    int val = knapsack(0,n,w,wt_val);
	    
	    printf("%d\n",val);
	}
	return 0;
}

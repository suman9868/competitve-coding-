/*
hackerrank disjoint set problem 
problem url:
https://www.hackerrank.com/challenges/components-in-graph/problem

done by: SUMAN KUMAR(suman9868)
date: 30 june 2018
time: 3:04 am

*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int root(int i, vector <int> &id){
    while(i != id[i])
        i = id[i];
    return i;
}

int main(){
    int n;
    cin>>n;
    vector <int> id(2*n+1);
    for(int i=1; i<=2*n; i++)
        id[i] = i;
    vector <int> count(2*n+1, 1);
    int i=n; 
    int x,y;
    while(i--){
        cin>>x>>y;
        int small_x = root(x, id);
        int big_y = root(y, id);
        if(small_x<=n){
            id[small_x] = big_y;
            count[big_y] +=1;
        }
        else{
            if(small_x < big_y){
                id[small_x] = big_y;
                count[big_y] += count[small_x];
                count[small_x] = 0;
            }
            else if(big_y < small_x){
                id[big_y] = small_x;
                count[small_x] += count[big_y];
                count[big_y] = 0;
            }
        }
    }
    int small = 1e9, big = 0;
    for(int i=n+1; i<=2*n; i++){
        if(count[i] != 1 and count[i] != 0){
            if(count[i]<small)
                small = count[i];
            if(count[i]>big)
                big = count[i];
        }
    }
    cout<<small<<" "<<big;
    return 0;
}

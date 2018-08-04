/*
spoj minimum spanning tree problem
problem url:
https://www.spoj.com/problems/MST/

done by: SUMAN KUMAR(suman9868)
date: 4 august 2018
time: 10pm
*/
//#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define max_size 10001
vector < pair< long long int, pair<long long int,long long int> > > vec;
//vector <int> id(max_size, 0);

void initialize(vector <long long int> &id, long long int n){
    for(int i=0; i<=n; i++)
        id[i] = i;
}

long long int findId(long long int x, vector <long long int> &id){
    while(x != id[x])
        x = id[id[x]];
    return x;
}

void union1(long long int x,long long int y, vector<long long int> &id){
    long long int x_root = findId(x,id);
    long long int y_root = findId(y,id);
    if(x_root < y_root){
        id[y_root] = x_root;
    }
    else
        id[x_root] = y_root;
}

long long int kruskal(long long int n,long long int m, vector <long long int> &id){
    long long int total = 0,i=0;
    while(i<m){
        pair <long long int, pair<long long int,long long int> > p = vec[i];  
        long long int wt = p.first;
        long long int x = p.second.first;
        long long int y = p.second.second;
        if(findId(x,id) != findId(y,id)){
            total += wt;
            union1(x,y,id);
        }
        i++;
    }
    return total;
}
int main(){
    //initialize();
    long long int n,m;
    cin>>n>>m;
    vector <long long int> id(n+1, 0);
    initialize(id,n);
    long long int t = m;
    while(t--){
        long long int i,j,k;
        cin>>i>>j>>k;
        vec.push_back(make_pair(k, make_pair(i,j)));
    }
    sort(vec.begin(), vec.end());
    /*
    for(int i=0; i<m; i++){
        pair <int, pair<int,int> > p = vec[i];
        cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    }
    */
    cout<<kruskal(n,m,id)<<endl;
    return 0;
}

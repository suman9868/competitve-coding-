/*
    dijkastra implementation using priority queue(heap)
    
    done by: SUMAN KUMAR
    date : 18 june 2018
    time : 6 pm
*/

#include <iostream>
#include <cstdio>     // for scanf(), printf();
#include <vector>     // for vector<int> v;
#include <queue>      //for queue <int> q;, priority_queue<int> pq;
#include <map>        // for map<int,int> m, multimap<int,int> mp;
#include <set>        // for set<int> s, multiset<int> ms;
#include <stack>      // for stack<int> s;
#include <cstring>    // for string related work
#include <algorithm>  // for max(), min(), swap(a,b), sort(a,a+n)
#include <utility>    // for pair<int, int>
#include <functional> // for greater<int> in case of min priority queue function creation
using namespace std;

#define max_size 10001
vector < pair<int,int> > v[max_size];
vector <bool> flag(max_size, false);
vector <int> dist(max_size, 1e9);

void dijkstra(int source){
    priority_queue < pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push(make_pair(0,source));
    dist[source] = 0;
    while(!pq.empty()){
        pair <int,int> p;
        p = pq.top();
        pq.pop();
        int x = p.second;
        int wt = p.first;
        if(flag[x] == true)
            continue;
        flag[x] = true;
        for(int i=0; i<v[x].size(); i++){
            int xx = v[x][i].second;
            int wtwt = v[x][i].first;
            if(dist[xx] > wtwt+dist[x])
                dist[xx] = wtwt+dist[x];
            pq.push(make_pair(dist[xx],xx));
        }
    }
}
int main(){
    int nodes,edges;
    scanf("%d%d",&nodes,&edges);
    for(int i=0; i<edges; i++){
        int x,y,wt;
        scanf("%d%d%d",&x,&y,&wt);
        v[x].push_back(make_pair(wt,y));
        v[y].push_back(make_pair(wt,x));
    }
    int source;
    scanf("%d",&source);
    dijkstra(source);
    for(int i=1; i<=nodes; i++)
        cout<<dist[i]<<" ";
    return 0;
}

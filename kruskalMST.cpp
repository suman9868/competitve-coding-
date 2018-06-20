#include <bits/stdc++.h>

using namespace std;
#define max_size 100001

pair <int, pair <int,int> > p[max_size];  // vector < source[i] < weight - destination > > 
int id[max_size];                         // to avoid the cycle 
 
void initialise(){                        // each vertex is point to itself
    for(int i=1; i<max_size; i++)
        id[i] = i;
}

int root(int i){                          // to find the parent root of each vertex
    while(i != id[i])
        i = id[i];
    return i;
}

void union1(int i, int j){               // to do union of two vertex 
    int root_i = root(i);
    int root_j = root(j);
    if(root_i < root_j)
        id[root_i] = id[root_j];
    else
        id[root_j] = id[root_i];
}

long long int kruskal(int g_edges){     // implementing kruskal 
    long long int total = 0;
    for(int i=0; i<g_edges; i++){
        int wt = p[i].first;
        int x = p[i].second.first;
        int y = p[i].second.second;
        if(root(x) != root(y)){
            total += wt;
            union1(x,y);
        }
    }
    return total;
}
int main()
{
    initialise();
    int g_nodes;
    int g_edges;

    cin >> g_nodes >> g_edges;
    

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    }

    // Write your code here.
    for(int i=0; i<g_from.size(); i++){
        int wt = g_weight[i];
        int x = g_from[i];
        int y = g_to[i];
        p[i] = make_pair(wt, make_pair(x,y));
    }
   
    sort(p,p+g_edges);
   
    long long int total = kruskal(g_edges);
    cout<<total;
    return 0;
}

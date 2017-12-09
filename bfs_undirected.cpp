/*
    this is program showing bfs implementation using stl library
    i have seen this program of nickzuck before writing but not while writing, so credit goes to him and i want to learn only, nothing else.

    submitted by : Suman Kumar
    data: 9 december 2017
    time: 8 pm

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define max 100
vector<int> vec[max];
bool visited[max];
queue<int> q;

void bfs(int start)
{
    q.push(start);
    visited[start] = true;
    //cout<<start<<" ";
    while(!q.empty())
    {
        //cout<<q.front();
        int temp = q.front();
        cout<<temp<<" ";
        for(int i=0; i<vec[temp].size(); i++)
        {
            if(visited[vec[temp][i]]==false)
            {
                q.push(vec[temp][i]);
                visited[vec[temp][i]] = true;
            }
        }         
        q.pop();
    }
}
int main()
{
    int node, edge,i , x, y;
    cout<<"Enter the number of nodes ";
    cin>>node;
    cout<<"Enter the number of edges ";
    cin>>edge;  
    for(i=1; i<=edge; i++)
    {
        cin>>x>>y;  
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(i=1; i<=node; i++)
        visited[i] = false;
    
    cout<<"bfs order of given graph is ";
    bfs(1);
    return 0;
}

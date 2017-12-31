/*
    below is dfs undirected graph to print dfs order 
    here i have written the code based on the understanding of bfs implementation

    submitted by : Suman Kumar
    time : 09 december 2017
    
*/
#include <iostream>
#include <vector>
using namespace std;

#define max 50
vector<int> vec[max];
bool visited[max];

vector<int> stack;

void dfs(int start)
{
    //vector<int> stack;
    stack.push_back(start);
    visited[start] = true;
    //while(!stack.empty())
    {
        int temp = stack.back();
        cout<<temp<<" ";    
        for(int i=0; i<vec[temp].size(); i++)
        {
            if(visited[vec[temp][i]] == false)
            {
                stack.push_back(vec[temp][i]);   
                //visited[vec[temp][i]] = true;
                dfs(vec[temp][i]);
            }
        }                
        stack.pop_back();
    }    
}

int main()
{
    int node, edge, i,x,y;
    cout<<"Enter the number of node " ;
    cin>>node;
    cout<<"Enter the number of edges ";
    cin>>edge;
    for(i=1; i<=edge; i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(i=0; i<max; i++)
        visited[i]=false;
    dfs(0);
    return 0;
}

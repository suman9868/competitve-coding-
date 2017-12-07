#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m,i;
    cin>>n>>m;
    int f[1001];
    for(i=0; i<m; i++)
        cin>>f[i];
    //f.sort();
    sort(f,f+m);
    //for(i=0; i<m; i++)
      //  cout<<f[i]<<endl;
    int diff=100000;    
    for(i=n-1; i<m; i++)
    {
        if((f[i]-f[i-n+1])<diff)
            diff = f[i]-f[i-n+1];
        //cout<<diff<<endl;
    }
    cout<<diff;//<<endl;
    return 0;
}

/*
    this is dynamic programming hackerrank problem

    submitted by: Suman Kumar
    date : 6 january 2017
    time : 9 pm

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int n,m,i,j;
    long long int a[51];
    cin>>n>>m;
    for(i=0; i<m; i++)
        cin>>a[i];
    sort(a,a+m);
    
    long long int result[n+1];
    for(i=0; i<=n; i++)
        result[i] = 0;
    result[0] = 1;
    for(i=a[0]; i<=n; i=i+a[0])
        result[i] = 1;

    //for(i=0; i<=n; i++)
      //  cout<<result[i]<<" ";
    //cout<<endl;

    for(i=1; i<m; i++)
    {
        int temp = a[i];
        for(j=temp; j<=n; j++)
        {
            result[j] = result[j] + result[j-temp];
        }

        //for(k=0; k<=n; k++)
          //  cout<<result[k]<<" ";
        //cout<<endl;
    }
    cout<<result[n];
    return 0;
}

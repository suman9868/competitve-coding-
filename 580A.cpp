#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int a[100002];
    int temp[100002];
    //cout<<temp[2]<<endl<<temp[1];
    for(i=0; i<n; i++)
    {    
        cin>>a[i];
        temp[i] = 1;
    }
    //int max=1;
    for(i=1; i<n; i++)
    {
        if(a[i] >= a[i-1])
            temp[i] = temp[i] + temp[i-1];
    }
    sort(temp,temp+n);
    cout<<temp[n-1];
    return 0;
}

/*
    
    codeforces prblem: Maximum increase
    problem code : 702A
    
    submitted by : Suman kumar
    date : 12 december 2017 
    time : 9:30 pm
*/
#include <iostream>
using namespace std;
#define max 100002

int main()
{
    int n;
    cin>>n;
    int a[max],temp[max],i;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        temp[i] = 0;
    }            
    temp[0] = 1; // first element length will always be 1
    int maximum_len = 1;
    for(i=1; i<n; i++)
    {
        if(a[i] > a[i-1])
        {
            temp[i] = temp[i-1] + 1;
            if(maximum_len < temp[i])
                maximum_len = temp[i];
        }
        else
        {
            temp[i] = 1;
            //if(maximum_len < temp[i-1])
              //  maximum_len = temp[i-1];
        }
    }
    cout<<maximum_len;
    return 0;
}

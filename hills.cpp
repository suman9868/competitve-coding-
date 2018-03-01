/*
codechef easy problem
prblem code : HILLS

submitted by : Suman Kumar
date : 01 march 2018
time : 7:18 pm
*/
#include <iostream>
using namespace std;
#define size 101
int main()
{
    int t,array[size],i;
    cin>>t;
    int n, u, d;
    while(t--)
    {
        cin>>n>>u>>d;
        for(i=0; i<n; i++)
            cin>>array[i];
        int count_d=1;        
        for(i=1; i<n; i++)
        {
            if(array[i]>array[i-1])
            {
                if(array[i-1]+u < array[i])
                    break;    
            }
            else if(array[i] < array[i-1])
            {
                if(array[i]+d < array[i-1])
                    if(count_d)
                        count_d=0;
                    else    
                        break;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}

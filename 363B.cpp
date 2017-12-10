/*
    last wrong was done 2 year back and finally now submitted.
    codeforces problem
    fence [ 363B ]
    
    submitted by : Suman Kumar
    date : 10 december 2017
    time : 8:40 pm

*/
#include <iostream>
using namespace std;
#define max 150002

int main()
{
    int n,k,h[max],temp,i;
    cin>>n>>k;
    for(i=1; i<=n; i++)
        cin>>h[i];
    
    int pos=n-k+1;
    
    temp = h[n];
    for(i=n-1; i>=n-k+1; i--)
        temp = temp + h[i];
    int min = temp;
    //cout<<temp<<" ";
    //cout<<pos<<" ";
    for(i=n-k; i>=1; i--)
    {
        //cout<<temp<<" ";
        //cout<<h[i]<<" ";
        //int t = temp;
        //cout<<"t "<<t<<" ";
        temp = temp+h[i]-h[i+k];
        //if(((temp+(h[i]))-(h[i+k])) < temp)
        if(min>temp)
        {
            pos = i;
            min = temp;
            //cout<<pos<<" ";            
        }
        //temp = temp+h[i]-h[i+k];
        //cout<<temp<<" ";
    }
    cout<<pos;
    return 0;
}

/*
    codeforces dynamic programming problem

    Submitted By : Suman Kumar
    date : 7 january 2018
    time : 12 pm
*/
#include <iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}    
int value(int arr[],int i,int j,int count,int pre)
{
    if(i>j)
        return count;
    else if(arr[i]==0)
        value(arr,i+1,j,count,0);
    else if(arr[i]==1)
    {
        if(pre==1)
        {
            value(arr,i+1,j,count,0);
        }
        else
            value(arr,i+1,j,1+count,1);
    }
    else if(arr[i]==2)
    {
        if(pre==2)
        {
            value(arr,i+1,j,count,0);
        }
        else
            value(arr,i+1,j,1+count,2);
    }
    else//arr[i]==3
    {
        if(pre==1)
        {
            value(arr,i+1,j,1+count,2);
        }
        else if(pre==2)
        {
            value(arr,i+1,j,1+count,1);
        }
        else//pre==0
        {
            int t=max(value(arr,i+1,j,1+count,1),value(arr,i+1,j,1+count,2));
            return t;
        }
    }    
}
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
        cin>>arr[i];  
    cout<<(n-value(arr,0,n-1,0,0));
    return 0;
}   


//
/*
    189/A problem
    problem name : Cut Ribbon
    
    submitted by: Suman Kumar
    done on: 9 december 2017
    time : 12:39 pm
*/
#include <iostream>
using namespace std;
//int a,b,c;
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int main()
{
    int n,a1,b1,c1;
    cin>>n>>a1>>b1;
    int a,b,c;  
    if(a1>=b1)
    {
        a=a1;
        b=b1;
    }
    else
    {
        a=b1;
        b=a1;
    }
    cin>>c1;
    if(c1<=b)
        c=c1;
    else if(c1>b && c1<=a)
    {
        c=b;
        b=c1;
        //c=b1;
    } 
    else
    {
        c=b;
        b=a;
        a=c1;
    }
    //cout<<a<<endl<<b<<endl<<c<<endl;
    int temp[n+1],i;
    for(i=0; i<=n; i++)
        temp[i] = 0;
    for(i=c; i<=n; i++) 
    {   
        if(i%c==0)
            temp[i]=i/c;       
    }    
    //for(i=1; i<=n; i++)
      //  cout<<temp[i]<<" ";
    for(i=b; i<=n; i++)
    {
        if(i%b==0)
            temp[i]=max(temp[i], i/b);
        //else
        //{
            if(temp[i-b]!=0)
                temp[i]=max(temp[i],temp[i-b]+1);                        
        //}
    }
    for(i=a; i<=n; i++)
    {
        if(i%a==0)
            temp[i]=max(temp[i], i/a);
        //else
        //{
            if(temp[i-a]!=0)
                temp[i]=max(temp[i],temp[i-a]+1);                        
        //}
    }
    cout<<temp[n];
    return 0;
}

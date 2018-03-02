/*
    this is codechef march long challenge div 2 problems
    problem code : CHEGLOVE

    submitted by : Suman Kumar
    date : 2 march 2018
    time : 7:51 pm
*/

#include <iostream>
using namespace std;
#define max 100002

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int l[max], g[max];
        int front=1, back=1,i;
        for(i=0; i<n; i++)
            cin>>l[i];
        for(i=0; i<n; i++)
            cin>>g[i];
        
        for(i=0; i<n; i++)
        {
            if(l[i] > g[i])
                front=0;
            if(l[i] > g[n-i-1])
                back=0;
        }
        if(front and back)
            cout<<"both"<<endl; 
        else if(front)
            cout<<"front"<<endl;
        else if(back)
            cout<<"back"<<endl;
        else
            cout<<"none"<<endl;
    }
    return 0;
}

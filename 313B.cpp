/*
 
    codeforces problems : IIya and Queries
    problem code : 313B
        
    submitted By : Suman Kumar
    date : 12 december 2017
    time : 9 pm

*/
#include <iostream>
using namespace std;
#define max 100002

int main()
{
    string s;
    cin>>s;
    int len = s.length();
    int temp[len],i;
    for(i=0; i<len; i++)
        temp[i] = 0;
    for(i=len-2; i>=0; i--)
    {
        if(s[i] == s[i+1])
            temp[i] = temp[i+1] + 1;
        else
            temp[i] = temp[i+1];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<temp[l-1]-temp[r-1]<<endl;
    }
    return 0;
}

/*
this is a basic tree problem of codeforces
problem code : 339/D

submitted by: SUMAN KUMAR(suman9868)
time : 10:20 pm
date : 11 june 2018
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //cout<<1 or 2;
    int n,m;
    cin>>n>>m;
    int i,j;
    //cout<<pow(2,n)<<endl;
    int s = pow(2,n+1);
    int a[s]; // used 1 based indexing
    //cout<<s;
    for(i=pow(2,n); i<pow(2,n+1); ++i) // storing element heap array type
        cin>>a[i];

    bool flag_or = true;
    for(i=n-1; i>=0; i--){
        if(flag_or){
            for(j=pow(2,i); j<=pow(2,i+1)-1; ++j)
                a[j] = a[j*2] | a[j*2 + 1];
            flag_or = false;
        }
        else{
            for(j=pow(2,i); j<=pow(2,i+1)-1; ++j)
                a[j] = a[j*2] xor a[j*2 + 1];
            flag_or = true;
        }
    }

    //for(i=1; i<pow(2,n+1); ++i)
    //    cout<<a[i]<<" ";
    while(m--){
        int p,b;
        cin>>p>>b;
        int pos = pow(2,n) + p -1 ;
        //cout<<pos<<endl;
        a[pos] = b;
        //for(i=1; i<pow(2,n+1); ++i)
        //    cout<<a[i]<<" ";
        pos = pos / 2;
        bool flag_or = true;
        while(pos){
            if(flag_or){
                a[pos] = a[pos*2] | a[pos*2 + 1];
                flag_or = false;
            }
            else{
                a[pos] = a[pos*2] xor a[pos*2 + 1];
                flag_or = true;
            }
            pos = pos / 2;
        }
        //for(i=1; i<pow(2,n+1); ++i)
        //    cout<<a[i]<<" ";
        cout<<a[1]<<endl;
    }
    return 0;
}

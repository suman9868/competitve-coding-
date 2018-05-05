/*
this is question of MAY codechef long challenge problem
problem code : XORAGN

submitted by: SUMAN KUMAR (maine hi kiya hai)
date : 5 may 2018 ( aaj ka hi din hai)
time : 7 pm (time to sahi hai)

*/

#include <iostream>
using namespace std;
#define max 100001

int main(){
    long long int t,n,array[max],i,j;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0; i<n; i++)
            cin>>array[i];
        //cout<<(array[3] xor array[2] xor array[0] xor array[1]);
        long long int value=0;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                //if(i==j)
                //    value = value xor (array[i]+array[j]);
                //else{
                    value = value xor (array[i]+array[j]) xor (array[i]+array[j]);
                    //value = value xor (array[i]+array[j]);
                //}
            }
            value = value xor (array[i]+array[i]);
        }
        cout<<value<<endl;        
    }    
    return 0;
}

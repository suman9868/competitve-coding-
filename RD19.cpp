/*
this is a codechef long challenge MAY DIV-2 problem
problem code : RD19

submitted by : SUMAN KUMAR
date : 4 may 2018
time : 11:10 pm

*/

#include <iostream>
#include <algorithm>
using namespace std;
#define size 1001

int main(){
    int t,A[size],i;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(i=0; i<n; i++){
            cin>>A[i];
        }
        sort(A,A+n);
        //for(i=0; i<n; i++)
        //    cout<<A[i]<<" ";
        if(A[0]==1)
            cout<<"0"<<endl;
        else{
            //int count_answer = n;
            int flag=0;
            for(i=1; i<n; i++){
                if(A[i]%A[0]!=0){
                    flag=1;
                    break;
                }
                /*
                else if(A[i]!=0){
                    int temp = A[i];
                    for(j=i+1; j<n; j++){
                        if(A[j]!=0){
                            if(A[j]%temp==0){
                                A[j]=0;
                                count_answer--;
                            }
                        }
                    }
                }
                */

            }
            if(flag==0)
                cout<<"-1"<<endl;
            else
                cout<<"0"<<endl;
        }
    }
    return 0;
}

/*
codechef program easy one 
problem url: 
https://www.codechef.com/problems/LCPESY

done by: SUMAN KUMAR(suman9868)
date: 26 june 2018
time: 5 pm 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string A,B;
        cin>>A>>B;
        vector <int> A_cap(26,0);
        vector <int> B_cap(26,0);
        vector <int> A_small(26,0);
        vector <int> B_small(26,0);
        vector <int> A_digit(10,0);
        vector <int> B_digit(10,0);
        
        for(int i=0; i<A.size(); i++){
            if(A[i]>='a' and A[i]<='z'){
                A_small[A[i]-'a']++;
            } 
            else if(A[i]>='A' and A[i]<='Z'){
                A_cap[A[i]-'A']++;
            }
            else if(A[i]>='0' and A[i]<='9'){
                A_digit[A[i] - '0']++;
            }
        }
        
        for(int i=0; i<B.size(); i++){
            if(B[i]>='a' and B[i]<='z'){
                B_small[B[i]-'a']++;
            } 
            else if(B[i]>='A' and B[i]<='Z'){
                B_cap[B[i]-'A']++;
            }
            else if(B[i]>='0' and B[i]<='9'){
                B_digit[B[i]-'0']++;
            }
        }
        int count = 0;
        for(int i=0; i<26; i++){
            count += min(A_cap[i], B_cap[i]);
            count += min(A_small[i], B_small[i]);
        }
        for(int i=0; i<10; i++){
            count += min(A_digit[i], B_digit[i]);
        }
        cout<<count<<endl;
    }
    return 0;
}

/*

geeksforgeeks problem
problem url:
https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0/?ref=self

done by: SUMAN KUMAR(suman9868)
date : 26 may 2018
time : 1 am
re-modified at : 26 may 2018 , 1pm

*/

#include <iostream>
#include <cstdio> // for printf(), scanf()
#include <algorithm> //for min(), max(), sort(),
#include <vector>
using namespace std;
#define max_size 100001

vector<int> v(max_size,0);
int shortest(int n){

    if(n<=1)
        return 0;
    if(v[n]!=0)
        return v[n];
    if(n%3==0)
        return v[n] = 1+min(shortest(n-1), shortest(n/3));
    return v[n] =  1+shortest(n-1);
    //return v[n];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        v[1] = 0;
        v[2] = 1;
        v[3] = 1;
        int val = shortest(n);
        printf("%d\n",val);
    }
    return 0;
}

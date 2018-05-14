/*
program to print all the subset of given set

algorithm applied: bit-mask
complexicity : O(n2^n) where n is no of element in given set

done by: SUMAN KUMAR(suman9868)
date : 15 may 2018
time : 1 am 

*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//#define push_back() pb()

int main(){
    //int a[] = {1,2,3};
    vector <int> v;// = {1,2,3};
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int size = v.size();
    int total_size = pow(2,size);
    for(int i=0; i<total_size; ++i){
        for(int j=0; j<size; ++j){
            
            if(i & (1<<j))
                cout<<v[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

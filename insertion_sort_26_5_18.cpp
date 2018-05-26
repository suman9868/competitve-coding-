/*

insertion sort with && without recursion

done by: SUMAN KUMAR (suman9868)
date : 26 may 2018
time : 9:15 pm

*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define max_size 1001

// with recursion 
int insertion_recursion(vector <int> &v,int i, int n){

    if(i>n)
        return 1;
    int pos= i-1;   
    int ele = v[i];
    
    while(pos>=0 and v[pos]>ele){
        v[pos+1] = v[pos];
        pos--;
    }    
    if(pos+1 != i)
        v[pos+1] = ele;

    insertion_recursion(v,i+1,n);
}

/*
// without recursion 

void insertion(vector <int> &v, int n){
    
    for(int j=2; j<=n; j++){
        int pos = j-1;
        int ele = v[j];
        
        while(pos>=0 and v[pos]>ele){
            v[pos+1] = v[pos];  
            pos--; 
        }
        if(pos+1 != j){
            v[pos+1] = ele; 
        }
    }
}
*/

void display(vector <int> &v){
    
    printf("\n");
    for(int i=0; i<v.size(); i++)
        printf("%d ",v[i]);
    printf("\n");
}

int main(){
    int a[] = {10,20,61,4,5};
    vector <int> v(a,a+5);
    //insertion(v,4);
    insertion_recursion(v,1,4);    
    display(v);
    return 0;
}

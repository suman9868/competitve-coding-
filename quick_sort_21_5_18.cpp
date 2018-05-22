/*
quick sort implementation

done by: SUMAN KUMAR(suman9868)
date : 21 may 2018
time : 9:15 pm
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int quicksort(vector <int>& a, int start, int end){
    if(start>end)
        return 1;
    int pos = start;

    for(int j=pos+1; j<=end; j++){
        if(a[j]<a[pos]){
            int temp = a[j];
            a[j] = a[pos];
            a[pos] = temp;
            pos++;
        }
    }

    quicksort(a,start,pos-1);
    quicksort(a,pos+1,end);
}
int main(){
    int arr[] = {2,19,5,4,3,14,2};
    vector <int> a(arr,arr+7);
    quicksort(a,0,6);
    for(int i=0; i<7; i++)
        printf("%d ",a[i]);
    //quicksort(a,0,6);
    return 0;
}


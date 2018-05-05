/*
this is a MAY long challenge problem
problem code : MTYFRI

submitted by : SUMAN KUMAR (suman9868 google it)
date : 5 may 2018
time : 8 pm

*/

#include <algorithm>
#include <iostream>
using namespace std;
#define max 10001

int main(){
    int t,array[max],array1[max],array2[max],i,j;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(i=0; i<n; i++)
            cin>>array[i];
        if(n==1)
            cout<<"NO"<<endl;   
        else{
            /*
            if(n%2==0){
                int array1[n/2];
                int array2[n/2];
            }
            else{
                int array1[n/2+1];
                int array2[n/2];
            }
            */
            int size1=0,size2=0;           
            int sum1=0,sum2=0;
            for(i=0; i<n; i++){
                if(i%2==0){
                    array1[size1]=array[i];
                    size1++;
                    sum1=sum1+array[i];
                }
                else{
                    array2[size2]=array[i];
                    size2++;
                    sum2=sum2+array[i];
                }
            }
            sort(array1,array1+size1);
            sort(array2,array2+size2);
            /*
            for(i=0; i<size1; i++)
                cout<<array1[i]<<" ";
            cout<<endl;
            for(i=0; i<size2; i++)
                cout<<array2[i]<<" ";        
            */
            if(k==0){
                if(sum1>=sum2)
                    cout<<"NO"<<endl;
                else
                    cout<<"YES"<<endl;
            }    
            else{
                int flag1= size1-1,flag2=0,k1=k;
                while(flag1>=0 and flag2<size2 and k1!=0 and array1[flag1]>array2[flag2]){
                    int temp = array1[flag1];
                    array1[flag1]=array2[flag2];
                    array2[flag2]=temp;
                    flag1--;
                    flag2++;
                    k1--;                    
                }
                int sum1=0,sum2=0;
                for(i=0; i<size1; i++)
                    sum1=sum1+array1[i];
                for(i=0; i<size2; i++)
                    sum2=sum2+array2[i];
                if(sum1>=sum2)
                    cout<<"NO"<<endl;
                else
                    cout<<"YES"<<endl;
            }           
        }  
    }
    return 0;
}

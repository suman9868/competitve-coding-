/*
NQeens problem related to backtracking and recursion

done by: SUMAN KUMAR(suman9868)
date: 20 june 2018
time : 1 am
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n=5;   // change here for N value, i.e. n*n

vector < vector<int> > Q (n, vector<int> (n, 0));  // storing the N*N values


bool isCollision(int x,int y,int i,int j){  // checking for collision
    for(int k=i; k<=j; k++){
        if(y!=k){
            if(Q[x][k] == 1)
                return true;
        }
    }
    for(int k=i; k<=j; k++){
        if(x!=k){
            if(Q[k][y] == 1)
                return true;
        }
    }
    int k=x-1,l=y-1;
    while(k>=i and l>=i){
        if(Q[k][l] == 1)
            return true;
        k--;
        l--;
    }
    k=x+1; l=y+1;
    while(k<=j and l<=j){
        if(Q[k][l] == 1)
            return true;
        k++; 
        l++;
    }
    k=x+1;l=y-1;
    while(k<=j and l>=i){
        if(Q[k][l] == 1)
            return true;
        k++; 
        l--;
    }    
    k=x-1;l=y+1;
    while(k>=i and l<=j){
        if(Q[k][l] == 1)
            return true;
        k--;
        l++;
    }
    return false;
}

bool NQueens(int i,int j,int row){  // initially i =0 and j=n-1
                                    // row is current row in which queen is placed                
   
    if(row>j)                       // if current row is greater than n-1 (zero based indexing) so just return 
        return true;

    for(int k=i; k<=j; k++){        
        Q[row][k] = 1;
        
        if(isCollision(row,k,i,j)){ // to check for collision
            Q[row][k] = 0;
            continue;
        }
       
       
        if(NQueens(i,j,row+1))
            return true;
       
        Q[row][k] = 0;           // backtrack the value if it is wrong 
    }
    
    return false;
}

int main(){
    
    bool flag= NQueens(0,n-1,0);
    
    // finally printning the NQueens
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<Q[i][j]<<" ";
        cout<<endl;
    }
 
    return 0;
}

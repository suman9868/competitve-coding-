// https://www.spoj.com/problems/BYTESM2/
#include <iostream>
#include <vector>
using namespace std;
int maximum_find(int a,int b,int c){
    if(a>=b and a>=c)
        return a;
    else if(b>=a and b>=c)
        return b;
    else
        return c;
}
int bytes(vector< vector<int> > &matrix,vector< vector<int> > &dp,int h_start,int h_end, int w_start,int w_end,int h_cur, int w_cur){

    if(h_cur<h_start or h_cur>h_end)
        return 0;
    if(w_cur<w_start or w_cur>w_end)
        return 0;
    if(dp[h_cur][w_cur] != -1)
        return dp[h_cur][w_cur];
    // int max_val = 0;
    // for(int j=w_start; j<=w_end; j++){
    //     int val = matrix[h_cur]+;
    // }
    dp[h_cur][w_cur] = (matrix[h_cur][w_cur]) + (maximum_find(bytes(matrix,dp,h_start,h_end,w_start,w_end,h_cur+1,w_cur),bytes(matrix,dp,h_start,h_end,w_start,w_end,h_cur+1,w_cur-1),bytes(matrix,dp,h_start,h_end,w_start,w_end,h_cur+1,w_cur+1)));
    return dp[h_cur][w_cur];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int h,w;
        cin>>h>>w;
        vector< vector<int> > matrix(h, vector<int>(w, 0));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>matrix[i][j];
            }
        }
        vector< vector<int> > dp(h, vector<int>(w, -1));
        int max_val = -1;
        // for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                int val = bytes(matrix, dp, 0,h-1,0,w-1,0,j);
                // cout<<"val:   "<<val<<"  ";
                if(val>max_val)
                    max_val = val;
            }
            // cout<<endl;
        // }
        cout<<max_val<<endl;
        // int val = bytes(matrix, dp, 0,h-1, 0, w-1, 0, 0);
        // cout<<val<<endl;
        // for(int i=0; i<h; i++){
        //     for(int j=0; j<w; j++){
        //         cout<<matrix[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
}

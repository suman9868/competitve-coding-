vector<vector<int> > Solution::subsets(vector<int> &A) {
    int len = A.size();
    
    vector< vector<int> > answer;
    for(int i=0; i< pow(2,len); i++){   // to run loop for all subset 
        vector <int> temp;
        for(int j=0; j<len; j++){    
            if(i & (1<<j)){
                temp.push_back(A[j]);
            }
        }
        sort(temp.begin(), temp.end());   // to sort each subset
        answer.push_back(temp);     // storing each subset in nested vector
      
    }
    sort(answer.begin(), answer.end());   // to sort the superset in ascending order
    return answer;
}

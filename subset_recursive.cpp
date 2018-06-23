/*
InterviewBit question 
problem ur: 
https://www.interviewbit.com/problems/subset/

done by: SUMAN KUMAR(suman9868)
date: 23 june 2018
time: 3:05 pm  

*/
vector < vector<int> > answer;  // to store the all subset 
void subsetPrint(vector<bool> &flag, int start, int end, vector<int> &A){ // called function
    
    if(start == end){
        vector <int> temp;
        for(int i=0; i<end; i++){
            if(flag[i] == true){
                temp.push_back(A[i]);
            }
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp);
        return ;
    }
    flag[start] = true;
    subsetPrint(flag, start+1, end, A);
    flag[start] = false;
    subsetPrint(flag, start+1, end, A);
    return;
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    answer.clear();
    int len = A.size();
    vector <bool> flag(len, false);  // if i th position is true then that value will be in subset print otherwise not
    
    subsetPrint(flag,0,len,A);    // calling function
    sort(answer.begin(), answer.end());   
    return answer;
}

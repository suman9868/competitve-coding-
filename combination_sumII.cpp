/*
interviewBit backtracking problem
problem url: 
https://www.interviewbit.com/problems/combination-sum-ii/

done by: SUMAN KUMAR(suman9868)
date: 23 june 2018
time: 5:36 pm

*/
vector < vector<int> > answer;
void sumFind(int start,int end, int sum, vector<int> &temp, vector<int> &A){
    if(start > end)
        return ;
    if(sum - A[start] == 0){
        temp.push_back(A[start]);
        answer.push_back(temp);
        temp.pop_back();
        return ;
    }
    temp.push_back(A[start]);                 
    sumFind(start+1, end, sum-A[start], temp, A);  // either to include A[start] and move start from start+1
    temp.pop_back();
    sumFind(start+1, end, sum, temp, A);       // don't include A[start] element and start search from start+1 again 
    return ;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
   answer.clear();
   vector <int> temp;
   sort(A.begin(), A.end());
   sumFind(0,A.size()-1,B,temp,A);
   set < vector<int> > s(answer.begin(), answer.end());
   vector < vector<int> >v(s.begin(), s.end());
   return v;
    
}

/*
interviewBit backtracking problem
problem url: 
https://www.interviewbit.com/problems/combination-sum/#

done by: SUMAN KUMAR(suman9868)
date: 23 june 2018
time: 5:18 pm

*/
vector < vector<int> > answer;
void sumFind(int start, int end, vector<int> &A, int sum, vector<int> &temp){
    if(start > end )
        return;
    if(sum - A[start] < 0)
        return ;
    if(sum-A[start] == 0){
        temp.push_back(A[start]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp);
        temp.pop_back();
        return;
    }
    temp.push_back(A[start]);
    sumFind(start, end, A, sum-A[start], temp); // continuing subtrating element till zero or negeive doesn't come
    temp.pop_back();
    sumFind(start+1, end, A, sum, temp);    // either miss the start element and move with next element
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    answer.clear();
    int len = A.size();
    vector <int> temp;
    sort(A.begin(), A.end());
    sumFind(0, len-1, A, B,temp);
    set < vector<int> > s(answer.begin(), answer.end());
    vector < vector<int> > v(s.begin(), s.end());
    sort(v.begin(), v.end());
    return v;
}

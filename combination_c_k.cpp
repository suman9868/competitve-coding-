/*
interviewBit question backtracking question
problem url:
https://www.interviewbit.com/problems/combinations/

done by: SUMAN KUMAR(suman9868)
date: 23 june 2018
time: 4:40 pm

*/
vector < vector<int> > answer;
void combination(vector <bool> &flag, int start, int k_start, int k_end, int end){
    
    if(k_end > end)
        return;
    if(k_start == k_end){
        vector <int> temp;
        for(int i=0; i<end; i++){
            if(flag[i] == true)
                temp.push_back(i+1);
        }
        answer.push_back(temp);
        return;
    }
    flag[k_start] = true;
    combination(flag, start, k_start+1, k_end, end);
    flag[k_start] = false;
    combination(flag, start, k_start+1, k_end+1, end);
    return ;
}
vector<vector<int> > Solution::combine(int A, int B) {
    answer.clear();
    vector <bool> flag(A, false);
    combination(flag,0,0,B,A);
    return answer;
}

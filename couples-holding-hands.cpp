/*

problem url:  https://leetcode.com/problems/couples-holding-hands/ 
user name: suman kumar (suman9868)
date: 18 january 2021
time: 10 PM 
place: dwarka metro staion new delhi 110078

*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
//APPROACH 1
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
		int len = row.size();
		//cout<<row.size()<<endl;
        //for(int i=0; i<row.size(); i++)
		//	cout<<row[i]<<" ";
		map<int, int> m;
		for(int i=0; i<len; i+=2){
			m[i] = i+1;
			m[i+1] = i;
    	}
		//cout<<endl;
		//for(int i=0; i<len; i+=2){
		//	cout<<m[i]<<"  ";	
		//}
		int count = 0;
		for(int i=0; i<len; i+=2){
			int l1 = row[i];
			int l2 = row[i+1];
			if(m[l1] == l2)
				continue;
			else{
				count++;
				for(int j=i+2; j<len; j++){ 
					if(m[l1] == row[j]){
						row[i+1] = row[j];//to make correct pair at i and i+1 position
						row[j] = l2;      // to change the jth position element with the different element at i and i+1 position element
						break;
					}
				}
			}
		}
		return count;        
    }
};
*/

/*
//APPROACH 2
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
		int len = row.size();
		int count = 0;
		for(int i=0; i<len; i+=2){
			int l1 = row[i];
			int l2 = row[i+1];
			if(l1 % 2 == 0 and l1+1 == l2)
				continue;
			else if(l1% 2 != 0 and l1-1 == l2)
				continue;
			else{
				count++;
				int ele = 0;
				if(l1 %2 == 0)
					ele = l1+1;
				else
					ele = l1-1;
				for(int j=i+2; j<len; j++){ 
					if(ele == row[j]){
						row[i+1] = row[j];//to make correct pair at i and i+1 position
						row[j] = l2;      // to change the jth position element with the different element at i and i+1 position element
						break;
					}
				}
			}
		}
		return count;        
    }
};
*/

//APPROACH 3
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
		int len = row.size();
		vector <int> position_row(len, 0);
		for(int i=0; i<len; i++){
			position_row[row[i]] = i;  // row = [5 0 1 2 3 4]  ->   position_row = [1 2 3 4 5 0] 
		}
		//for(int i=0; i<position_row.size(); i++)
		//	cout<<position_row[i]<<" ";
		//cout<<endl;
		int count = 0;
		for(int i=0; i<len; i+=2){
			int l1 = row[i];
			int l2 = row[i+1];
			if(l1 % 2 == 0 and l1+1 == l2)
				continue;
			else if(l1% 2 != 0 and l1-1 == l2)
				continue;
			else{
				count++;
				int ele = 0;
				if(l1 %2 == 0)
					ele = l1+1;
				else
					ele = l1-1;
				//int pos_l2 = position_row[l2];
				int pos_ele = position_row[ele];
				row[i+1] = ele;
				row[pos_ele] = l2;
				
				position_row[ele] = i+1;
				position_row[l2] = pos_ele; 
				//cout<<" pos_l2:  pos_ele:  "<<pos_l2<<"  "<<pos_ele<<endl;  // 1    5
				//int temp = row[pos_l2];
				//row[pos_l2] = ele;
				//row[pos_ele] = temp;
				for(int k=0; k<len; k++)
					cout<<row[k]<<"  ";
				cout<<endl;
			}
		}
		return count;        
    }
};

int main(){
	Solution s;
	vector<int> v;
	//v.push_back(5);	
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	int count = s.minSwapsCouples(v);
	cout<<"count:    "<<count<<endl;
	return 0;
}
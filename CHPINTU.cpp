/*
code written by: Suman Kumar
date: 8 March 2020
time: 1 AM
place: dwarka, new delhi

*/
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>m>>n;
		vector<int> F(m,0); // fruit types: initialise with 0(zero) inititally
		vector<int> P(m,0); // fruit cost:

		for(int i=0; i<m; i++)
			cin>>F[i];
		for(int i=0; i<m; i++)
			cin>>P[i];

		map<int, int> fruit_to_cost_map;

		for(int i=0; i<m; i++){
			fruit_to_cost_map[F[i]] = 0;
		}


		for(int i=0; i<m; i++){
			// if(fruit_to_cost_map.find(F[i])==fruit_to_cost_map.end())
			// 	fruit_to_cost_map[F[i]] = P[i];
			// else
			fruit_to_cost_map[F[i]] += P[i];
		}

		map<int,int>::iterator itr;
		int min_value = 999999;

		// for(itr=fruit_to_cost_map.begin(); itr!=fruit_to_cost_map.end(); ++itr){
		// 	cout<<itr->first<<"  :  "<<itr->second<<endl;
		// }
		// cout<<endl<<endl;

		for(itr=fruit_to_cost_map.begin(); itr!=fruit_to_cost_map.end(); ++itr){
			if(itr->second < min_value)
				min_value = itr->second;
		}

		cout<<min_value<<endl;
    }
	return 0;
}
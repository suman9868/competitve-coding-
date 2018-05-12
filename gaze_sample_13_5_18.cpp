/*
this is a simple program to check recusion function

.....
.S**.
.**..
.**D.
.....

given the above matrix and S source and D destination
we cant walk on * but can walk on .

find whether we can reach S to D return 1(true)
else return 0 (false)
*/
#include <iostream>
using namespace std;
int n;
char s[10][10];
bool gaze(int s1, int s2){
    //s[s1][s2] = '*';
    if(s[s1][s2]=='D') return true;

    if(s[s1][s2]=='*') return false;

    if(s1>n-1 or s1<0 or s2>n-1 or s2<0) return false;

    s[s1][s2] = '*';

    if(gaze(s1+1,s2)) return true;
    if(gaze(s1-1,s2)) return true;
    if(gaze(s1,s2+1)) return true;
    if(gaze(s1,s2-1)) return true;

    return false;

}

int main(){
    //string s[10][10];
    //int n;
    cin>>n;
    int i,j;
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j)
            cin>>s[i][j];
    }
    /*
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    */
    cout<<gaze(1,2);   // just give the location of S
    // return 1 if path exist orthewise 0
    return 0;
}

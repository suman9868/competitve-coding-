/*
    
    codeforces problems : Two Substrings
    problem code : 550A

    submitted by: Suman Kumar
    date : 12 december 2017 
    time : 10:30 pm
*/
#include <iostream>
using namespace std;

int main()
{
    string s;   
    cin>>s;
    int len = s.length();
    //cout<<len<<endl;
    int temp[len],i;
    temp[0] = 0;
    int count_one = 0;
    int flag_ab=0,flag_ba=0;    
    for(i=1; i<len; i++)
    {
        if(s[i]=='A' && s[i-1]=='B')
        {
            temp[i] = 1;
            flag_ba=1;
            count_one++;
        }
        else if(s[i]=='B' && s[i-1]=='A')
        {
            temp[i] = 1;
            flag_ab=1;
            count_one++;
        }
        else
            temp[i]=0;   
    }
    if(flag_ab==1 && flag_ba==1)
    {
    //if(count_one<2)
      //  cout<<"NO";
        if(count_one>3)
            cout<<"YES";
        else if(count_one==2)
        {
            //cout<<count_one;
            int flag=0;
            for(i=1; i<len; i++)
            {
                if(temp[i]==1 && temp[i-1]==1)
                {
                    flag=1;
                    break;    
                }
            }
            if(flag==1)
                cout<<"NO";
            else
                cout<<"YES";
        }
        else if(count_one==3)
        {
            //cout<<count_one;
            int flag=0;
            for(i=2; i<len; i++)
            {
                if(temp[i]==1 && temp[i-1]==1 && temp[i-2]==1)
                {
                    flag=1;
                    break;    
                }
            }
            if(flag==1)
                cout<<"NO";
            else
                cout<<"YES";
        }
    }
    else
        cout<<"NO";
    return 0;
}

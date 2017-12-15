/*
    spoj problem : seinfeld
    dynamic programming problem
        
    done by : Suman Kumar
    date : 15 december 2017
    time : 7 pm

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> stack;
    string str;
    cin>>str;
    int number = 1,i;
    while(str[0]!='-')
    {
        stack.push_back(str[0]);
        for(i=1; str[i]!='\0'; i++)
        {
            if(str[i]=='{')
                stack.push_back(str[i]);
            else
            {
                if(stack.back() == '{')
                    stack.pop_back();
                else
                    stack.push_back(str[i]);
            }
        }
        //cout<<number<<". "<<stack.size()<<endl;
        int count=0;
        for(i=1; i<stack.size(); i++)
        {
            //cout<<stack[i]<<" ";
            if(stack[i-1] == '}' && stack[i] == '}')
                count++;
            else if(stack[i-1] == '{' && stack[i] == '{')
                count++;
            else if(stack[i-1] == '}' && stack[i] == '{')
                count=count+2;
            i++;
        }
        //len = (count*2)+(len-(count)
        cout<<number<<". "<<count<<endl;
        number++;
        stack.clear();
        cin>>str;
    }
    
    return 0;
}

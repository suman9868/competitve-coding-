//similar dishes
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c,d;
		cin>>a>>b>>c>>d;
		int i,count=0;
		string e;
		for(i=1; i<=4; i++)
		{
			cin>>e;
			if(e == a)
			    count++;
			else if(e == b)
			    count++;
			else if(e == c)
			    count++;
			else if(e == d)
			    count++;
		}
		if(count >= 2)
		    cout<<"similar"<<endl;
		else 
		    cout<<"dissimilar"<<endl;
	}
	return 0;
}

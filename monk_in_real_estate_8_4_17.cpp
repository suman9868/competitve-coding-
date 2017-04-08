//monk in the real estate     
#include<iostream> 
using namespace std; 
#define max 10001    

int main()
{
	long long int a[max] = {0};
	int i;
	
	int t;
	cin>>t;
	while(t--)
	{
		for(i=1; i<=max-1; i++)
	        a[i]=0;
		
		int e;
		cin>>e;
		int x,y;
		for(i=1; i<=e; i++)
		{
		    cin>>x>>y;
		    a[x] = 1;
		    a[y] = 1;
	    }
		
		int count = 0;
		for(i=1; i<=max-1; i++)
		    if(a[i] == 1)
		        count++;
		cout<<count<<endl;
	}
	return 0;
}

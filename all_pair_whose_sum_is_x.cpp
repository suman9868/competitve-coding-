//find all pairs with a given sum
#include<iostream>
#include<algorithm>

using namespace std;
#define max 1001

int main()
{
	int t,a[max],b[max],i,j;
	cin>>t;
	while(t--)
	{
		int n,m,x;
		cin>>n>>m>>x;
		for(i=0; i<n; i++)
		    cin>>a[i];
		for(i=0; i<m; i++)
		    cin>>b[i];
		sort(a,a+n);
		sort(b,b+m);
		/*
        for(i=0; i<n; i++)
		    cout<<a[i]<<"  ";
		cout<<endl;
		for(i=0; i<m; i++)
		    cout<<b[i]<<"  ";
        
		*/
		int flag = 0, index=0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if((a[i]+b[j]) == x)
				{
					if(index == 1)
					    cout<<", ";
					flag = 1;
					//if(a[i] > b[j])
					    cout<<a[i]<<" "<<b[j];
					//else
					   // cout<<b[j]<<" "<<a[i];
					
					//if(i != n-1)
        			//    cout<<", ";
                    index = 1;
				}
				else if((a[i]+b[j]) > x)
				    break;
			}
		}
		
		if(flag == 0)
		    cout<<"-1";
		cout<<endl;
	}
	return 0;
}

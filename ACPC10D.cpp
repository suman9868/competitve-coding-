/*
spoj dynamic programming problems

submitted by : Suman Kumar
date : 14 january 2018
time : 10 pm

*/
#include <iostream>
using namespace std;
#define max 100002
int a[max],b[max],c[max];
int min(int a,int b)
{
	if(a<=b)
		return a;
	else 
		return b;
}
int min(int a,int b,int c)
{
	if(a<=b && a<=c)
		return a;
	else if(b<=a && b<=c)
		return b;
	else 
		return c;
}/*
int call(int start,int end,int pos,int pre)
{
	if(start>end)
		return 0;
	if(start==1)
		return min(b[start]+call(start+1,end,1,2), b[start]+c[start]+call(start+1,end,2,3));
	if(start==end && (pre==1 || pre==2))
		return min(a[start], a[start]+b[start]);
	if(start==end && pre==3)
		return b[start];
	if(pos==1)
		return min(a[start]+call(start+1,end,1,1), a[start]+b[start]+call(start+1,end,1,2), a[start]+b[start]+c[start]+call(start+1,end,2,3));
	if(pos==2)
		return min(b[start]+call(start+1,end,1,2), b[start]+c[start]+call(start+1,end,2,3));
	//if()
	//return min(a[start],b[start],c[start])+call(start+1,end);
}
*/
int call(int start,int end,int pre)
{
	if(start>end)
		return 0;
	if(start==1)
		return min(b[start]+call(start+1,end,2), b[start]+c[start]+call(start+1,end,3));
	if(start==end && (pre==1 || pre==2))
		return min(a[start], a[start]+b[start]);
	if(start==end && pre==3)
		return b[start];
	if(pre==1 || pre==2)
		return min(a[start]+call(start+1,end,1), a[start]+b[start]+call(start+1,end,2), a[start]+b[start]+c[start]+call(start+1,end,3));
	if(pre==3)
		return min(b[start]+call(start+1,end,2), b[start]+c[start]+call(start+1,end,3));
	//if()
	//return min(a[start],b[start],c[start])+call(start+1,end);
}
int main()
{
	int n,k=1,i;
	cin>>n;
	while(n)
	{
		//int t=n;
		for(i=1; i<=n; i++)	
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		//int val=b[1]+call(2,n-1,2)+b[n];
		int val = call(1,n,0);
		cout<<k<<". "<<val<<endl;
		k++;
		cin>>n;
	}
	return 0;
}
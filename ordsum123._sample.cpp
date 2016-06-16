//ordsum23 problem partial checking 
//sample checking whether it is working or not 

//this will work only for n%2==0 and n<=45 
                                        //so need to improve more on this 
include<iostream>
using namespace std;
long long int fact(long long int n)
{
	if(n==0)
	    return 1;
	if(n!=1)
	    return n*fact(n-1);
}
int main()
{
	long long int n;
	cin>>n;
	long long int no_of_two=n/2;
	if(no_of_two<=2)
	    cout<<"1"<<endl;
	else
	{
		long long int total=0;
		long long int no_of_three=0;
		while(no_of_two>=0)
		{
			total+=(fact(no_of_two+no_of_three)/(fact(no_of_two)*fact(no_of_three)));
			no_of_two-=3;
			no_of_three+=2;
		}
		cout<<total<<endl;
	}
	
	return 0;
}

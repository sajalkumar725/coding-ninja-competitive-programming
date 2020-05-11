/*
find (a^b)%c where a and b can be very large
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod_exp(int a,int b,int c)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	long ans;
	if(b%2==0)
	{
		long small_ans=mod_exp(a,b/2,c);
		ans=(small_ans*small_ans)%c;
	}
	else
	{
		long small_ans=mod_exp(a,b-1,c);
		ans=a%c;
		ans=(ans*small_ans)%c;
	}
	return ans;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<mod_exp(a,b,c)<<endl;
}

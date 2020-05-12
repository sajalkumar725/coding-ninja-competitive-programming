#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod_exp(int a,int b,int c)
{
	int ans=1;
	while(b>0)
	{
		int right_most=(b&1);
		if(right_most==1)
		{
			ans=(ans*a)%c;
		}
		a=(a*a)%c;
		b=b/2;
	}
	return (ans+c)%c;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<mod_exp(a,b,c)<<endl;
}

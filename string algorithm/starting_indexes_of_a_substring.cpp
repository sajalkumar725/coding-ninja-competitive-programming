/*
print all the starting indexes of a given sub string in a string
input: 
2(test cases)
abcabcabcabc
abc
aaabbbcccddd
abbbc
output:
0 3 6 9
2
*/
#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
vector<int> findString(string s,string t)
{
	vector<int> result;
	int n=s.length();
	int m=t.length();
	int i=0,j=0;
	int index;
	while(i!=n)
	{
		if(s[i]==t[j])
		{
			/*if(j==0)
			{
				index=i;
				result.eb(index);
			}*/
			i++;
			j++;
			if(j==m)
			{
				result.eb(i-m);
				j=0;
			}
		}
		else if(s[i]!=t[j])
		{
			i++;
			j=0;
		}
	}
	if(result.empty())
	{
		result.eb(-1);
	}
	return result;
}

#define eb emplace_back
int main() {
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
    	string t;
    	getline(cin>>ws,s);
    	getline(cin>>ws,t);
    	vector<int> ans=findString(s,t);
    	for(auto it=ans.begin();it!=ans.end();it++)
    	{
    		cout<<(*it)<<" ";
		}
		cout<<endl;
	}
}

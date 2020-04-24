/*
print length of the largest palindromic substring

input: abbabbaabcd
output: 7
*/
#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

int largest_palindromic_substring(string s)
{
	int max_length=INT_MIN;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		//odd length
		int left=i;
		int right=i;
		while(left>=0 && right<n && s[left]==s[right])
		{
			int curr_length=right-left+1;
			max_length=max(curr_length,max_length);
			left--;
			right++;
		}
		//even length
		left=i;
		right=i+1;
		while(left>=0 && right<n && s[left]==s[right])
		{
			int curr_length=right-left+1;
			max_length=max(curr_length,max_length);
			left--;
			right++;
		}
	}
	return max_length;
}

int main()
{
	string s;
	getline(cin>>ws,s);
	cout<<largest_palindromic_substring(s)<<endl;
}

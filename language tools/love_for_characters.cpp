/*
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,count_a=0,count_s=0,count_p=0;
    cin>>n;
    fflush(stdin);
    char s[n];
    /*fflush(stdin);
    string s;
    getline(cin,s);
    //std::string::iterator it;
    for(auto it=s.begin();it!=s.end();it++)
    {
        if(*it=='a')
            count_a++;
        else if(*it=='s')
            count_s++;
        else if(*it=='p')
            count_p++;
        else
            continue;
    }*/
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
            count_a++;
        else if(s[i]=='s')
            count_s++;
        else if(s[i]=='p')
            count_p++;
        else
            continue;
    }
    cout<<count_a<<" "<<count_s<<" "<<count_p;
	return 0;
}

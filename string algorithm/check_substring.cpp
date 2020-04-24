/*
check if the given string is the substring of other string or not
*/
#include <iostream>
using namespace std;

#include<bits/stdc++.h>
bool findString(string s, string t)
{
    int n=s.length();
    int m=t.length();
    int i=0,j=0;
    int index=-1;
    while(i!=n && j!=m)
    {
        if(s[i]==t[j])
        {
            if(j==0)
            {
                index=i;
            }
            i++;
            j++;
        }
        else if(s[i]!=t[j])
        {
            i++;
            j=0;
        }
    }
    if(j==m)
{
return true;
}
    else if(i==n)
    {
    return false;
}
    /*if(i==n)
    {
        return -1;
    }
    else if(j==m)
    {
        return index;
    }*/
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
      string s;
      string t;
      getline(cin>>ws,s);
      getline(cin>>ws,t);
      bool ans=findString(s,t);
      if(ans)
      {
        cout<<"ans= YES"<<endl;
      }
      else
      {
        cout<<"ans= NO"<<endl;
      }
    }
}

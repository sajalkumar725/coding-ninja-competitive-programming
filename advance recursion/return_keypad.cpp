/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <string>
using namespace std;
#include<bits/stdc++.h>
int keypad(int num, string output[]){
    string alp[11]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    else
    {
        int quo=num/10;
        int rem=num%10;
        int smallOutput=keypad(quo,output);  
        string str=alp[rem];
        for(int j=0;j<smallOutput;j++)
        {
            string temp=output[j];
            for(int i=0;i<str.size();i++)
            {
                output[i*smallOutput+j]=temp+str[i];
            }
        }
        return smallOutput*alp[rem].size();
    }
}

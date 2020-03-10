/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba
*/

#include<bits/stdc++.h>
void removeConsecutiveDuplicates(char *input) {
    if(strlen(input)==1)
        return;
    if(input[0]!=input[1])
        removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1])
    {
        int i;
        for(i=1;input[i]!='\0';i++)
            input[i-1]=input[i];
        input[i-1]=input[i];
        removeConsecutiveDuplicates(input);
    }
}

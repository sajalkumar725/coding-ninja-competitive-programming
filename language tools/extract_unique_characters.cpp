/*
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
1 <= Length of S <= 50000
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include<bits/stdc++.h>
using namespace std;
char* uniqueChar(char *str){
    int count = 0;
int i = 0;
while(str[i] != '\0'){
count++;
i++;
}
    map<char , int>m;
    char arr[count];
    int j =0;
    //cout << "n";
    for(i = 0 ; i < count ; i++){
        if(m[str[i]] == 0){
            arr[j++] = str[i];
            m[str[i]] = 1;
        }
    }
    for(int k = 0 ; k < j ; k++){
        cout << arr[k];
    }
    return arr;
}

/*
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
true or false
Constraints :
1 <= N <= 10^3
Sample Input :
3
9 8 10
8
Sample Output :
true
*/


bool checkNumber(int *input,int n, int x)
{
	if(n==0)
		return false;
	else
	{
		if(input[0]==x)
			return true;
		return(checkNumber(input+1,n-1,x));
	}
}

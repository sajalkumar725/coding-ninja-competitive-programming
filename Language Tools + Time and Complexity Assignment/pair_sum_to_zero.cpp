/*
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
1 <= N <= 10^6
Ai contains all non-zero values
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2
*/

#include<bits/stdc++.h>
	void PairSum(int *input, int n) 
    {
        map<int,int> m;
        map<int,int>::iterator it;
        map<int,int>::iterator itp;
        for(int i=0;i<n;i++)
        {
            m[input[i]]++;
        }
        for(it=m.begin();it!=m.end();it++)
        {
            if((it->first)>0)
            {
                itp=m.find(-(it->first));
                if(itp!=m.end())
                {
                	int l=((it->second)*(itp->second));
                    while(l--)
                    {
                        cout<<itp->first<<" "<<it->first<<endl;
                    }
                    it->second=0;
                    itp->second=0;
                }
            }
        }
 	}

/*
You are given an integer N. 
You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left)
*/

int returnFirstSetBit(int n)
{
    for(int i=0;i<n;i++)
    {
        if(n&(1<<i))
            return 1<<i;
    }
    return 0;
}


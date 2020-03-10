/*
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
*/

int turnOffFirstSetBit(int n)
{
    /*int i;
    for(i=0;i<n;i++)
    {
        if(n&(1<<i)!=0)
        {
            return n^(1<<i);
        }
    }
    return 0;*/
    
    return n^(n&(-n));
}


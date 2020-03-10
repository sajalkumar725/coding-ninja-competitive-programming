/*
You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
*/

int turnOffIthBit(int n, int i)
{
    int x=(n&(~(1<<i)));
    return x;
}


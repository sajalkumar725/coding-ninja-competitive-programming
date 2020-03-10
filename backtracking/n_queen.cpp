/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

int arr[11][11]={0};
bool is_safe(int n,int row,int col)
{
    int i=row-1,j=col+1;
    while(i>=0 && j<n)
    {
        if(arr[i][j]==1)
            return false;
        i--;
        j++;
    }
    i=row-1;
    j=col-1;
    while(i>=0 && j>=0)
    {
        if(arr[i][j]==1)
            return false;
        i--;
        j--;
    }
    for(i=row-1;i>=0;i--)
    {
        if(arr[i][col]==1)
            return false;
    }
    return true;
}
void helper(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
        cout<<endl;
        return;
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            if(is_safe(n,row,j))
            {
                arr[row][j]=1;
                helper(n,row+1);
                arr[row][j]=0;
            }
        }
        return;
    }
    return;
}
void placeNQueens(int n){
    helper(n,0);
}

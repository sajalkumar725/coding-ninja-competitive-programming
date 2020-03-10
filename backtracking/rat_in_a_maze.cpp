/*
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible
*/

#include<bits/stdc++.h>
int solution[20][20];

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}

void rat_helper(int maze[][20],int n,int row,int col)
{
    if(row==n-1 && col==n-1)
    {
        solution[row][col]=1;
        print(n);
        return;
    }
    if(row>=n || row<0 || col>=n || col<0 || solution[row][col]==1 || maze[row][col]==0 )
        return;
    solution[row][col]=1;
    rat_helper(maze,n,row-1,col);
    rat_helper(maze,n,row+1,col);
    rat_helper(maze,n,row,col-1);
    rat_helper(maze,n,row,col+1);
    solution[row][col]=0;
}

void ratInAMaze(int maze[][20], int n){
    rat_helper(maze,n,0,0);
}

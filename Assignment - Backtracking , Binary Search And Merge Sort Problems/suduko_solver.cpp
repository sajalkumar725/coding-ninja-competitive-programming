/*
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

#include<bits/stdc++.h>
int n=9;

bool is_empty_blank(int grid[][9],int &row,int &col)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]==0)
			{
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

bool is_col_safe(int grid[][9],int col,int num)
{
	for(int i=0;i<n;i++)
	{
		if(grid[i][col]==num)
			return false;
	}
	return true;
}

bool is_grid_safe(int grid[][9],int row,int col,int num)
{
	int row_factor=row-(row%3);
	int col_factor=col-(col%3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i+row_factor][j+col_factor]==num)
				return false;
		}
	}
	return true;
}

bool is_row_safe(int grid[][9],int row,int num)
{
	for(int i=0;i<n;i++)
	{
		if(grid[row][i]==num)
			return false;
	}
	return true;
}

bool is_safe(int grid[][9],int row,int col,int num)
{
	if(is_row_safe(grid,row,num) && is_col_safe(grid,col,num) && is_grid_safe(grid,row,col,num))
		return true;
	else
		return false;
}

bool sudokuSolver(int grid[][9])
{
    int row,col;
	if(!(is_empty_blank(grid,row,col)))
	{
		return true;
	}
	for(int i=1;i<=n;i++)
	{
		if(is_safe(grid,row,col,i))
		{
			grid[row][col]=i;
			if(sudokuSolver(grid))
				return true;
			grid[row][col]=0;
		}
	}
	return false;
}

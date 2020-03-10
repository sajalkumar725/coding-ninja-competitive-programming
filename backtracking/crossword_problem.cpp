/*
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include<bits/stdc++.h>
using namespace std;
#define n 10
#define f(i,n) for(i=0;i<n;i++)
#define f(j,n) for(j=0;j<n;j++)

void reset_vertical(char cross[10][10],int row,int col,string s)
{
	int counter=0;
	for(int i=row;counter!=s.size();i++)
	{
		cross[i][col]='-';
		counter++;
	}
}

void reset_horizontal(char cross[10][10],int row,int col,string s)
{
	int counter=0;
	for(int i=col;counter!=s.size();i++)
	{
		cross[row][i]='-';
		counter++;
	}
}

bool valid_vertical(char cross[10][10],string name,int row,int col)
{
	int i,counter=0;
	int len=name.size();
	for(int i=row;counter!=len;i++)
	{
		if(cross[i][col]=='-' || cross[i][col]==name[counter])
		{
			counter++;
			continue;
		}
		else
			return false;
	}
	return true;
}

bool valid_horizontal(char cross[10][10],string name,int row,int col)
{
	int i,counter=0;
	int len=name.size();
	for(int i=col;counter!=len;i++)
	{
		if(cross[row][i]=='-' || cross[row][i]==name[counter])
		{
			counter++;
			continue;
		}
		else
			return false;
	}
	return true;
}

void set_vertical(char cross[10][10],string s,int row,int col,bool helper[])
{
	for(int i=0;i<s.size();i++)
	{
		if(cross[row][col]=='-')
		{
			cross[row][col]=s[i];
			helper[i]=true;
		}
		else
		{
			helper[i]=false;
		}
		row++;
	}
}

void set_horizontal(char cross[10][10],string s,int row,int col,bool helper[])
{
	for(int i=0;i<s.size();i++)
	{
		if(cross[row][col]=='-')
		{
			cross[row][col]=s[i];
			helper[i]=true;
		}
		else
		{
			helper[i]=false;
		}
		col++;
	}
}

bool fill_crossword(char cross[10][10],string words[],int st_index,int end_index)
{
	if(st_index==end_index)
		return true;
	int i,j;
	bool helper[50];
	f(i,n)
	{
		f(j,n)
		{
			if(cross[i][j]=='-' || cross[i][j]==words[st_index][0])
			{
				if(valid_vertical(cross,words[st_index],i,j))
				{
					set_vertical(cross,words[st_index],i,j,helper);
					if(fill_crossword(cross,words,st_index+1,end_index))
						return true;
					reset_vertical(cross,i,j,words[st_index]);
				}
				if(valid_horizontal(cross,words[st_index],i,j))
				{
					set_horizontal(cross,words[st_index],i,j,helper);
					if(fill_crossword(cross,words,st_index+1,end_index))
						return true;
					reset_horizontal(cross,i,j,words[st_index]);
				}
			}
		}
	}
}

int main()
{
	int i,j;
	char cross[10][10];
	string words[10];
	string s;
	f(i,n)
	{
		f(j,n)
		{
			cin>>cross[i][j];
		}
	}
	cin>>s;
	int k=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==';')
		{
			k++;
			i++;
		}
		words[k]=words[k]+s[i];
	}
	bool x=fill_crossword(cross,words,0,k+1);
	f(i,n)
	{
		f(j,n)
		{
			cout<<cross[i][j];
		}
		cout<<endl;
	}
}

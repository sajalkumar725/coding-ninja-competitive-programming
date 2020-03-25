/*
A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format
String s
Array of length of string
Output Format
Area
Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Sample Test Case
"NWWSE"
{10,3,7,10,10}
Returns: 100


"NESWNWSW"
{20,200,30,100,20,30,10,70}
Returns: 4700
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct points
{
    double x,y;
}points;

int area2(points p[],int n)
{
    double sum=0,cross;
    for(int i=1;i<n-1;i++)
    {
        double X1=p[i].x-p[0].x;
        double Y1=p[i].y-p[0].y;
        double X2=p[i+1].x-p[0].x;
        double Y2=p[i+1].y-p[0].y;
        cross=X1*Y2-X2*Y1;
        sum+=cross;
    }
    int ans=(int)sum;
    return abs(ans/2);
}



int area(int *arr,string s,int n)
{
    points p[n+1];
    p[0].x=0;
    p[0].y=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='N')
        {
            p[k+1].y=p[k].y+arr[i];
            p[k+1].x=p[k].x;
        }
        else if(s[i]=='S')
        {
            p[k+1].y=p[k].y-arr[i];
            p[k+1].x=p[k].x;
        }
        else if(s[i]=='E')
        {
            p[k+1].x=p[k].x+arr[i];
            p[k+1].y=p[k].y;
        }
        else
        {
            p[k+1].x=p[k].x-arr[i];
            p[k+1].y=p[k].y;
        }
        k++;
    }
    /*for(int i=0;i<n+1;i++)
    {
    	cout<<p[i].x<<" "<<p[i].y<<endl;
	}*/
	cout<<area2(p,n+1)<<endl;
}

int main() 
{
    string s;
    cin>>s;
    int n=s.length();
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    area(arr,s,n);
}

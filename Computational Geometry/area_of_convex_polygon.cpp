/*
A convex polygon is a set of n vertices that are joined by n edges, such that no two edges intersect and all angles are less than 180 degrees. We can represent a polygon by listing all the vertices, starting at one vertex and following the edges until that vertex is reached again. Thus, element 0 in the array represents the first vertex. The first vertex is connected to the second vertex (element 1), the second vertex is connected to the third vertex (element 2) and so on. The last element represents the last vertex, which is connected to the first vertex.
Given the vertices of a polygon, where the x-coordinate of vertex i is element i of int[] x and its y-coordinate is element i of int[] y, return its exact area.
Input Format
 Integer N
 Two arrays x and y of size N
Output Format
Area of polygon
Notes
Get the integer part of the area. (It can be long)
So get your answer in double, and typecast it into long.
Constraints
x and y will have the same number of elements.
x will have between 3 and 50 elements inclusive.
y will have between 3 and 50 elements inclusive.
each element in x will be between -10000 and 10000 inclusive.
each element in y will be between -10000 and 10000 inclusive.
the represented polygon will NOT intersect itself.
the represented polygon will NOT have any angles equal to or greater than 180 degrees.
Sample Input
3
0 0 1
0 1 0
Sample Output
0
(Exact area was 0.5 . In Integer It is 0)
*/


#include<bits/stdc++.h>
using namespace std;

typedef struct points
{
    double x,y;
}points;

int area(points p[],int n)
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

int main()
{
    int n;
    cin>>n;
    points p[n];
    for(int i=0;i<n;i++)
        cin>>p[i].x;
    for(int i=0;i<n;i++)
        cin>>p[i].y;
    cout<<area(p,n)<<endl;
}

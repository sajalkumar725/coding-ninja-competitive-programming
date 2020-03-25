/*
Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format
Integer N(Number Of points)
Array of X coordinates
Array of Y coordinates
Output Format
X coordinate and Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Testcase
Input
7
2 1 6 5 3 7 9
2 5 1 5 7 6 4
Output
1 5
2 2
6 1
9 4
7 6
3 7
*/

#include<bits/stdc++.h>
using namespace std;
typedef struct points
{
    int x,y;
}points;

bool to_change(points p,points q,points r)
{
    int x1=q.x-p.x;
    int y1=q.y-p.y;
    int x2=r.x-q.x;
    int y2=r.y-q.y;
    int cross=x2*y1-x1*y2;
    if(cross>0)
         return true;
    else
         return false;
}

void convex_hull(points P[],int n)
{
    vector<points> hull;
    int left=0;
    for(int i=1;i<n;i++)
    {
        if(P[i].x<P[left].x)
            left=i;
    }
    int p=left;
    do
    {
        hull.push_back(P[p]);
        int q=(p+1)%n;
        for(int i=0;i<n;i++)
        {
            if(to_change(P[p],P[q],P[i]))
                q=i;
        }
        p=q;
    }while(p!=left);
    
    
    //print answer
    for(int i=0;i<hull.size();i++)
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
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
    convex_hull(p,n);
}

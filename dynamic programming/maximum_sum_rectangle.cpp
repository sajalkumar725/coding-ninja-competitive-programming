/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

// #include <bits/stdc++.h>
// using namespace std;
// int kadane_algo(int* a,int size)
// {
//     int max_so_far = INT_MIN, max_ending_here = 0; 
  
//     for (int i = 0; i < size; i++) 
//     { 
//         max_ending_here = max_ending_here + a[i]; 
//         if (max_so_far < max_ending_here) 
//             max_so_far = max_ending_here; 
  
//         if (max_ending_here < 0) 
//             max_ending_here = 0; 
//     } 
//     return max_so_far; 
// }

// void find_sum_array(int *sum,int i,int j,int **s,int m)
// {
//     int f,b,k=0;
//     for(f=i;f<m;f++)
//     {
//         for(b=0;b<=j;b++)
//         {
//             sum[k]=sum[k]+s[i][j];
//         }
//         k++;
//     }
// }

// int max_rectangle_sum(int **arr,int m,int n)
// {
//     int i,j,ans=INT_MIN;
//     int *sum=new int[m];
//     j=1;
//     for(i=0;i<n;i++)
//     {
//     	for(int l=0;l<m;l++)
//         	sum[l]=0;
//         find_sum_array(sum,i,j,arr,m);
//         j++;
//         int temp=kadane_algo(sum,m);
//         ans=max(ans,temp);
//     }
//     return ans;
// }

// int main()
// {
//     int m,n,i,j;
//     cin>>m>>n;
//     int** arr=new int*[m];
//     for(i=0;i<m;i++)
//         arr[i]=new int[n];
//     for(i=0;i<m;i++)
//         for(j=0;j<n;j++)
//             cin>>arr[i][j];
//     cout<<max_rectangle_sum(arr,m,n);
//     return 0;
// }

// 
#include <bits/stdc++.h>
using namespace std;

int max_array(int *arr,int n,int *start,int *finish)
{
    int max_val = INT8_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_val)
        {
            max_val = arr[i];
            *start = i;
            *finish = i;
        }
    }
    return max_val;
}

int kadanes_algo(int arr[],int *start,int *finish,int n)
{
    bool allNeg = true;

    for(int i = 0; i < n; i++)
        if(arr[i] > 0)
            allNeg = false;

    if(allNeg)
        return max_array(arr,n,start,finish);

    int current_max = 0,best_so_far = 0;
    int start_i = 0;
    for(int i = 0; i < n; i++)
    {
        current_max += arr[i];
        if(best_so_far < current_max)
        {
            best_so_far = current_max;
            *start = start_i;
            *finish = i;
        }
        if(current_max < 0)
        {
            current_max = 0;
            start_i = i+1;
        }
    }
    return best_so_far;
}

int maxSumRectangle(int **rectangle,int n,int m)
{
    int max_sum = INT8_MIN,left,right,top,bottom;
    int temp[n],sum,start = 0,finish = 0;
    int i,j;

    for(i = 0; i < m ; i++)
    {
        memset(temp,0,sizeof(temp));
        
        for(j = i; j < m; j++)
        {
            for(int k = 0; k < n ; k++)
                temp[k] += rectangle[k][j];   //Row Sum For Column(s) 
            
            /****
             * For Col 1,Col 1 + Col 2,Col 1+ Col 2 + Col 3
             *      Find Apt Top and Bottom Using Kadane's algo such that sum is maximum
             *      Taking n^2 combinations of L and R positions
             *      Input
             *      ======
             *      4 5 
             *      1 2 -1 -4 -20 
             *      -8 -3 4 2 1 
             *      3 8 10 1 3 
             *      -4 -1 1 7 -6
             *      Output
             *      =======
             *      for i = 0:
             *         j = 0 --> temp  = {1,-8,3,-4} MaxSum = 3 (2,0) --> (2,0)
             *         j = 1 --> temp  = {3,-11,11,-5} MaxSum = 11 (2,0) --> (2,1)
             *         j = 2 --> temp  = {2,-4,21,-4} MaxSum = 21 (2,0) --> (2,2)
             *         j = 3 --> temp  = {-2,-6,22,3} MaxSum = 25 (2,0) --> (3,3)
             *         j = 4 --> temp  = {-22,-7,6,-10} MaxSum = 6 (2,0) --> (2,4)
             *      for i = 1;
             *         j = 1 --> temp  = {2,-3,8,-1} MaxSum = 8 (2,1) --> (2,1)
             *         j = 2 --> temp  = {1,1,18,0} MaxSum = 20 (0,2) --> (3,2)
             *         j = 3 --> temp  = {-3,3,19,7} MaxSum = 29 (1,1) --> (3,3)    ******ANSWER******
             *         j = 4 --> temp  = {-23,4,22,1} MaxSum = 27 (1,1) --> (3,4)
             * 
             * */
            
            sum = kadanes_algo(temp,&start,&finish,n);

            if(sum > max_sum)
            {
                max_sum = sum;
                left = i;
                right = j;
                top = start;
                bottom = finish;
            }
        }
    }
    // cout<<"TOP: "<<left<<" "<<top<<endl;
    // cout<<"BOTTOM: "<<right<<" "<<bottom<<endl;
    return max_sum;
}

int main()
{
    int m,n;
    cin >> n >> m;
    int **mat = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    cout<<maxSumRectangle(mat,n,m)<<endl;
    return 0;
}

/*
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it.

Input:
  Items as (value, weight) pairs
  arr[] = {{60, 10}, {100, 20}, {120, 30}}
  Knapsack Capacity, W = 50;
Output:
  Maximum possible value = 220
  by taking items of weight 20 and 30 kg 
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution.



In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This problem in which we can break an item is also called the fractional knapsack problem.

Input : 
   Same as above
Output :
   Maximum possible value = 240
   By taking full items of 10 kg, 20 kg and 
   2/3rd of last item of 30 kg
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct items
{
	int weight;
	int value;
}items;

bool compare(items a,items b)
{
	double a1=((double)a.value/a.weight);
	double b1=((double)b.value/b.weight);
	return a1>b1;
}

int knapsack(items *arr,int n,int W)
{
	sort(arr,arr+n,compare);
	int curr_weight=0, curr_value=0;
	for(int i=0;i<n;i++)
	{
		if(curr_weight+arr[i].weight<=W)
		{
			curr_weight+=arr[i].weight;
			curr_value+=arr[i].value;
			//W=W-arr[i].weight;
		}
		else
		{
			int rem=W-curr_weight;
			curr_value+=arr[i].value*((double)rem/arr[i].weight);
			break;
		}
	}
	return curr_value;
}

int main()
{
	int n;
	cout<<"Number of items : ";
	cin>>n;
	int w;
	cout<<"Enter max weight(W) : ";
	cin>>w;
	items *arr=new items[n];
	cout<<"Enter weight ans value of the items : ";
	for(int i=0;i<n;i++)
		cin>>arr[i].weight>>arr[i].value;
	int ans =knapsack(arr,n,w);
	cout<<ans<<endl;
}

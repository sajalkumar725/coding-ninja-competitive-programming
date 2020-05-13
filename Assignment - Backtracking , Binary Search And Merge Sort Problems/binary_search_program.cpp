bool binary_search(int *arr,int val,int start,int end)
{
	if(start>end)
	{
		return false;
	}
	int mid=start+(end-start)/2;
	if(val<arr[mid])
	{
		return binary_search(arr,val,start,mid-1);
	}
	if(val>arr[mid])
	{
		return binary_search(arr,val,mid+1,end);
	}
	return true;
}

/*
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. 
After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. 
She visits the market and starts buying momos (one from each shop) starting from the first shop. 
She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. 
She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.
*/

#include<bits/stdc++.h>
using namespace std;
int binary_search(int r[], int start, int end,int x){
    if(start>end) return end;
    int mid=(start+end)/2;
    if(r[mid-1]<x && x<r[mid]) return mid-1;
    else if(r[mid]<=x && x<r[mid+1]) return mid;
    else if(r[mid]<x) start=mid+1;
    else end=mid-1;
    binary_search(r,start,end,x);
}
int main() {
    int n;
    cin>>n;
    int* r = new int[n];
    for(int i=0;i<n;i++) cin>>r[i];
    int q;
    cin>>q;
    int sum=0;
    for(int i=0;i<n;i++) {
        sum=sum+r[i];
        r[i] = sum;
    }
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        int x1 = binary_search(r,0,n-1,x);
        cout<<x1+1<<" "<<x-r[x1]<<endl;
    }
   
    return 0;
}
//  #include <bits/stdc++.h>

// using namespace std;
// pair<int, int> go(vector<int> sum, int q){
// 	//cout << "q "<<q << '\n';
	
// 	//Getting just greater index
// 	int pos = lower_bound(sum.begin(), sum.end(), q)-sum.begin();
// 	if (pos>sum.size()-1)
// 	{
// 		pos--;
// 	}
// 	if (sum.at(pos) > q)
// 	{
// 		pos--;
// 	}
// 	//cout << "Position "<< pos << '\n';
	
// 	if (pos<0)
// 	{
// 		int momos = 0;
// 		int money_left = q;
// 		return make_pair(momos, money_left);	
// 	}
	

// 	int momos = pos+1;
// 	int money_left = q-sum.at(pos);
// 	return make_pair(momos, money_left);

// }


// int main( int argc , char ** argv )
// {
// 	ios_base::sync_with_stdio(false) ; 
// 	cin.tie(NULL) ; 
	
// 	int n;
// 	cin>>n;

// 	std::vector<int> v;
// 	std::vector<int> sum;
// 	int temp_sum = 0;

// 	while(n--){
// 		int a;
// 		cin>>a;
// 		v.push_back(a);
// 		temp_sum+=a;
// 		sum.push_back(temp_sum);
// 	}

// 	int q;
// 	cin>>q;
// 	while(q--){
// 	int total_money;
// 	cin>>total_money;
	
// 	pair<int, int> ans = make_pair(0,0);
// 	ans = go(sum, total_money);

// 	cout << ans.first<<" "<< ans.second << '\n';
	
// 	}

// 	return 0 ; 



// }

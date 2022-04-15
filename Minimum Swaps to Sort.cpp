// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 

{
    void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
int indexOf(vector<int> &arr, int ele)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int N=nums.size();
	     int ans = 0;
  vector<int>temp = nums;
 
  // Hashmap which stores the
  // indexes of the input array
  map <int, int> h;
 
  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++)
  {
    h[nums[i]] = i;
  }
  for (int i = 0; i < N; i++)
  {
    // This is checking whether
    // the current element is
    // at the right place or not
    if (nums[i] != temp[i])
    {
      ans++;
      int init = nums[i];
 
      // If not, swap this element
      // with the index of the
      // element which should come here
      swap(nums, i, h[temp[i]]);
 
      // Update the indexes in
      // the hashmap accordingly
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

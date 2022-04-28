// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	     int len = nums.size();
  vector<int> lis(len,1);
  vector<int> lds(len,1);
  for(int i=1;i<len;i++){
      for(int j=0;j<i;j++){
           if(nums[j]<nums[i] && lis[i]<=lis[j]){
               lis[i] = lis[j]+1;
           }
      }
  }
  for(int i = len-2;i>=0;i--){
      for(int j = len-1;j>i;j--){
          if(nums[j]<nums[i] && lds[i]<=lds[j] ){
              lds[i] = lds[j]+1;
          }
      }
  }
  //We are subtracting -1 here because the last number in LIS and LDS will be same, and we
  //do not want to count it twice. 5 in this case.
  int maxV = 0;
  for(int i=0;i<len;i++){
      maxV = max(maxV , lis[i]+lds[i]-1);
  }
  return maxV;
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
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

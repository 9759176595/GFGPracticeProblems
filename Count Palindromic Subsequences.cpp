// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
   long long m = 1e9 + 7;
   int dp[1001][1001];
   
   long long int cps(string &s,int i,int j)
   {
       if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j])
       {
         return  dp[i][j] = ( 1 + cps(s,i+1,j) + cps(s,i,j-1))%m;
       }
       else
       {
          return dp[i][j] = (m+ cps(s,i+1,j) + cps(s,i,j-1) - cps(s,i+1,j-1))%m;
       }
      // return dp[i][j]%m;
   }
   
    long long int  countPS(string s)
    {
       //Your code here
      memset(dp,-1,sizeof(dp));
     return cps(s,0,s.size() -1);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends

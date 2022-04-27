// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int dp[1001][1001];
   int help(string& s,int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = 2+help(s,i+1,j-1,dp);
        return dp[i][j] = max(help(s,i+1,j,dp),help(s,i,j-1,dp));
    }
    int longestPalinSubseq(string s) {
       vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return help(s,0,s.length()-1,dp);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends

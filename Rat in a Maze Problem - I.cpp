// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
     void findans(vector<vector<int>> &m,int n, int i,int j, vector<string> &ans,string temp)
    {
        
        
        if(i>n-1 )
        return;
        if(j>n-1)
        return;
        if(j<0)
        return;
        if(i<0)
        return;
        
        if(m[i][j]==0)
        return ;
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(temp);
            return ;
        }
        
        if(m[i][j]==1)
        {
            m[i][j]=0;
        findans(m, n,  i+1,j ,ans, temp+"D");
         findans(m, n,  i,j+1 ,ans, temp+"R");
          findans(m, n,  i-1,j,ans, temp+"U");
           findans(m, n, i,j-1, ans, temp+"L");
             m[i][j] =1;
    }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
        vector<string> ans;
        findans(m,n,0,0,ans,"");
        if(ans.size()==0) return {"-1"};
        return ans;
        
    }
    
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
       if(S < 7)
       {
           if(N < M)
               return -1;
       }
       else
       {
           int total_food = N*6, food_required = M*7;
           if(total_food < food_required)
               return -1;
       }
       
       double one_day_food = (double)N/(double)M;
       double ans = (double)S/one_day_food;
       return ceil(ans);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int A[])
    {
        // code here
        int t[N][N];
      memset( t , 0 , sizeof t );
      
      for( int L = 2 ; L <= N ; L++ )
      for( int i = 1 ; i+L-1<N; i++ )
      {
          int j = i+L-1;
          t[i][j] = INT_MAX ;
          
          for( int k = i ; k < j ; k++ )
          t[i][j] = min( t[i][j] , t[i][k] + t[k+1][j] + A[i-1]*A[k]*A[j] );
      }
      
      return t[1][N-1] ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends

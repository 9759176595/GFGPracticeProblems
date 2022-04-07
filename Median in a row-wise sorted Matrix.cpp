// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &A, int r, int c){
        // code here          
        int low=1,high=1000000000;
        for(int i=0;i<r;i++){
            low=min(low,A[i][0]);
            high=max(high,A[i][c-1]);
        }
        int median =low;
        int  medianPosition=(r*c+1)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0;
            
            //count no of elements <=mid
            for(int i=0;i<r;i++){
                int indx=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
                count+=((indx-1)-0)+1;  //last-first+1
            }
            //if no of elements <=mid value
            if(count<medianPosition){
                low=mid+1;
                median=low;
            }
            else{
                high=mid-1;
            }
        }
        return median;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends

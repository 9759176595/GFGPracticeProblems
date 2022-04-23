// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
   vector<vector<int>>ans;
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());  
        //eliminate duplicates elements
        set<int>s(A.begin(),A.end());
        A.assign(s.begin(),s.end());
        
        vector<int>v;
        func(A,B,v,0);
        return ans; 
        
    }
    void func(vector<int> &A, int B, vector<int>&v,int i){
        if(B==0){
        ans.push_back(v);   //{1,1,1} 
        }
        if(i==A.size()) return;
        while(i<A.size() && B-A[i]>=0){
            if(B-A[i]>=0){  //B=3
                v.push_back(A[i]);  //push 1
                func(A,B-A[i],v,i);    //fun(A,2,{1}) func(A,1,{1,1})  func(A,0,{1,1,1})  noe ans vector me daal do
                i++;
                v.pop_back();   // backtrack
            }
        }
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	string res = "";
    
    void permutation(vector<string>&result,string S,string res){
        if(S.length()==0){
         result.push_back(res);
         return;
     }
     
     for(int i=0;i<S.length();i++){
         char ch = S[i];
         string leftpart = S.substr(0,i);
         string rightpart = S.substr(i+1);
         string val = leftpart+rightpart;
         permutation(result,val,res+ch);
     }
     sort(result.begin(),result.end());
    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    
		     vector<string>result;
           permutation(result,S,res);
           return result;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends

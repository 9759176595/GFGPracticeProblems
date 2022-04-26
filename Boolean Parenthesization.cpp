// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int mcs(string s,int i,int j,bool isTrue)   
    {
    	//base case(smallest valid i/p)
    	if(i>j)
    		return 0;
    	if(i==j)
    	{
    	    if(isTrue)
    	        return s[i]=='T';
    	    else
    	        return s[i]=='F';
    	}
    	
    	//searching table
    	if(dp[i][j][isTrue]!=-1)
    	    return dp[i][j][isTrue]%1003;
    	
        //recursive case
        int res=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int lt,rt,lf,rf;
            
            //calculating lt,rt,lf,rf var
            //left true
            if(dp[i][k-1][1]!=-1)
                lt=dp[i][k-1][1];        
            else
                lt=mcs(s,i,k-1,true);
                
            //left false
            if(dp[i][k-1][0]!=-1)
                lf=dp[i][k-1][0];        
            else
                lf=mcs(s,i,k-1,false); 
                
            //right true
            if(dp[k+1][j][1]!=-1)
                rt=dp[k+1][j][1];        
            else
                rt=mcs(s,k+1,j,true);
                
            //right false
            if(dp[k+1][j][0]!=-1)
                rf=dp[k+1][j][0];
            else
                rf=mcs(s,k+1,j,false);    
        	
        	//calculating ans based on the operator (k)
        	if(s[k]=='&')
        	{
        	    if(isTrue)
    	            res+=(lt*rt);
        	    else
    	            res+=(lt*rf+lf*rt+lf*rf);
        	}
        	else if(s[k]=='|')
        	{
        	    if(isTrue)
    	            res+=(lt*rf+lf*rt+lt*rt);
        	    else
    	            res+=(lf*rf);
        	}
        	else if(s[k]=='^')
        	{
        	    if(isTrue)
    	            res+=(lt*rf+lf*rt);
        	    else
    	            res+=(lt*rt+lf*rf);
        	}
        	dp[i][j][isTrue]=res%1003;
        }
        
        return dp[i][j][isTrue]%1003;
    }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return mcs(S,0,S.length()-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

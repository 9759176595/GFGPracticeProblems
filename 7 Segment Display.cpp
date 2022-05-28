// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string S, int N) {
        // code here
        vector<int>noOfSegments={6,2,5,5,4,5,6,3,7,5};
                               //0,1,2,3,4,5,6,7,8,9
        //S=234567
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=noOfSegments[S[i]-'0'];
        }
        //sum=28
        // 2 2 2 2 2 2  sabko 2 segment de dia
        sum-=2*N;
        vector<int>output(N,2); 
        int i=0;
        while(sum>=4){    //bcz 4 se jaada n hoga to '0' nhi bna skte
            sum-=4;
            output[i++]=6;
        }
        
        // jab last se dekhna pde 
        i=N-1;
        while(i>=0 && sum){
            if(sum>7-output[i]){
                sum-=7-output[i];
                output[i]=7;
                i--;
            }
            else{
                  output[i]+=sum;
            sum=0;
            }
          
        }
        string ans="";
        for(int i=0;i<N;i++){
            switch(output[i]){
                case 2: ans+='1';
                break;
                case 3: ans+='7';
                break;
                case 4: ans+='4';
                break;
                case 5: ans+='2';
                break;
                case 6: ans+='0';
                break;
                case 7: ans+='8';
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends

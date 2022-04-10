// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>colorvector(V,-1);
	    for(int i=0;i<V;i++){
	        if(colorvector[i]==-1){
	            if(checkBipartite(V,adj,i,colorvector)==false)
	               return false;
	        }
	    }
	    return true;
	}
   bool checkBipartite(int V, vector<int>adj[], int src, vector<int>&colorvector){
       queue<int>q;
       q.push(src);
       colorvector[src]=0;  //0 is any color eg. 0 is red and 1 is green
       while(!q.empty()){
           int x=q.front();
           q.pop();
           int color=colorvector[x];
           vector<int>v=adj[x];
           for(int neighbour: v){
               if(colorvector[neighbour]!=-1){  //already coloured
                   if(colorvector[neighbour]==color) return false;
               }
               else{
                   colorvector[neighbour]=(color==0)?1:0;
                   q.push(neighbour);
               }
           }
       }
       return true;
   }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends

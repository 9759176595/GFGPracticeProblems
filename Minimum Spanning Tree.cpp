// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	int findpar(int u,vector<int> &parent)
{
    if(u==parent[u])
    {
        return u;
    }
    return parent[u]=findpar(parent[u],parent);
}
void unite(int u,int v,vector<int> &parent,vector<int> &rank)
{
    u=findpar(u,parent);
    v=findpar(v,parent);
    parent[v]=u;
}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
         int cost=0;
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minh;
       
       vector<int> parent(V);
       vector<int> rank(V);
       for(int i=0;i<V;i++)
       {
           parent[i]=i;
           rank[i]=0;
       }
       for(int i=0;i<V;i++)
       {
           for(auto it:adj[i])
           {
               minh.push({it[1],{i,it[0]}});
           }
       }
       while(!minh.empty())
       {
           int wt=minh.top().first;
           int u=minh.top().second.first;
           int v=minh.top().second.second;
           minh.pop();
           if(findpar(u,parent)!=findpar(v,parent))
           {
               unite(u,v,parent,rank);
               cost+=wt;
           }
       }
       return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

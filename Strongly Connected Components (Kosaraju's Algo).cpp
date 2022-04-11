// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	 stack<int> S;
	bool visited[5000];
	vector<int> reversed_edges[5000];
	void dfs(int u, vector<int> edges[], bool push) {
	    visited[u] = true;
	    for (int& v : edges[u]) {
	        if (visited[v] == false)
	            dfs(v, edges, push);
	    }
	    if (push)
	        S.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> edges[])
    {
        //code here
        int cnt = 0;
        for (int u = 0; u < n; u++) {
            for (int& v : edges[u])
                reversed_edges[v].push_back(u);
        }
        memset(visited, false, sizeof(visited));
        for (int u = 0; u < n; u++) {
            if (visited[u] == false)
                dfs(u, edges, true);
        }
        memset(visited, false, sizeof(visited));
        while (!S.empty()) {
            int u = S.top();
            S.pop();
            if (visited[u] == false) {
                cnt++;
                dfs(u, reversed_edges, false);
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

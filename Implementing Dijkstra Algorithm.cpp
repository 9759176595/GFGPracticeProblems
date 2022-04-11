// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here------(Without using min heap)
        // vector<int> dist(V,INT_MAX);
        // vector<int> fin(V,false);
        // dist[S] = 0;
        // for(int c=0;c<V;c++)
        // {
        //     int u = -1;
        //     for(int i=0;i<V;i++)
        //     {
        //         if( !fin[i] && (u==-1 || dist[i] < dist[u]))
        //         {
        //             u=i;
        //         }
        //     }
            
        //     fin[u] = true ;
            
        //     for(auto it : adj[u]){
        //         int node = it[0];
        //         int d = it[1];
        //         if( !fin[node] && (dist[node] > dist[u] + d))
        //         {
        //             dist[node] = dist[u] + d;
        //         }
        //     }
            
        // }
        // return dist;
        
        //-------. with min heap :
        vector<int> dist(V,INT_MAX);
        vector<int> fin(V,false);
        priority_queue< pair<int,int> , vector<pair<int,int>> , 
                        greater<pair<int,int>> > pq;
                        
        
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            fin[u] = true;
            
            for(auto it : adj[u]){
                int node = it[0];
                int d = it[1];
                if( !fin[node] && (dist[node] > dist[u] + d))
                {
                    dist[node] = dist[u] + d;
                    pq.push({dist[node],node});
                }
            }
            pq.pop();
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends

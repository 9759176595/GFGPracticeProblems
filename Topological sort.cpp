class Solution
{
	public:
	void DFSRec(int s, stack<int>&st,vector<bool>&visited,vector<int>adj[]){
	    visited[s]=true;
	    vector<int>data=adj[s];
	    for(auto v: data){
	        if(!visited[v]){
	            DFSRec(v,st,visited,adj);
	        }
	    }
	    st.push(s);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            DFSRec(i,st,visited,adj);
	        }
	    }
	    vector<int>ans;
	    
	    while(!st.empty()){
	        int x=st.top();
	        st.pop();
	        ans.push_back(x);
	    }
	    return ans;
	}
};

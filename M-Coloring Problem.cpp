// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool issafetoassign(int i,int j, bool graph[101][101],int n,vector<int>&color){
    //cheking is i can assign color j to node i
    //no other neighbour should have the same color
    for(int k=0;k<n;k++){
        if(graph[i][k]==1 && color[k]==j)return false;
    }
    return true;
}
bool func(bool graph[101][101], int m, int n,int i,vector<int>&color){
    if(i==n) return true;
    for(int j=0;j<m;j++){
        if(issafetoassign(i,j,graph,n,color)){
            color[i]=j;
            if(func(graph,m,n,i+1,color)) return true;
            color[i]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int>color(n,-1);
    
    return func(graph,m,n,0,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends

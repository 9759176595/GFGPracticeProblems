// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
unordered_map<int,int>um;
Node* solve(int lvl, int levelOrder[],int inorder[],int iStart, int iEnd){
    if(iStart>iEnd) return NULL;
    Node* root=new Node(levelOrder[lvl]);
    int idx=um[root->key];
    root->left=solve(2*lvl+1,levelOrder,inorder,iStart,idx-1);
    root->right=solve(2*lvl+2,levelOrder,inorder,idx+1,iEnd);
    return root;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
for(int i=0;i<n;i++){
    um[inorder[i]]=i;
}
return solve(0,levelOrder,inorder,iStart,iEnd);
}

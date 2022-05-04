// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/
Node* helper(int post[], int lr, int rr, int n, int& idx)
{
    if(idx<0){
        return NULL;
    }
    if(post[idx]>=lr&&post[idx]<=rr){
        Node* curr = new Node(post[idx]);
        idx--;
        
        curr->right = helper(post,curr->data,rr,n,idx);
        curr->left = helper(post,lr,curr->data,n,idx);
        return curr;
    }
    else
    return NULL;
}
Node *constructTree (int post[], int size)
{
//code here
int idx = size-1;
return helper(post,INT_MIN,INT_MAX,size,idx);
}

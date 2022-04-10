// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node *reverse(struct Node* head){
        struct Node* curr=head, *prev=NULL, *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int length(Node *head){
        int count=0;
        Node *temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
       if(length(first) < length(second)){
            struct Node* temp = first;
            first = second;
            second = temp;
        }
        
        struct Node* f = reverse(first);
        struct Node* f1 = f;
        struct Node* s = reverse(second);
        struct Node* s1 = s;
        struct Node* prev = NULL;
        int carry = 0;
        while(f1 != NULL or s1 != NULL){
            int fd = 0, sd = 0;
            if(f1 == NULL){
                fd = 0;
            }else{
                fd = f1->data;
            }
            
            if(s1 == NULL){
                sd = 0;
            }else{
                sd = s1->data;
            }
            int sum = fd + sd + carry;
            carry = sum/10;
            f1->data = sum%10;
            prev = f1;
            f1 = f1->next;
            if(s1 != NULL){
                s1 = s1->next;
            }
            
        }
        
        if(carry == 1){
            struct Node* new_node = new Node(1);
            prev->next = new_node;
        }
        
        return reverse(f);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends

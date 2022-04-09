// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
int getCount(Node* head)
{
    Node* current = head;
 
    // Counter to store count of nodes
    int count = 0;
 
    // Iterate till NULL
    while (current != NULL) {
 
        // Increase the counter
        count++;
 
        // Move the Node ahead
        current = current->next;
    }
 
    return count;
}
int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;
 
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
 
    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
 
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
 
    return -1;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
      int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
 
    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int lo=0;
        int hi=n-1;
        int mid=0;
        while(mid<=hi){
            switch(a[mid]){
                //if the element id 0
                case 0:
                swap(a[lo++],a[mid++]);
                break;
                //if the elemetn is 1
                case 1:
                 mid++;
                break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
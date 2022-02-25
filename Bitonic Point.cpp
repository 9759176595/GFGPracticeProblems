class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int low=0;
	    int high=n-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        if(mid>0 && mid<n-1){
	            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
	            return arr[mid];
	            else if(arr[mid-1]>arr[mid]){
	                high=mid-1;
	            }else{
	                low=mid+1;
	            }
	        }
	        else if(mid==0){
	            if(arr[0]>arr[1]){
	                return arr[0];
	            }
	            else
	            return arr[1];
	        }
	        else if(mid==n-1){
	            if(arr[n-1]>arr[n-2]){
	                return arr[(n-1)];
	            }else{
	                return arr[(n-2)];
	            }
	        }
	    }
	    return 0;
	}
};

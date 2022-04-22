// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    bool issafe(int row, int col, int i, int grid[N][N]){
       for(int k =0; k<N; ++k) if(grid[row][k]==i || grid[k][col]==i) return false;
       int rs = row - (row%3), cs = col - (col%3);
       for(int k =0; k<3; ++k){
           for(int l =0; l<3; ++l) if(grid[rs+k][cs+l]==i)return false;
       }
       return true;
   }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
          int col =-1, row =-1;
       bool flag = false;
       for(int i =0; i<N; ++i){
           for(int j =0; j<N; ++j){
               if(grid[i][j]==0){
                   row = i;
                   col =j;
                   flag = true;
                   break;
               }
           }
           if(flag) break;
       }
       if(!flag)return true;
       for(int i =1; i<=N; ++i){
           if(issafe(row, col, i, grid)){
               grid[row][col] = i;
               if(SolveSudoku(grid)) return true;
               grid[row][col] =0;
           }
       }
       return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
         for(int i =0; i<N; ++i){
           for(int j =0; j<N; ++j) cout << grid[i][j] << " ";
       }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends

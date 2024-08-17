//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
      if (i<0 ||j<0||i>=grid.size()||j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0)return;
      vis[i][j]=1;
      dfs(i+1,j,vis,grid);
      dfs(i-1,j,vis,grid);
      dfs(i,j+1,vis,grid);
      dfs(i,j-1,vis,grid);
      
      
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m= grid[0].size();
        
       vector<vector<int>>vis(n,vector<int>(m,0));
       for (int i=0;i<m;i++){
           if (grid[0][i]==1 && vis[0][i]==0)dfs(0,i,vis,grid);
           if (grid[n-1][i]==1 && vis[n-1][i]==0)dfs(n-1,i,vis,grid);
       }
       for (int i=0;i<n;i++){
           if (grid[i][0]==1 && vis[i][0]==0)dfs(i,0,vis,grid);
           if (grid[i][m-1]==1 && vis[i][m-1]==0)dfs(i,m-1,vis,grid);
       }
       int cnt=0;
       for (int i=0;i<n;i++){
           for (int j=0;j<m;j++){
               if (vis[i][j]==0 && grid[i][j]==1)cnt++;
           }
       }
    //     for (int i=0;i<n;i++){
    //       for (int j=0;j<m;j++){
    //           cout<<vis[i][j]<<" ";
    //       }
    //       cout<<"\n";
    //   }
       return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
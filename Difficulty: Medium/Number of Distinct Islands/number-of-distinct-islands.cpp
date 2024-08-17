//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
 void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis, vector<pair<int,int>>&p ){
      queue<pair<int,int>>q;
      
      int cnt=0;
      q.push({i,j});
      //cnt++;
      vis[i][j]=1;
      while(!q.empty()){
          int x=q.front().first;
          int y= q.front().second;
          p.push_back(make_pair(x-i,y-j));
          q.pop();
          // neighbour
          for (auto d:dir){
          int x_=x+d[0];
          int y_=y+d[1];
          if (x_>=0 && y_>=0 && x_<grid.size() && y_<grid[0].size() && vis[x_][y_]==0 && grid[x_][y_]==1){
              vis[x_][y_]=1;
             // s.insert({x_-x,y_-y});
              q.push({x_,y_});
          }
      }
          
          
          
      }
     // s.insert(cnt);
      //neighbour
      
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>s;
       vector<vector<int>>vis(n,vector<int>(m,0));
       for (int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if (grid[i][j]==1 && vis[i][j]==0){
                   vector<pair<int,int>>p;
                   bfs(i,j,grid,vis,p);
                   s.insert(p);
                   
               }
           }
       }
       return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
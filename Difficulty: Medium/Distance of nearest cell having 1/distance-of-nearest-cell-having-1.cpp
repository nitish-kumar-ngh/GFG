//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>>ans(n,vector<int>(m,-1));
       queue<pair<pair<int,int>,int>>q;
       for (int i=0;i<n;i++){
           for (int j=0;j<m;j++){
               if (grid[i][j]==0){
                   q.push({{i,j},{0}});
               }else{
                   ans[i][j]=0;
               }
           }
       }
       while (!q.empty()){
           int x=q.front().first.first;
           int y=q.front().first.second;
           int d=q.front().second;
           q.pop();
           if (ans[x][y]==-1){
               queue<pair<pair<int,int>,int>>q1;
                q1.push({{x,y},{d+1}});
                while (!q1.empty()){
                   if ( ans[x][y]!=-1)break;
               int x1=q1.front().first.first;
               int y1=q1.front().first.second;
               int d1=q1.front().second;
               q1.pop();
               for (auto d:dir){
                   int x1_=x1+d[0];
                   int y1_=y1+d[1];
                   if (x1_>=0 && y1_>=0 && x1_<n && y1_<m && ans[x][y]==-1 &&grid[x1_][y1_]==0){
                        q1.push({{x1_,y1_},{d1+1}});
                   }else if(x1_>=0 && y1_>=0 && x1_<n && y1_<m && ans[x][y]==-1 &&grid[x1_][y1_]==1){
                       ans[x][y]=d1;
                   }
               }
           
                }
           }
               
               
           }
       
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
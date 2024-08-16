//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
      
      int n = grid.size();
      int m = grid[0].size();
      int vis[n][m];
      queue<pair<pair<int,int>,int>>q;
      for (int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==2){
                  q.push({{i,j},{0}});
                  vis[i][j]=2;
              }else vis[i][j]=0;
          }
      }
      int tm=0;
      while(!q.empty()){
          int a=q.front().first.first;
          int b= q.front().first.second;
          int t=q.front().second;
          q.pop();
          tm=max(tm,t);
          //neighbour
          for(auto d:dir){
              int a_=a+d[0];
              int b_=b+d[1];
              if (a_>=0 && b_>=0 && a_<n && b_<m && grid[a_][b_]==1 && vis[a_][b_]==0){
                  q.push({{a_,b_},{t+1}});
                  vis[a_][b_]=2;
              }
              
          }
      }
      for (int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if (grid[i][j]==1 && vis[i][j]!=2)return -1;
          }
      }
      return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution { 
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
      vector<int>res(N,INT_MAX);
      unordered_map<int,vector<pair<int,int>>>adj;
      for (auto v:edges){
          adj[v[0]].push_back(make_pair(v[1],v[2]));
      }
      queue<pair<int,int>>q;
      q.push({0,0});
      res[0]=0;
      while(!q.empty()){
          int node=q.front().second;
          int dist=q.front().first;
          q.pop();
          //neighbour
          for (auto v:adj[node]){
              int adjnode=v.first;
              int newdist=v.second;
              if (dist+newdist<res[adjnode]){
                  res[adjnode]=dist+newdist;
                  q.push({dist+newdist,adjnode});
              }
          }
      }
      for (int i=0;i<N;i++){
          if (res[i]==INT_MAX)res[i]=-1;
      }
      return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<pair<int,int>> >adj;
        //graph banao
        for (auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        
        }
        
        vector<int>result(n+1,INT_MAX);
        vector<int>path;
        vector<int>parent(n+1);
        for (int i=0;i<n+1;i++){
            parent[i]=i;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});//dist,node
        result[1]=0;
        while(pq.size()>0){
            auto ele=pq.top();
            pq.pop();
            int node=ele.second;
            int dist=ele.first;
            for (auto v:adj[node]){//neighbour
                 int adjnode=v.first;
                 int adjNodeDist=v.second;
                 if (dist+adjNodeDist<result[adjnode]){
                     pq.push({adjNodeDist+dist,adjnode});
                     result[adjnode]=dist+adjNodeDist;
                     parent[adjnode]=node;
                 }
            }
            
        }
        
        int destNode=n;
        if (result[n]==INT_MAX) return {-1};
        while (parent[destNode]!=destNode){
            path.push_back(destNode);
           destNode= parent[destNode];
        }
        
        path.push_back(1);
         path.push_back(result[n]);
         reverse(path.begin(),path.end());
        
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
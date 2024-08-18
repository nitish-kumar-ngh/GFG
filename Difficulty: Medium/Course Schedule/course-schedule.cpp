//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
          unordered_map<int,vector<int>>adj;
	   for (auto p:prerequisites){
	       adj[p[1]].push_back(p[0]);
	   }
	   //vector<int>adj[m];
	   //for (int i=0;i<m;i++){
	   //    for (auto v:prerequisites){
	   //        adj[v.second].push_back(v.first);
	   //      //  adj[i].push_back(v.first);
	   //    }
	   //}
	    vector<int>indegree(N,0);
	   vector<int>ans;
	   for (int i=0;i<N;i++){
	       for (auto v:adj[i]){
	           indegree[v]++;
	       }
	       
	   }
	   queue<int>q;
	   for (int i=0;i<N;i++){
	       if (indegree[i]==0){
	          q.push(i);
	          ans.push_back(i);
	   }
	   }
	   while (!q.empty()){
	       int a=q.front();
	      //ns.push_back(a);
	       q.pop();
	       for (auto v:adj[a]){
	           indegree[v]--;
	           if (indegree[v]==0){
	             q.push(v);
	             ans.push_back(v);
	       }
	   }
	   }
	   if (ans.size()==N)return ans;
	   else return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
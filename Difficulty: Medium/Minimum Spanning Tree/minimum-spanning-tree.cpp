//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	typedef pair<int,pair<int,int>>P;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //vector<pair<int,int>>mst;
        //mst.push_back({2,4});
        //mst.push_back(make_pair(1,2));
        vector<bool>vis(V,0);
        int s=0;
        priority_queue<P,vector<P>,greater<P>>pq;
      //  int co_node=adj[0][0];//v
       // int wt=adj[0][0][1];
        pq.push({0,{0,-1}});
       // vis[0]=1;
        //  for (auto m:adj[0]){
        //         int adjnod=m[0];
        //         int adjw=m[1];
        //         if (vis[adjnod]==0){
        //             pq.push({adjw,{adjnod,0}});
        //         }
        //     }
        while(pq.size()>0){
            auto k=pq.top();
            pq.pop();
            int wet=k.first;
            int node=k.second.first;
            int parent=k.second.second;
           // if(vis[node]==0 && parent!=-1)mst.push_back(make_pair(node,parent));
            // if (vis[node]==0) {
            // s+=wet;
            // vis[node]=1;
                
            // }
            if (vis[node]==1)continue;
              vis[node]=1;
              s+=wet;
                         
            for (auto m:adj[node]){
                int adjnode=m[0];
                int adjwt=m[1];
                if (vis[adjnode]==0){
                    pq.push({adjwt,{adjnode,node}});
                }
            }
           
        }
        
        return s;
      
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
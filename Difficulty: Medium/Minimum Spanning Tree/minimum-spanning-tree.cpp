//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	typedef pair<int,int>P;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<bool>inMST(V,false);
       priority_queue<P,vector<P>,greater<P> >pq;
       pq.push({0,0});
       int sum=0;
       
       while(!pq.empty()){
           
           auto p=pq.top();
           pq.pop();//(LogE)
           
           int wt=p.first;
           int node=p.second;
           
          if(inMST[node]==true)continue;
             sum+=wt;
             inMST[node]=true;
             for (auto tmp:adj[node]){
                 int wtnode=tmp[1];
                 int dusranode=tmp[0];
                 if (inMST[dusranode]==false){
                     pq.push({wtnode,dusranode});
                 }
                 
             }
           
           
       }
       return sum;
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
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater< pair<int,int >> >pq;//min heap
    vector<int>result(V,INT_MAX);
    pq.push({0,source});
    result[source]=0;
    while (pq.size()>0){
        auto ele=pq.top();
        int node=ele.second;
        int dist=ele.first;
        pq.pop();
        //neighbour
        for (auto vec:adj[node]){
            int adjNode=vec[0];
            int adjDist=vec[1];
            if (dist+adjDist<result[adjNode]){
                result[adjNode]=dist+adjDist;
                pq.push({dist+adjDist,adjNode});
            }
        }
    }
    
    
    return result;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
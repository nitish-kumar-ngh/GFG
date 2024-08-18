//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	  // vector<int>adj[];
	   unordered_map<int,vector<int>>adj;
	   for (auto p:prerequisites){
	       adj[p.second].push_back(p.first);
	   }
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
	   if (ans.size()==N)return true;
	   else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
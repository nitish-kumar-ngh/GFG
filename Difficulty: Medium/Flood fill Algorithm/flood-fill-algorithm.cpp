//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(vector<vector<int>>& image,vector<vector<int>>& vis, vector<pair<int,int>>&p,int sr,int sc,int n,int m){
    queue<pair<int,int>>q;
    q.push({sr,sc});
    p.push_back(make_pair(sr,sc));
    vis[sr][sc]=1;
    image[sr][sc]=n;
    while(!q.empty()){
        int currR=q.front().first;
        int currC=q.front().second;
        q.pop();
        //neighbour
        for (auto d:dir){
            int newcurrR=currR+d[0];
            int newcurrC=currC+d[1];
            if (newcurrR>=0 && newcurrC>=0 && newcurrR<image.size() && newcurrC<image[0].size() && !vis[newcurrR][newcurrC] && image[newcurrR][newcurrC]==m){
                q.push({newcurrR,newcurrC});
                image[newcurrR][newcurrC]=n;
                vis[newcurrR][newcurrC]=1;
                p.push_back(make_pair(newcurrR,newcurrC));
            }
        }
        
    }
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<pair<int,int>>p;
    int n=image.size();
    int m=image[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    bfs(image,vis,p,sr,sc,newColor,image[sr][sc]);
    
  
    
    return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
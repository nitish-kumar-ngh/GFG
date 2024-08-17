//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 vector<pair<int,int>>p;
 vector<pair<int,int>>p1;
void dfs (int i,int j, vector<vector<char>> &mat, vector<vector<int>>&vis){
    if (i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]=='X'||vis[i][j]==1)return;
    vis[i][j]=1;
    p.push_back(make_pair(i,j));
    dfs(i+1,j,mat,vis);
    dfs(i,j+1,mat,vis);
    dfs(i-1,j,mat,vis);
    dfs(i,j-1,mat,vis);
        
    
    
    
    
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    { 
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]=='X'){
                   vis[i][j]=1;
               }else if (i>0 && j>0 && i<n-1 && j<m-1 && vis[i][j]==0){
                   
                   dfs(i,j,mat,vis);
                   for (auto v:p){
                    if(v.first==0 || v.second==0 ||v.first==n-1 || v.second==m-1){
                        p.clear();
                    }
                       
                   }
                    for (auto v:p){
                    
                        p1.push_back(make_pair(v.first,v.second));
                    
                       
                   }
       
                   
               }else{
                   vis[i][j]=0;
               }
           }
       }
       for (auto v:p1){
           mat[v.first][v.second]='X';
       }
       return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
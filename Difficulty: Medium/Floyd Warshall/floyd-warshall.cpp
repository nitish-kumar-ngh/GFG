//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int row=matrix.size();
	    int col=matrix[0].size();
	    
	    for(int i=0;i<row;i++){
	        for (int j=0;j<col;j++){
	            if (matrix[i][j]==-1){
	                matrix[i][j]=10000;
	            }
	        }
	    }
	    
	       for(int via=0;via<row;via++){
	        for (int j=0;j<col;j++){
	            for (int k=0;k<col;k++){
	                matrix[j][k]=min(matrix[j][k],matrix[j][via]+matrix[via][k]);
	            }
	            }
	        }
	    
	     for(int i=0;i<row;i++){
	        for (int j=0;j<col;j++){
	            if (matrix[i][j]==10000){
	                matrix[i][j]=-1;
	            }
	        }
	     }
	     return;
	    }
	    
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
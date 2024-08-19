//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        vector<vector<int>>s(rows,vector<int>(columns,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        s[0][0]=0;
        while(!pq.empty()){
            int dis =pq.top().first;
            int x = pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for (auto d:dir){
                int x_=x+d[0];
                int y_=y+d[1];
                if (x_>=0 && y_>=0 && x_<rows && y_<columns ){
                    int adis=abs(heights[x_][y_]-heights[x][y]);
                    if (s[x_][y_]>max(adis,dis) ){
                        pq.push({max(adis,dis),{x_,y_}});
                        s[x_][y_]=max(adis,dis);
                    }
                }
            }
            
        }
       return s[rows-1][columns-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends
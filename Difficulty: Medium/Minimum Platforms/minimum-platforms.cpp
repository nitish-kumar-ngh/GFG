//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
     sort(arr.begin(),arr.end());
     sort(dep.begin(),dep.end());
     int cnt=0;
     int maxcnt=0;
     int i=0,j=0;
     while(i<arr.size()){
         if (arr[i]<=dep[j]){
             cnt++;
             i++;
         }else{
             j++;
             cnt--;
         }
         maxcnt=max(cnt,maxcnt);
     }
     return maxcnt;
    }
};


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool static cmp(pair<int,int>a,pair<int,int>b){
       return a.second<b.second;
   }
    int maxMeetings(vector<int> start, vector<int> end) {
      vector<pair<int,int>>v;
      for (int i=0;i<start.size();i++){
          v.push_back({start[i],end[i]});
      }
      sort(v.begin(),v.end(),cmp);
      int cnt=1;
      int freetime=v[0].second;
      for (int i=1;i<v.size();i++){
          if (v[i].first>freetime){
              cnt++;
              freetime=v[i].second;
          }
      }
      return cnt;
     
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
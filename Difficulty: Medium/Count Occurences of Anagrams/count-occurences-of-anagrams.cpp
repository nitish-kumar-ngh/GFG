//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool allZero( vector<int>&Counter){
        for (int i=0;i<Counter.size();i++){
             if (Counter[i]!=0)return false;
        }
        return true;
    }
	int search(string pat, string txt) {
	    vector<int>Counter(26,0);
	    for (int i=0;i<pat.size();i++){
	        Counter[pat[i]-'a']++;//frequency
	    }
	    
	    int n=txt.size();
	    int k=pat.size();
	    int i=0;
	    int j=0;
	    int ans=0;
	    while(j<n){
	        Counter[txt[j]-'a']--;
	        if (j-i+1==k){
	            if (allZero(Counter))ans++;
	       
	            Counter[txt[i]-'a']++;
	                 i++;
	        }
	        j++;
	    }
	    
	    return ans;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
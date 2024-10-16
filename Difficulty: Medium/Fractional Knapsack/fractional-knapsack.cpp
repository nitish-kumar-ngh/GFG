//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    // Static comparison function to sort items based on value-to-weight ratio
    static bool cmp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }

    // Function to get the maximum total value in the knapsack
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Sort items by descending value-to-weight ratio
        sort(arr, arr + n, cmp);

        double ans = 0;  // Total value in the knapsack
        int i = 0;       // Index to track items

        // Loop through the items until the knapsack is full or all items are considered
        while (w > 0 && i < n) {
            if (w >= arr[i].weight) {
                // If the item can fully fit in the knapsack
                ans += arr[i].value;
                w -= arr[i].weight;
            } else {
                // If only a fraction of the item can fit in the knapsack
                ans += ((double) arr[i].value / (double) arr[i].weight) * w;
                w = 0;  // Knapsack is now full
            }
            i++;
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
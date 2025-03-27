//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {    //nilambar
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        // Sort both arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int platforms_needed = 1, max_platforms = 1;
        int i = 1, j = 0; // Pointers for arrival and departure

        while (i < n && j < n) {
            // If a train arrives before the last one departs, increment count
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            }
            // If a train departs, reduce the platform count
            else {
                platforms_needed--;
                j++;
            }
            // Update the maximum platforms required
            max_platforms = max(max_platforms, platforms_needed);
        }

        return max_platforms;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
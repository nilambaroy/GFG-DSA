//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    //nilambar
    int helper(int ind, vector<int>&arr, vector<int>&dp){
        if(ind>=arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int steal=arr[ind]+helper(ind+2,arr, dp);
        int notSteal = helper(ind+1, arr, dp);
        
        return dp[ind] = max(steal, notSteal);
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n, -1);
        
        return helper(0, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> result;
    unordered_map<int, int> freqMap;

    int n = arr.size();
    if (k > n) return result; // Edge case: Window size greater than array size

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        freqMap[arr[i]]++;
    }
    result.push_back(freqMap.size());

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove the influence of the element sliding out
        freqMap[arr[i - k]]--;
        if (freqMap[arr[i - k]] == 0) {
            freqMap.erase(arr[i - k]);
        }
        
        // Add the influence of the new element
        freqMap[arr[i]]++;
        
        // Store the count of distinct elements in the current window
        result.push_back(freqMap.size());
    }

    return result;
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
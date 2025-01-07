//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int, int> freq; // To store frequency of elements
        int count = 0;
    
        for (int num : arr) {
            int complement = target - num;
    
            // Check if complement exists in the frequency map
            if (freq[complement] > 0) {
                count += freq[complement]; // Count valid pairs
            }
            freq[num]++; // Update frequency of the current number
        }
    
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
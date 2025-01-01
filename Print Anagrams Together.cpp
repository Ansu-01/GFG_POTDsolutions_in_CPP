//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, vector<int>> mp;
        vector<vector<string>> result;
        
        for (int i = 0; i < arr.size(); i++) {
            string sorted_str = arr[i];
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(i);
        }

        for (auto& s : arr) {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
    
            if (mp.count(sorted_str)) { 
                vector<string> group;
                for (int idx : mp[sorted_str]) {
                    group.push_back(arr[idx]); 
                }
                result.push_back(group);
                mp.erase(sorted_str);
            }
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

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
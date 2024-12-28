class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> result;
    
        // Store value to index mapping
        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[arr[i]].push_back(i);
        }
    
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int complement = -arr[i] - arr[j]; // Find the complement
    
                // Check if complement exists in map
                if (indexMap.find(complement) != indexMap.end()) {
                    for (int k : indexMap[complement]) {
                        // Ensure indices are valid and distinct
                        if (k > j) {
                            result.push_back({i, j, k});
                        }
                    }
                }
            }
        }
    
        // Remove duplicates by sorting
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
    
        return result;
    }
};
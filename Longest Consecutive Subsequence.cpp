#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        
        int count = 1;
        int maxi = INT_MIN;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i-1] == arr[i]) continue;
            
            if(arr[i-1] + 1 == arr[i]){
                count++;
            }
            else{
                maxi = max(count, maxi);
                count = 1;
            }
        }
        maxi = max(maxi, count);
        return maxi;
    }
};


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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

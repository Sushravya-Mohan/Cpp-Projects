// // Brute Force Approach
// #include <vector>
// using namespace std;

// vector<int> twoSumBruteForce(vector<int>& nums, int target) {
//     int n = nums.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             if (nums[i] + nums[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }

// Hash Map
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumHashMap(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;     // Map from number to its Index
    for (int i = 0; i< nums.size(); i++) {
        int complement = target - nums[i];
        // Check if the complement exists in the map
        if (numToIndex.find(complement) != numToIndex.end()) {
            return {numToIndex[complement], i};
        }
        // Store the current number with its index
        numToIndex[nums[i]] = i;
    }
    return {};      // Return empty if no solution is found
}
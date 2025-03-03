#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;        // Create a hash set to store unique numbers
    for (int num: nums) {
        // If the current number is already in the set, a duplicate exists
        if (seen.find(num) != seen.end())
            return true;
        // Otherwise insert the current number into the set
        seen.insert(num);
    }
    // If no duplicates are found, return false
    return false;
}

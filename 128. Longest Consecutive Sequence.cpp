#include <unordered_set>
#include <vector>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end()); // Store numbers in a set
        int count = 0;

        for (int num : numsSet) { // Iterate through the set, not the array
            // Check if num is the start of a sequence
            if (numsSet.find(num - 1) == numsSet.end()) {
                int currentNum = num;  // Start of the sequence
                int localCount = 1;    // Length of the current sequence

                // Incrementally check for the next consecutive numbers
                while (numsSet.find(currentNum + 1) != numsSet.end()) {
                    currentNum++;     // Move to the next number
                    localCount++;     // Increment the count
                }

                count = max(count, localCount); // Update the max sequence length
            }
        }

        return count; // Return the longest sequence length
    }
};

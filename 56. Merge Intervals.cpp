#include <vector>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        // Step 1: Sort intervals by their start times
        sort(intervals.begin(), intervals.end());

        // Step 2: Merge intervals
        for (const auto& interval : intervals) {
            // If result is empty or the current interval does not overlap with the last one
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval); // Add the interval to the result
            } else {
                // Merge the intervals by updating the end time of the last interval
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};

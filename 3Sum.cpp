#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Fix 1: Check if array has at least 3 elements
        if(n < 3) return result;
        
        for(int i = 0; i < n - 2; i++) {  // Fix 2: Changed n-1 to n-2
            // Fix 3: Skip duplicates for i, but check if i > 0 first
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;  // Fix 4: j should start from i+1
            int k = n - 1;
            
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum < 0) {
                    j++;
                } else if(sum > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    // Fix 5: Skip duplicates for j and k, but check bounds first
                    while(j < k && nums[j] == nums[j + 1]) j++;  // Changed j-1 to j+1
                    while(j < k && nums[k] == nums[k - 1]) k--;  // Added j < k check
                    
                    // Fix 6: Move pointers after finding a valid triplet
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};
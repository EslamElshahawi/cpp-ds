class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int complement;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        complement = target - nums[i];
        if (hash.find(complement) != hash.end()) {
            return {i , hash[complement]};
        }
        hash[nums[i]] = i;
    }

    return {};
    }
};
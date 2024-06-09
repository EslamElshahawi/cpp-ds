class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int pSum = 0;
        vector<int> modGroups(k);
        modGroups[0] = 1;

        for(int num : nums){
            pSum += num;
            pSum = ((pSum % k) + k) % k;

            ans += modGroups[pSum];
            modGroups[pSum]++;
        }
        return ans;
    }
};
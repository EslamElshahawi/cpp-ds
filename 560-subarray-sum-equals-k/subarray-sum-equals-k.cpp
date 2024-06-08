class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int answer = 0;
        int pSum = 0;
        countMap[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            pSum += nums[i];
            if(countMap.count(pSum - k) > 0) answer += countMap[pSum - k];

            countMap[pSum]++;
        }
        return answer;
    }
};
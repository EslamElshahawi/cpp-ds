class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N, 0);
        int sum = 0;

        for(int i = 0; i < N; i++){
            sum += nums[i];
            result[i] = sum;
        }
        return result;
    }
};
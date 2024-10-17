class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int lsum = 0;
        int rsum = 0;
        for(int i = 0; i < nums.size();i++){
            rsum+= nums[i];
        }
        for(int i = 0; i < nums.size();i++){
            if(i == 0) lsum == 0;
            else lsum += nums[i-1];
            rsum -= nums[i];
            if(rsum == lsum) return i;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> decreasingQueue;
        vector<int> maxList;
        int l = 0;
        int r = 0;

        while(r < nums.size()){
            while(!decreasingQueue.empty() && nums[decreasingQueue.back()] < nums[r]){
                decreasingQueue.pop_back();
            }
            decreasingQueue.push_back(r);
            if(l > decreasingQueue.front()){
                decreasingQueue.pop_front();
            }
            if((r+1) >= k){
                maxList.push_back(nums[decreasingQueue.front()]);
                l++;
            }
            r++;
        }
        return maxList;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_sum = 0;
        int curr_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curr_sum += 1;
                max_sum = max(max_sum, curr_sum);
            } else {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};

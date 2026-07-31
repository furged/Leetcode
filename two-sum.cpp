class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int, int> hm;
        for (int i = 0; i < nums.size(); i++) {
           int curr_value = nums[i];
           int checked_value = target - curr_value;
           
           if (hm.find(checked_value) != hm.end()) {
            answer.push_back(hm.find(checked_value)->second);
            answer.push_back(i);
            return answer;
           }
           hm[curr_value] = i;
        }
        return {};
    }
}   ;

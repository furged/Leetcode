class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int> &candidates, int index, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }
        path.push_back(candidates[index]);
        dfs(candidates, index, target-candidates[index]);
        path.pop_back();

        dfs(candidates, index+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int index, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};

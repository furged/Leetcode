class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long count = 0;
        long long availablek = k;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= availablek) {
                availablek -= nums[i];
            } else {
                long long resourceneeded = nums[i] - availablek;
                long long refillneeded = (resourceneeded + k - 1)/k;
                availablek += refillneeded*k;
                availablek -= nums[i];
                count += refillneeded;
            }
        }
        long long a = count;
        long long b = count + 1;

        if (a % 2 == 0)
            a /= 2;
        else
            b /= 2;

        const long long MOD = 1000000007;
        
        long long ans = ((a % MOD) * (b % MOD)) % MOD;
        return ans;
    }
};

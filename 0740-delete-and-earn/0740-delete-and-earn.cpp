class Solution {
public:

    vector<int> dp;

    int solve(int idx, vector<int>& points) {

        if(idx >= points.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // take current value
        int take =
            points[idx] +
            solve(idx + 2, points);

        // skip current value
        int notTake =
            solve(idx + 1, points);

        return dp[idx] =
               max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxi = 0;

        unordered_map<int,int> freq;

        for(int num : nums) {
            freq[num]++;
            maxi = max(maxi, num);
        }

        // points[i] = total points from value i
        vector<int> points(maxi + 1, 0);

        for(auto it : freq) {
            points[it.first] =
                it.first * it.second;
        }

        dp.resize(maxi + 1, -1);

        return solve(0, points);
    }
};
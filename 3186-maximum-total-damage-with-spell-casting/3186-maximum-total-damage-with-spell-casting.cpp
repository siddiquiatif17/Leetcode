class Solution {
public:

    unordered_map<int,long long> dp;

    long long sol(vector<pair<long long,long long>> &arr,
                  int idx) {

        int n = arr.size();

        if(idx >= n)
            return 0;

        if(dp.count(idx))
            return dp[idx];

        // skip current
        long long notCast =
            sol(arr, idx + 1);

        // take current
        long long cast = arr[idx].second;

        int j = idx + 1;

        // skip values within difference <= 2
        while(j < n &&
              arr[j].first <= arr[idx].first + 2) {
            j++;
        }

        cast += sol(arr, j);

        return dp[idx] =
               max(cast, notCast);
    }

    long long maximumTotalDamage(vector<int>& power) {

        sort(power.begin(), power.end());

        vector<pair<long long,long long>> arr;

        int n = power.size();

        // group duplicates together
        for(int i = 0; i < n; ) {

            long long val = power[i];
            long long sum = 0;

            while(i < n && power[i] == val) {
                sum += power[i];
                i++;
            }

            arr.push_back({val, sum});
        }

        return sol(arr, 0);
    }
};
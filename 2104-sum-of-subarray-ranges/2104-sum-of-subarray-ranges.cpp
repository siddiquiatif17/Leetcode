// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int n = nums.size();
//         // long long ans=0;
//         // for(int i=0;i<n;i++){
//         //     int mini=nums[i];
//         //     int maxi=nums[i];
//         //     for(int j=i+1;j<n;j++){
//         //         mini=min(mini,nums[j]);
//         //         maxi=max(maxi,nums[j]);
//         //         ans+=(maxi-mini);
//         //     }
//         // }
//         // return ans;
       
//     }
// };
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       
//         // long long ans=0;
//         // for(int i=0;i<n;i++){
//         //     int mini=nums[i];
//         //     int maxi=nums[i];
//         //     for(int j=i+1;j<n;j++){
//         //         mini=min(mini,nums[j]);
//         //         maxi=max(maxi,nums[j]);
//         //         ans+=(maxi-mini);
//         //     }
//         // }
//         // return ans;
        int n = nums.size();

        vector<int> minLeft(n, 0);
        vector<int> minRight(n, 0);
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        stack<int> st;

        // ---------------- MIN LEFT ----------------
        // Previous smaller element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                minLeft[i] = 0;
            else
                minLeft[i] = st.top() + 1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // ---------------- MIN RIGHT ----------------
        // Next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                minRight[i] = n - 1;
            else
                minRight[i] = st.top() - 1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // ---------------- MAX LEFT ----------------
        // Previous greater element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                maxLeft[i] = 0;
            else
                maxLeft[i] = st.top() + 1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // ---------------- MAX RIGHT ----------------
        // Next greater or equal element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                maxRight[i] = n - 1;
            else
                maxRight[i] = st.top() - 1;

            st.push(i);
        }

        long long ans = 0;

        // Maximum contribution - Minimum contribution
        for (int i = 0; i < n; i++) {

            long long maxCount =
                1LL * (i - maxLeft[i] + 1) *
                (maxRight[i] - i + 1);

            long long minCount =
                1LL * (i - minLeft[i] + 1) *
                (minRight[i] - i + 1);

            ans += 1LL * nums[i] * maxCount;
            ans -= 1LL * nums[i] * minCount;
        }

        return ans;
    }
};
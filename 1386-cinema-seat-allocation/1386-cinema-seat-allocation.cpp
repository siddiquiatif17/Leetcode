class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mpp;

        for(auto seat : reservedSeats) {
            mpp[seat[0]].push_back(seat[1]);
        }

        int ans = (n - mpp.size()) * 2;

        for(auto &it : mpp) {
            int row = it.first;
            vector<int> seats = it.second;

            bool left = true;
            bool right = true;
            bool middle = true;

            for(int col : seats) {
                if(col >= 2 && col <= 5)
                    left = false;

                if(col >= 6 && col <= 9)
                    right = false;
            }

            if(left) ans++;
            if(right) ans++;

            if(!left && !right) {
                // middle block 4-7 check karna
                bool canMiddle = true;

                for(int col : seats) {
                    if(col >= 4 && col <= 7)
                        canMiddle = false;
                }

                if(canMiddle)
                    ans++;
            }
        }

        return ans;
    }
};
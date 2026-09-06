class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++)mpp[words[i]]++;
        
      

         priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        for (auto it : mpp) {
            pq.push({-it.second, it.first});
        }

        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;


    }
};
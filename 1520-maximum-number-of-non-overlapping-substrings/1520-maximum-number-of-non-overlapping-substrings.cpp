class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
          unordered_map<char, int> firstIndex;
        unordered_map<char, int> lastIndex;
      for(int i=0;i<n;i++){
        if(firstIndex.find(s[i])==firstIndex.end())firstIndex[s[i]]=i;
        lastIndex[s[i]]=i;
      }
        vector<pair<int,int>> intervals;
      for(auto it:firstIndex){
        char ch=it.first;
        int l=firstIndex[ch];
        int r=lastIndex[ch];
        bool valid=true;
        for(int i=l;i<=r;i++){
            char curr=s[i];
            if(firstIndex[curr]<l){
                valid=false;
                break;
            }
            r=max(r,lastIndex[curr]);
        }
        if(valid)intervals.push_back({l,r});
      }

      sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
        return a.second<b.second;
      });

      vector<string> ans;
      int prevEnd=-1;
      for(auto &interval:intervals){
        int l=interval.first;
        int r=interval.second;
        if(l>prevEnd){
            ans.push_back(s.substr(l,r-l+1));
            prevEnd=r;
        }
      }
        return ans;
    }
};
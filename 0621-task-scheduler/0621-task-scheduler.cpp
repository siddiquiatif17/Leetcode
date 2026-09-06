class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<size;i++)mpp[tasks[i]]++;

        priority_queue<int> pq;
        for(auto it:mpp)pq.push(it.second);
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                        int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
                
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0)pq.push(temp[i]);
            }
            if(pq.empty()){
                ans+=temp.size();
            }else ans+=n+1;
        }
        return ans;
        // if(n==0)return tasks.size();
        // int size=tasks.size();
        // vector<int> mpp(26,0);
        // for(int i=0;i<size;i++){
        //     mpp[tasks[i]-'A']++;
        // }
        // sort(mpp.begin(),mpp.end());
        // int maxi=mpp[25];
        // int gaps=maxi-1;
        // int idleSlots=gaps*n;
        // for(int i=24;i>=0;i--){
        //     idleSlots-=min(mpp[i],gaps);
        // }
        // if(idleSlots>0)return tasks.size()+idleSlots;

        // return tasks.size();//Because the most frequent task determines the minimum required cooling structure. If all cooling gaps around the most frequent task can be filled by other tasks, then no idle slots are necessary. Since every other task has frequency ≤ max frequency, a valid schedule without idle time always exists.
       
    }
};
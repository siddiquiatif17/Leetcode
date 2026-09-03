class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int heaviest=pq.top();
            pq.pop();
            int secondHeaviest=pq.top();
            pq.pop();
            if(heaviest!=secondHeaviest){
                pq.push(heaviest-secondHeaviest);
            }
        }
        if(pq.size()==0)return 0;
        return pq.top();
        
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int y=pq.top();
            cout<<y;
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(abs(y-x));
            }
        }
        return pq.empty()? 0: pq.top();
    }
};
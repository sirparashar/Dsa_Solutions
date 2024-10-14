class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        //cout<<pq.size();
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

          //  cout<<y<<x<<'\n';

            int t = y - x;
            if (t!=0) {
                pq.push(t);
                cout<<t;
            }
            cout<<pq.size();
         
        }

         return pq.empty() ? 0 : pq.top();
    }
};
class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int>pq;
        int x=n;
        while(x){
            pq.push(x%10);
            x=x/10;
        }
        int y=pq.top();
        pq.pop();
        return y*pq.top();
    }
};
class MinStack {
public:
    deque<int>q;
    priority_queue<int,vector<int>,greater<int>>pq;
    MinStack() {
        
    }
    
    void push(int value) {
        q.push_front(value);
        pq.push(value);
    }
    
    void pop() {
        int node=q.front();
        q.pop_front();
        priority_queue<int,vector<int>,greater<int>>pq1;
        bool used=false;
        while(!pq.empty()){
            if(pq.top()==node && used==false){
                pq.pop();
                used=true;
            }
            else if(pq.top()!=node || (pq.top()==node && used==true)){
                pq1.push(pq.top());
                pq.pop();
            }
            
        }
        while(!pq1.empty()){
            pq.push(pq1.top());
            pq1.pop();
        }
    }
    
    int top() {
        return q.front();
    }
    
    int getMin() {
        return pq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        // but from stack POV, the pushed element should be at the front
        int n = q.size();
        for (int i=0; i<n-1; i++) { // n-1 because we dont wanna touch the  last element
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // if (q.empty()) {
        //     return NULL;
        // }
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        // if (q.empty()) {
        //     return NULL;
        // }
        return q.front();    
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
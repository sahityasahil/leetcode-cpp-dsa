class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            return;
        }

        while (!s1.empty()) {
            int el = s1.top();
            s2.push(el);
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            int el = s2.top();
            s1.push(el);
            s2.pop();
        }
    }
    
    int pop() {
        if (s1.empty()) {
            return NULL;
        }

        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
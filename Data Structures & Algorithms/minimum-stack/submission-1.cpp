class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top())
            minS.push(val);
    }
    
    void pop() {
        if (!minS.empty() && s.top() == minS.top())
            minS.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }

private:
    stack<int> s;
    stack<int> minS;
};

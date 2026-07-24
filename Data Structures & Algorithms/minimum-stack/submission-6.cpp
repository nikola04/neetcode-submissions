class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (s.empty()) {
            min = val;
            s.push(0);
        } else {
            s.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (s.empty()) return;

        long pop = s.top();
        s.pop();

        if (pop < 0) min = min - pop;
    }
    
    int top() {
        long top = s.top();
        return (top > 0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }

private:
    long min;
    stack<long> s;
};

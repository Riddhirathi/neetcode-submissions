class MinStack {
public:
    stack<int> st;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!mini.empty()) val = min(val, mini.top());
        mini.push(val);
    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        
        data.push(val);
        if(minStack.empty()) minStack.push(val);
        else if(val <= minStack.top()) minStack.push(val);
        //cout << "Push: " << minStack.top() << endl;
    }
    
    void pop() {
        
        int top = data.top(); data.pop();
        if(minStack.top() == top) minStack.pop();
        //cout << "after POP minstack: " << minStack.top() << endl;
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        //cout << "getMin: " << minStack.top() << endl;
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
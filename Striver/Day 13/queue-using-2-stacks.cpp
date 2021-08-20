class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int>s2;
    MyQueue() {
        
    }
    // void swap(const stack<int> &s1, const stack<int>&s2)
    // {
    //     stack<int> temp =s1;
    //     s1 = s2;
    //     s2=temp;
    // }
    /** Push element x to the back of queue. */
    void push(int x) {
        // whatever in s1 push to s2
        while(!s1.empty())
        {
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        // put current element to s1
        s1.push(x);
        
        // whatever in s2 push to s1
        while(!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=s1.top();
        s1.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.size() == 0;
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
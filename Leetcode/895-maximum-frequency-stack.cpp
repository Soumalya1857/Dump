class FreqStack {

    private:
        unordered_map<int, stack<int>> stacks;
        unordered_map<int,int> freq;
        int maxFreqCount;

public:
    FreqStack() {
        this->maxFreqCount = 0;
    }

    void push(int val) {
        int currFreq = 1 + freq[val];
        if(stacks.find(currFreq) == stacks.end()){ // does not exists
            stacks[currFreq] = stack<int>();
            maxFreqCount++;
        }

        stacks[currFreq].push(val);
        freq[val] = currFreq;
    }

    int pop() {

        int val = stacks[maxFreqCount].top();
        stacks[maxFreqCount].pop();
        freq[val]--;

        if(stacks[maxFreqCount].size() == 0){
            stacks.erase(maxFreqCount);
            maxFreqCount--;
        }

        return val;

    }
};

// https://www.youtube.com/watch?v=Z6idIicFDOE
// https://leetcode.com/problems/maximum-frequency-stack/

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
#include"iostream"
#include"vector"
#include"stack"

using namespace std;

class MinStack {
public:
    stack<int> numstack;
    stack<int> minstack;
    /** initialize your data structure here. */
    MinStack() {
        minstack.push(INTMAX_MAX);
    }
    
    void push(int val) {
        numstack.push(val);
        minstack.push(min(minstack.top(),val));      
    }
    
    void pop() {
        numstack.pop();
        minstack.pop();
    }
    
    int top() {
        return numstack.top();
    }
    
    int getMin() {
        return minstack.top();
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
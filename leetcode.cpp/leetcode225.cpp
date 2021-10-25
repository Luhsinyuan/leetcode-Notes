#include"iostream"
#include"vector"
#include"queue"

using namespace std;


class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num=q1.front();
        q1.pop();
        return num;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};
int main()
{
    MyStack* obj = new MyStack();
    obj->push(2);
    obj->push(5);
    obj->push(7);
    int param_2 = obj->pop();
    cout<<param_2<<endl;
    int param_3 = obj->top();
    cout<<param_3<<endl;
    bool param_4 = obj->empty();
    if(param_4)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    system("pause");
    return 0;
}
/**
 * Your MyStack object will be instantiated and called as such:
 * 
 */


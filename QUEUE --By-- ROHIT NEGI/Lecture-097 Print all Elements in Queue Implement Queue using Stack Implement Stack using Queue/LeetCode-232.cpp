// https://leetcode.com/problems/implement-queue-using-stacks/description/


class MyQueue {
public:

    stack<int>st1;
    stack<int>st2;

    MyQueue() {
        
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(empty()){
            return 0;
        }
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int ele = st2.top();
            st2.pop();
            return ele;
        }

        int ele = st2.top();
        st2.pop();
        return ele;
    }
    
    int peek() {
        if(empty()){
            return 0;
        }
        else if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
       
        return st2.top();
    } 
};
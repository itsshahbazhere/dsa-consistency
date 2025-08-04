// https://leetcode.com/problems/implement-stack-using-queues/


//implement in signle queue
// T.C- O(N)
class MyStack {
public:

    queue<int>q;

    MyStack() {
        
    }

    bool empty() {
        return q.empty();
    }

    void push(int x) {
        q.push(x);
    }
    
    int pop() { 
        if(empty()){
            return 0;
        }
        else{
            int size = q.size()-1;
            while(size--){
                q.push(q.front());
                q.pop();
            }
            int ele = q.front();
            q.pop();
            return ele;
        }
    }
    
    int top() {
        return q.back();
    }
    
};


//implement using 2 queue
// T.C- O(N)
class MyStack {
public:

    queue<int>q1;
    queue<int>q2;

    MyStack() {
        
    }

    bool empty() {
        return q1.empty()&&q2.empty();
    }

    void push(int x) {
        if(empty()){
            q1.push(x);
        }
        else if(q1.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
    }
    
    int pop() { 
        if(empty()){
            return 0;
        }
        else if(q1.empty()){
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }
    
    int top() {
        if(empty()){
            return 0;
        }
        else if(q1.empty()){
            return q2.back();
        }
        else{
           return q1.back();
        }
    }
    
};
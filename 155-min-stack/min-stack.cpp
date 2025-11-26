class MinStack {
    stack<int> number;
    stack<int> min;

public:
    MinStack() {
        
    }
    void push(int val) {

        if(min.empty()){
            number.push(val);
            min.push(val);
        }
        else{
            number.push(val);

            if(val < min.top()) {
                min.push(val);
            }
            else min.push(min.top()); 
        }
    }
    
    void pop() {
        number.pop();
        min.pop();
    }
    
    int top() {
        return number.top();
    }
    
    int getMin() {
        return min.top();
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
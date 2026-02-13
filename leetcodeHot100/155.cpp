#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minst;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minst.push(val);
        }
        else{
            minst.push(min(minst.top(),val));
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

// 题解给的方法，minst和st不对齐但是同步的思路
// 而且不用处理pop时候的empty
class MinStack2 {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack2(){
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};



//�ȿ�˼·----Ȼ�����𡣡���ʼû����Ŀ��˼=��=������
//�ø���ջ��ά��

class MinStack {
public:
        stack<int> x_stk;
        stack<int> min_stk;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if( x_stk.empty() || min_stk.top() >= x) min_stk.push(x);
        x_stk.push(x);
    }
    
    void pop() {
        if(x_stk.top() == min_stk.top() ) min_stk.pop();
        x_stk.pop();
    }
    
    int top() {
        return x_stk.top();
    }
    
    int getMin() {
       return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//��������һ��ջ��ά���������䡣����

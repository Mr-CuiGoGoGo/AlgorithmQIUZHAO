
//������Ŀ����ϵ��----�ڿ��˴��˼·����vectorʵ��
//���ѭ��˫�˶���
class MyCircularDeque {
public:
    vector<int> deq;
    int icapacity;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        icapacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(deq.size() < icapacity){
            deq.insert(deq.begin(), value);
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(deq.size() < icapacity){
            deq.push_back(value);
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(deq.empty()) return false;
        deq.erase(deq.begin());
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(deq.empty()) return false;
        deq.pop_back();
      //  cout <<"shan last: current_capacity "<<deq.size()<<endl;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(deq.empty()) return -1;
        return deq[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(deq.empty()) return -1;
        return deq.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return deq.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return deq.size() == icapacity?true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

//�ܸо�������Ϊ�����㲻�����κ������������������Ѽ�¼�ã�����ʱ���ϵ����ҵ��������һ����д�� ˫������˫ջ�Լ� ����Ľⷨ������������
//���滹ʹ��������vector��������ʼ���⣬û����vector��������Ϻ��Ĺ�ʽ ˫ָ���������  head = (tail + 1 ) % capacity
//�������  һЩ���е�˼·�����=��=�����ۻ��ۣ�����ʶ��~~~
class MyCircularDeque {
public:
    vector<int> deq;
    int capacity;
    int head = 0;
    int tail = 0;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k + 1;
        deq.assign(k+1, 0);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        head = (head - 1 + capacity)% capacity;
        deq[head] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        deq[tail] = value;
        tail = (tail + 1)% capacity;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        head = (head + 1 )% capacity;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        tail = (tail - 1 + capacity)% capacity;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return deq[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return deq[(tail-1+capacity)%capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == tail;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return tail == (head - 1 + capacity)% capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
////h�������� ˫ջ �� ˫������~~
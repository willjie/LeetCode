/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

//���������ö�����ʵ�ֶ�ջ��
���ľ���������������

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q2.push(x);
        
        while(q2.size() > 1)   //�������һ��Ԫ���������Ԫ�ط�������һ��������
        {
            q1.push(q2.front());
            q2.pop();
        }
       
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!q2.empty())
        {
            q2.pop();
        }
        else
        {
            for(int i = 0; i < q1.size() - 1; i++)
            {
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q2.pop();
            q1.pop();
        }
        
      
        
    }

    // Get the top element.
    int top() {
        if(!q2.empty())
        {
            return q2.front();
        }
        for(int i = 0; i < q1.size() - 1; i++)
        {
             q1.push(q1.front());
             q1.pop();
        }
         q2.push(q1.front());
         q1.pop();
        return q2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        
        return q1.empty() && q2.empty();
        
    }
    
    private:
    queue<int> q1;   //�ö�����ģ���ջ
    queue<int> q2;   //����������һ������ջ��Ԫ�أ�ģ��ջ��Ԫ��
};
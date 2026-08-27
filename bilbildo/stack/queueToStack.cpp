class MyStack {
    private:
    queue<int>* q1;
    queue<int>* q2;

    public:

        MyStack() {
            q1 = new queue<int>;
            q2 = new queue<int>;
        }
        ~MyStack() {
            delete q1;
            delete q2;
        }
    
        void push(int x) {
            q1->push(x);
            while (!q2->empty()) {
                q1->push(q2->front());
                q2->pop();
            }
            queue<int>* temp = q2;
            q2 = q1;
            q1 = temp;
        }
    
        int pop() {
            int val = q2->front();
            q2->pop();
            return val;
           
        }
    
        int top() {
          return q2->front();
        }
    
        bool empty() {
            return q2->empty();
        }
    };
class ArrQueue
{
private:
    int* queue;
    int cap;
    int front;
    int rear;
private:
    void expand(int size) {
        int* p = new int[size];
        int first = front;
        int i = 0;
        for (; first!=rear; i++, first=(first+1)%cap) {
            p[i] = queue[first];
        }
        delete[] queue;
        queue = p;
        cap =size;
        front = 0;
        rear = i;
    }
public:
    ArrQueue(int size)
    : cap(size)
    , front(0)
    , rear(0)
    {queue = new int[size];}
public:
    void push(int val) {
        if ((rear+1)%cap==front) {
            expand (2*cap);
        }
        queue[rear] = val;
        rear = (rear+1)%cap;
    }
    void pop() {
        if (front == rear) {
            throw "empty";
        }
        front = (front+1)%cap;
    }
    int showHead() const {
        if (front == 0 && rear == 0) {
            throw "empty";
        }
        return queue[front];
    }
    int showTail() const {
        if (front == 0 && rear == 0) {
            throw "empty";
        }
        return queue[(rear-1+cap)%cap];
    }
    int size() const {
        int a = 0;
        for (int i =front; i!=rear; i=(i+1)%cap) 
        {
            a++;
        }
        return a;
    }
};
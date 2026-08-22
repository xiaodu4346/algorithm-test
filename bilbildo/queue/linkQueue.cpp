class LinkQueue
{
private:
    struct Node
    {
        Node(int size)
        : data(size)
        , next(nullptr)
        , pre(nullptr)
        {}

        int data;
        Node* next;
        Node* pre;
    };
private:
    Node* head;
public:
    LinkQueue()
    {head = new Node(0);
    head->next = head;
    head->pre = head;
    }
    ~LinkQueue() {
        Node* p =head->next;
        while(p!=head) {
            head->next = p->next;
            p->next->pre = head;
            delete p;
            p=head->next;
        }
        delete head;
    }
public:
    void push(int val) {
        Node* node = new Node(val);
        Node* p = head->pre;
        p->next = node;
        node->pre = p;
        node->next = head;
        head->pre = node;
    }
    void pop (){
        if (head->next == head) {
            throw "empty";
        }
        Node* p =head->next;
        head->next = p->next;
        p->next->pre = head;
        delete p;
    }
    int showHead() const {
        if (head->next == head) {
            throw "empty";
        }
        return head->next->data;
    }
    int showTail() const {
        if (head->next == head) {
            throw "empty";
        }
        return head->pre->data;
    }

};
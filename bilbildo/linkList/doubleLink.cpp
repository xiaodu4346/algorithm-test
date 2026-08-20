#include <iostream>

using namespace std;

struct Node
{
    Node(int a =0)
    : data(a)
    , pre(nullptr)
    , next(nullptr)
    {}

    int data;
    Node* pre;
    Node* next;
};

class doubleLink
{
private:
    Node* head;
public:
    doubleLink(int a=0)
    {
        head = new Node();
    }

void touInsert(int val) {
    Node* node = new Node(val);
    node->pre = head;
    node->next = head->next;
    if (head->next!= nullptr) {
        head->next->pre = node;
    };
    head->next = node;
}

void weiInsert(int val) {
    Node* node = new Node();
    Node* p = head;
    while (p->next!=nullptr) {
        p = p->next;
    };
    p->next = node;
    node->pre = p;
}

void deleteNode(int val) {
    Node* p = head->next;
    while (p!=nullptr) {
        if (p->data == val) {
            p->pre->next = p->next;
            if (p->next!=nullptr) {
                p->next->pre = p->pre;
            };
            delete p;
            return;
        }
        else 
        {
            p = p->next;
        }
    }
}

void show() {
    Node* p = head->next;
    while (p!=nullptr) {
        cout << p->data << ' ';
        p=p->next;
    };
}
};
int main() {}
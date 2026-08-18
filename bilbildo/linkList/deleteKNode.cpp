#include <iostream>

using namespace std;

//删除单链表倒数第K个节点
struct Node 
{
    int data;
    Node* next;
};

class Link
{
private:
    Node* lhead;
    friend bool deleteKNode(Link& clink, int k);

public:
    Link()
    {
        lhead = new Node();
        lhead->next = nullptr;
    };

public:
void insert(int val) {
    Node* p = lhead;
    Node* newNode = new Node();
    while (p->next!= nullptr) {
        p = p->next;
    };
    p->next = newNode;
    newNode->data = val;
    newNode->next = nullptr;
    };

    void show() {
        Node* p = lhead->next;
        while (p!= nullptr) {
            cout << p->data << ' ';
            p = p->next;
        }
    };
};

bool deleteKNode(Link& clink, int k) {
    Node* p = clink.lhead;
    Node* q = clink.lhead;
    for (int i=0; i<k; i++) {
        p = p->next;
        if (p == nullptr) {
            return false;
        };
    };
    while (p->next != nullptr) 
    {
       p = p->next;
       q = q->next;
    };
    Node* del = q->next;
    q->next = q->next->next;
    delete del;
    return true;
}

int main() {
    Link clink;
    clink.insert(10);
    clink.insert(20);
    clink.insert(30);
    clink.insert(40);
    clink.insert(50);
    clink.show();
}

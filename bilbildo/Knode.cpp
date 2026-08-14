#include <iostream>

using namespace std;

//单链表求倒数第K个节点
struct Node 
{
    int data;
    Node* next;
};

class Link
{
private:
    Node* lhead;
    friend int Knode(Link & slink, int k);

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
int Knode(Link& slink, int k) {
    Node* p = slink.lhead->next;
    Node* q = slink.lhead->next;
    for (int i=0; i<k ;i++) {
        p = p->next;
    };
    while (p!=nullptr) {
        p = p->next;
        q = q->next;
    };
    return q->data;
}

int main() {
    Link clink;
    clink.insert(10);
    clink.insert(20);
    clink.insert(30);
    clink.insert(40);
    clink.insert(50);
    cout << Knode(clink,2);
    clink.show();




}

#include <iostream>

using namespace std;

//旋转链表，将每个节点向后移动K位
struct Node 
{
    int data;
    Node* next;
};

class Link
{
private:
    Node* lhead;
    friend void function(Link& clink, int k);

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

void function(Link& clink, int k) {
     Node*p = clink.lhead;
     Node*q = clink.lhead;
     int num = 0;
     for (Node* k = clink.lhead->next; k!= nullptr; k=k->next) 
     {
        num++;
     };
     k= k%num;
     for (int i=0; i<k; i++) {
        p = p->next;
     };
     while (p->next != nullptr) {
        p = p->next;
        q = q->next;
     };
     p->next = clink.lhead->next;
     clink.lhead->next = q->next;
     q->next =nullptr;

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

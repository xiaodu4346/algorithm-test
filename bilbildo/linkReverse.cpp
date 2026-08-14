#include <iostream>

using namespace std;

//单链表的逆序
struct Node 
{
    int data;
    Node* next;
};

class Link
{
private:
    Node* lhead;
    friend void linkResver(Link & slink);

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

void linkResver(Link & slink) {
    Node* p = slink.lhead->next;
    Node* q = slink.lhead->next;
    slink.lhead->next = nullptr;;
    while (p!=nullptr) {
        q = p->next;
        p->next = slink.lhead->next;
        slink.lhead->next = p;
        p = q;
    }

}

int main() {
    Link clink;
    clink.insert(10);
    clink.insert(20);
    clink.insert(30);
    clink.insert(40);
    clink.insert(50);
    linkResver(clink);
    clink.show();




}

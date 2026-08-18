#include <iostream>

using namespace std;

//合并两个有序单链表
struct Node 
{
    int data;
    Node* next;
};

class Link
{
private:
    Node* lhead;
    friend void mergeLink(Link& link1, Link& link2);

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

void mergeLink(Link& link1, Link& link2) {
    Node* p = link1.lhead->next;
    Node* q = link2.lhead->next;
    Node* last = link1.lhead;
    link2.lhead->next = nullptr;
    while (p!=nullptr && q!=nullptr) {
        if (p->data < q->data) {
            last->next = p;
            p = p->next;
            last = last->next;
        }
        else  {
            last->next = q;
            q = q->next;
            last = last->next;
        };
    };

    if (p != nullptr) {
        last->next = p;
    };
    if (q != nullptr) {
        last->next = q;
    };
}

int main() {
    Link clink;
    Link clink2;
    int arr[] = {12,32,54,56,88};
    int brr[] = {2,32,45,55,66,111};
    for (int a : arr) {
        clink.insert(a);
    };
    for (int b : brr) {
        clink2.insert(b);
    };
    clink.show();
    clink2.show();
    cout << '\n';
    mergeLink(clink,clink2);
    clink.show();
    clink2.show();
}


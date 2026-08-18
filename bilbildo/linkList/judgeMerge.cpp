#include <iostream>

using namespace std;

//验证两个链表是否相交，并返回交点。
struct Node 
{
    int data;
    Node* next;
};

class Link
{
private:
    Node* lhead;

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

bool judgeMerge(Node* head, Node* head2, int val) {
    Node* p = head->next;
    Node* q = head2->next;
    int a = 0, b = 0;
    while (p!= nullptr) {
        a++;
        p = p->next;
    };
    while (q!= nullptr) {
        b++;
        q = q->next;
    };
    p = head;
    q = head2;
    if (a > b) {
        for (int i = 0; i < (a-b); i++) {
            p = p->next;
        };
    }
    else  {
        for (int i = 0; i < (a-b); i++) {
            q = q->next;
        };      
    };

    while (q!=nullptr && p!=nullptr) 
    {
        if (q == p) {
            val = p->data;
            return true;
        }

    }
    return false;
}

int main() {
    // 公共部分：8 -> 10
    Node common2{10, nullptr};
    Node common1{8, &common2};

    // 链表1：1 -> 2 -> 8 -> 10
    Node node2{2, &common1};
    Node node1{1, &node2};
    Node head1{0, &node1};

    // 链表2：3 -> 8 -> 10
    Node node3{3, &common1};
    Node head2{0, &node3};
    int a;
    judgeMerge(&head1,&head2,a);

    return 0;
}
 


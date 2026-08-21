#include <iostream>
using namespace std;


class LinkStack
{
private:
    struct Node
    {
        Node(int a):data(a), next(nullptr) {}
        int data;
        Node* next;
    };
private:
    Node* head;
public:
    LinkStack()
    {
        head = new Node(0);
    }
    ~LinkStack()
    {
        while (head!=nullptr) {
            Node* p = head->next;
            delete head;
            head = p;
        }
    }
public:
    void push(int val) {
        Node* newnode = new Node(val);
        newnode->next = head->next;
        head->next = newnode;
    }
    void pop() {
        if (head->next == nullptr) {
            throw "empty";
        }
        Node* p = head->next;
        head->next = p->next;
        delete p;
    }
    int showTop() const {
        if (head->next == nullptr) {
            throw "empty";
        }
        return head->next->data;
    }
    bool empty() {
        return head->next == nullptr;
    }


};




int main () {}
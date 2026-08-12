#include <iostream>

using namespace std;


class Link
{
private:
    struct Node 
    {
        int data;
        Node* next;
    };
private:
    Node* head;

public:
    Link()
    {
        Node* head = new Node();
    };

public:
    void insert(int val) {
        Node* p = head;
        Node* newNode = new Node();
        while (p->next!= nullptr) {
            p = p->next;
        };
        p->next = newNode;
        newNode->data = val;
    };
    void deleteOne(int val) {
        Node* q = head;
        Node* p = head->next;
        while (p->data == val) {
            q->next = p->next;
            delete p ;
        }
            q = p;
            p = p->next;
    };
    void show() {
        Node* p = head->next;
        while (p!= nullptr) {
            cout << p->data << ' ';
            p = p->next;
        }
    };
        

};
int main() {
    Link L;
    L.insert(10);
    L.show();


}
#include <iostream>

using namespace std;

//寻找链表中是否有环
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

bool findCycle(Node* head, int val) {
    Node* fast = head;
    Node* slow = head;
      while (fast != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            fast = head;
           while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
          };
          val = slow->data;
          return true;
        };
      };
      return false;

}

int main() {}
 


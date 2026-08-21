#include <iostream>
#include <cstring>
using namespace std;

class ArrStack
{
private:
    int* arrstack;
    int cap;
    int top;

private:
    void expand(int a) {
        int* newstack = new int[a];
        memcpy(newstack, arrstack, top*sizeof(arrstack[0]));
        delete[] arrstack;
        arrstack = newstack;
        cap = a;
    }
public:
    ArrStack(int a = 10)
    : top()
    , cap(a)
    {arrstack = new int[cap];}
    ~ArrStack()
    {
        delete[] arrstack;
    }
public:
    void push(int val) {
        if (top == cap) {
            expand(2*cap);
        }
        arrstack[top] = val;
        top++;
    }
    void pop() {
        if (top == 0) {
            throw "stack is empty";
        }
        top--;
    }
    int showTop() const {
        if (top == 0) {
            throw "empty";
        }
        return arrstack[top-1];
    }


};

int main() {}
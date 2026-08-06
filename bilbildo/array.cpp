#include <iostream>

using namespace std;

class Array
{
public:
    Array(int a = 10):size(a),curNum(0)
    {
        newArray = new int[size];
    }
    ~Array() 
    {
        delete[] newArray;
    }
private:
    int size;
    int curNum;
    int * newArray;


public:
   void addElement(int val) {
    if (size == curNum) {
        expand();
    };
    newArray[curNum] = val;
    ++curNum;

   };
   void expand() {
    int* p = new  int [size*1.5];
    memcpy(p, newArray, sizeof(int) * curNum);
    delete[] newArray;

    newArray = p;
    size*= 1.5;
   };
   void show() {
    for (int i=0; i<curNum; i++) {
        cout << newArray[i] << ' ';
    }
   }
};

int main(){
    Array a(10);
    a.addElement(2);
    a.show();


}
//记得对函数的有效性进行一个判断

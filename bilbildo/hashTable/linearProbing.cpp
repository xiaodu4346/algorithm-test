#include <iostream>

using namespace std;

enum Status {
    beingUsed,
    neverUse,
    deleted
};
struct Table {
    Table(int a = 0, Status status = neverUse)
    : key(a)
    , status(status)
    {}
    int key;
    Status status;
};


class HashTable {
private:
    Table* table;
    int cap;
    int size;
    double hashFactor;

private:
    static const int primeSize = 10;
    static int primeArr[];

private:
    void expand() {
        
    }
public:
    HashTable (int cap_ = 3, double hashFactor_ = 0.75)
    : cap(cap_)
    , size(0)
    , hashFactor(hashFactor_)
    {table = new Table[cap];}
    ~HashTable() {
        delete[] table;
    }

public:
    void insert(int val) {
        double factor = size*1.0/cap;
        if (factor > hashFactor) {
            expand();
        }
        int index = val%cap;
        if (table[index].status != beingUsed) {
            table[index].key = val;
            size++;
            table[index].status = beingUsed;
            return;
        }
        if (table[index].status == beingUsed) {
            while (index < cap && table[index].status != beingUsed) {
                index = (index+1)%cap;
            }
            table[index].key = val;
            size++;
            table[index].status = beingUsed;
        }
    }
    void delete_(int val) {
        if (size == 0) {
            throw "empty!";
        }
        int index =val%cap;
        do{
            if (table[index].key == val) {
                table[index].status = beingUsed;
                size--;
                break;
            }
            index = (index+1)%cap;
        }while(index < cap && table[index].status != neverUse);
    }
};

int HashTable::primeArr[] = {5, 11, 23, 47, 97, 193, 389, 769, 1543, 3079};

int main() {



}
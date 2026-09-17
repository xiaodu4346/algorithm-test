#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


class HashTable 
{
public:
    HashTable(int size = primes_[0], double loadFactor = 0.75)
    : useBucketNum_(0)
    , loadFactor_(loadFactor)
    {
        if (size != primes_[0]) {
            for ( ; primeIndex < PRME_SIZE; primeIndex++) {
                if (primes_[primeIndex] >= size) {
                    break;
                }
            }
            if (primeIndex == PRME_SIZE) {
                primeIndex--;
            }
        }
        table_.resize(primes_[primeIndex]);
    }
public:
    void insert(int key)
    {
        double factor = useBucketNum_*1.0/table_.size();
        if (factor > loadFactor_) {
            expand();
        }
        int index = key%table_.size();//key%primes_[primeIndex];
        if (table_[index].empty())
        {
            useBucketNum_++;
            table_[index].push_back(key);
        }
        else
        {
            auto it = ::find(table_[index].begin(),table_[index].end(),key);
            if (it == table_[index].end()) 
            {
                table_[index].push_back(key);
            }
        }
    }
    void erase(int key)
    {
        int index = key%table_.size();
        auto it = ::find(table_[index].begin(), table_[index].end(), key);
        if (it != table_[index].end()) 
        {
            table_[index].erase(it);
            if (table_[index].empty()) 
            {
                useBucketNum_--;
            }
        }
    }
    bool find(int key) 
    {
        int index = key%table_.size();
        auto it = ::find(table_[index].begin(), table_[index].end(), key);
        return it != table_[index].end();
        
    }
private:
    vector<list<int>>table_;
    int useBucketNum_;
    double loadFactor_;


    static const int PRME_SIZE = 10;
    static int primes_[PRME_SIZE];
    int primeIndex;
private:
    void expand()
    {
        if (primeIndex +1 == PRME_SIZE)
        {
            throw "max!";
        }
        primeIndex++;
        vector<list<int>> oldTable;
        table_.swap(oldTable);
        table_.resize(primes_[primeIndex]);
        useBucketNum_ = 0;
        for (auto& list : oldTable)
        {
            for (int& key : list) 
            {
                int index = key%table_.size();
                if (table_[index].empty())
                {
                    useBucketNum_++;
                }
                table_[index].push_back(key);
            }
        }
    }


};
int HashTable::primes_[] = {3,7,23,47,97,251,443,911,1471,42773};

int main()
 {}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(12);
    vec.push_back(12);

    // 查找第一个重复出现的数字
    unordered_set<int> s1;

    for (const auto& a : vec)
    {
        auto it = s1.find(a);

        if (it == s1.end())
        {
            s1.insert(a);
        }
        else
        {
            cout << a << endl;
            break;
        }
    }

    // 统计每个数字出现的次数
    unordered_map<int, int> m1;

    for (const auto& b : vec)
    {
        auto it = m1.find(b);

        if (it == m1.end())
        {
            m1.emplace(b, 1);
        }
        else
        {
            it->second += 1;
        }
    }

    // 输出重复出现的数字
    for (const auto& item : m1)
    {
        if (item.second > 1)
        {
            cout << "key: " << item.first << endl;
        }
    }

    return 0;
}
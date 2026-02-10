#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;


// 这个就是leetcode的题解
// 这里面学到的有
// emplace_back和push_back的区别
// 还有"=="在vector中的使用
vector<int> findAnagrams(string s, string p)
{
    int sLen = s.size(), pLen = p.size();

    if (sLen < pLen)
    {
        return vector<int>();
    }

    vector<int> ans;
    vector<int> sCount(26);
    vector<int> pCount(26);
    for (int i = 0; i < pLen; ++i)
    {
        ++sCount[s[i] - 'a'];
        ++pCount[p[i] - 'a'];
    }

    if (sCount == pCount)
    {
        ans.emplace_back(0);
    }

    for (int i = 0; i < sLen - pLen; ++i)
    {
        --sCount[s[i] - 'a'];
        ++sCount[s[i + pLen] - 'a'];

        if (sCount == pCount)
        {
            ans.emplace_back(i + 1);
        }
    }

    return ans;
}

int main(){
    findAnagrams("ad","asbbbbcce");
    unordered_map<int,int> testnum;
    testnum.insert({1,1});
    ++testnum[1];
    //testnum.insert(1,3);
    cout << testnum[1];
}
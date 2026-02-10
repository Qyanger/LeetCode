#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

// 利用前缀和和哈希表
// mp first参数为前缀和，second为前缀和出现的次数
// 这个是leetcode的题解
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    
    for (auto x : nums)
    {
        pre += x;
        if (mp.find(pre - k) != mp.end())
        {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}

int main(){
    vector<int> test = {1};
    cout << subarraySum(test,0);

}
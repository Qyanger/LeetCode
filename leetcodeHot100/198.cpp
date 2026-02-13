#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2);
        // dp[i] 为以nums[i-2]即第i-1个元素结尾的最高金额
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = nums[0];

        for(int i=3;i<=n+1;++i){
            dp[i] = max(dp[i-2],dp[i-3])+nums[i-2];
        }
        return max(dp[n+1],dp[n]);
    }
};

// 方法二 求解直接为子问题
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for(int i=1;i<n;++i){
            if(i ==1){
                dp[i] = max(dp[i-1],nums[1]);
            }
            else
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

int main(){
    cout << "hello";
}
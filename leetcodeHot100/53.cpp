#include<iostream>
#include<vector>
using namespace std;


// 动态规划要求已经求解的子问题不受后续阶段的影响。这个条件也被叫做「无后效性」
//使用动态规划
//子问题为，以nums[i]结尾的连续子数组的最大和
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    dp[0]=nums[0];
    for(int i =1;i<n;++i){
        dp[i] = max(nums[i],dp[i-1]+nums[i]);

    }
    int ans = dp[0];
    for(auto it: nums){
        ans = max(ans,it);
    }
    return ans;
}

// 优化之后
int maxSubArrayPro(vector<int> &nums){
    int ans = nums[0];
    int pre = 0;
    for(int it: nums){
        pre = max(pre+it,it);
        ans = max(ans,pre);
    }
    return ans;
}
int main(){
    vector<int> test = {1};
    cout << maxSubArray(test);
}

// 暴力
// int maxSubArray(vector<int> &nums)
// {
//     int n =nums.size();
//     vector<int> pre(n+1);
//     pre[0] = 0;
//     for(int i =0;i<n;++i){
//         pre[i+1] = pre[i]+nums[i];
//     }
//     int ans = nums[0];
//     for(int i =0;i<=n;++i){
//         for(int j = i+1;j<=n;++j){
//             ans = max(ans,pre[j]-pre[i]);
//         }
//     }
//     return ans;
// }

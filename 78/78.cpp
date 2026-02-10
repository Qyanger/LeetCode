#include<iostream>
#include<vector>
using namespace std;

// 这道题目和22类似，用回溯法
// 这里，使用全局变量不传参的话，会节省很多时间***
void dfs(vector<vector<int>>& ans,int index,vector<int>& nums,vector<int> cur){
    if(index == nums.size()){
        ans.push_back(cur);
        return;
    }
    cur.push_back(nums[index]);
    dfs(ans,index+1,nums,cur);
    cur.pop_back();
    dfs(ans,index+1,nums,cur);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    dfs(ans,0,nums,{});
    return ans;
}

int main(){

}
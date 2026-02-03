#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *slow = head, *fast = head;
            while(fast != nullptr && fast->next !=nullptr){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    ListNode *index1 = head;
                    ListNode *index2 = slow;
                    while(index1 != index2 ){
                        index1 = index1->next;
                        index2 = index2->next;
                    }
                    return index1;
                }
            }
            return nullptr;
        }
};

class Solution1 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int,int> map;
            for(int i = 0;i<nums.size();i++){
                if(map.find(target-nums[i]) != map.end()){
                    res.push_back(map[target-nums[i]]);
                    res.push_back(i);
                    return res;
                }
                map[nums[i]] = i;
            }

            // for(int i = 0;i<nums.size();i++){
            //     for(int j = i+1;j<nums.size();j++){
            //         if(nums[i]+nums[j] == target){
            //             res.push_back(i);
            //             res.push_back(j);
            //             return res;
            //         }
            //     }
            // }
            // return res;
        }
};

class Solution2 {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>> map;
            for(string str: strs){
                string key = str;
                sort(key.begin(),key.end());
                map[key].push_back(str);
            }
            vector<vector<string>> res;
            for(auto it = map.begin();it != map.end();it++){
                res.push_back(it->second);
            }
            return res;
        }
    };

class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        // 0 1 1 2
        // 1 0 1
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()-1,0);
        for(int i=0;i<dp.size();++i){
            dp[i] = nums[i+1] - nums[i];
        }
        int res = 1;
        int curr =1;
        for(auto it : dp){
            if(it == 1){
                curr++;
            }
            else if(it == 0){
                continue;
            }
            else{
                curr =1;
            }
            res = max(res,curr);
        }
        return res;
    }
};

class Solution4 {
    public:
        void moveZeroes(vector<int>& nums) {
            // for(int e=0;e<nums.size();e++){
            //     for(int i =0;i<nums.size()-1;i++){
            //         if(nums[i] == 0){
            //             int tmp = nums[i];
            //             nums[i] = nums[i+1];
            //             nums[i+1] = tmp;
            //         }
            //     }
            // }


        }
    };

class Solution5 {
public:
    int maxArea(vector<int>& height) {
        int res =0;
        int left =0,right = height.size()-1;
        while(left<right){
            res = max(res,min(height[left],height[right])*(right-left));
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};

class Solution6 {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            unordered_set<int> set;
            for(auto it :nums){
                set.insert(it);
            }
            sort(nums.begin(),nums.end());
            vector<vector<int>> res;
            for(int first =0;first<nums.size();++first){
                if(first>0 && nums[first]==nums[first -1]){
                    continue;
                }
                int target = -nums[first];
                for(int second =first+1;second<nums.size();++second){
                    if(second>first+1 && nums[second] == nums[second-1]){
                        continue;
                    }
                    if(second<nums.size()-1 &&-nums[first]-nums[second] >=nums[second+1] && set.find(-nums[first]-nums[second])!=set.end()){
                        res.push_back({nums[first],nums[second],-nums[first]-nums[second]});
                    }
                    
                }
            }
            return res;
        }
    };

class Solution7 {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
                // 3 1 1 1 2 4 
                // 3 2 4

                //3 2 1 1 2
            }
            stk.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += min(leftMax,rightMax) - height[left];
                ++left;
            } else {
                ans += min(leftMax,rightMax) - height[right];
                --right;
            }
        }
        return ans;
    }
};


int main(){

}
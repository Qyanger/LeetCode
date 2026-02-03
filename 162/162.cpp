#include<iostream>
#include<vector>
using namespace std;

int find(vector<int>& nums){
    int left = 0,right = nums.size()- 1;

    if(nums.size()==2) return nums[1]>nums[0]?1:0;
    while(left < right){
        int mid = (left + right)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid] > nums[mid-1]){left=mid;}
        else if(nums[mid] > nums[mid+1]){right=mid;}
    }
    return left;

}

int main() {
    vector<int> test1 = {1,2,5,4,3};
    vector<int> test2 = {1,2};
    vector<int> test3 = {2,1};
    cout << find(test1) << endl <<find(test2) << endl <<find(test3);
    return 0;
}
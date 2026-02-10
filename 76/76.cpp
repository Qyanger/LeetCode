#include<iostream>
#include<vector>
using namespace std;

// 通过堆排序来找到第k大的数
// 堆排序的函数有pro版本的，见/additional/heap.cpp
void adjust(vector<int> &nums,int i,int size){
    int left = 2*i+1;
    int right = 2*i+2;
    int adjustpos = i;
    if(left <= size && nums[left]>nums[i]) adjustpos = left;
    if(right <= size && nums[right]>nums[i]) adjustpos = right;
    if(adjustpos==i) return;

    if(left <= size&&right<= size&&nums[left]>nums[right])
        adjustpos = left;
    swap(nums[i],nums[adjustpos]);
    adjust(nums,adjustpos,size);
}
void heapmake(vector<int> &nums){
    for(int i = nums.size()-1;i>=0;--i){
        adjust(nums,i,nums.size()-1);
    }
}
int findKthLargest(vector<int> &nums, int k)
{
    heapmake(nums);
    int size = nums.size()-1;
    while(k>1){
        swap(nums[0],nums[size]);
        adjust(nums,0,size-1);
        --size;
        --k;
    }
    return nums[0];

}


int main(){
    vector<int> test = {3,1,2,4};
    cout << findKthLargest(test,2);
    for(auto it: test){
        cout << it <<" ";
    }

}
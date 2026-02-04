#include<iostream>
#include<vector>
using namespace std;

int inpartion(vector<int>& arr,int left,int right){
    int val = arr[left];
    while(left < right){
        while(arr[right]>=val && left<right) --right;
        arr[left] = arr[right];
        while(arr[left]<=val && left<right) ++left;
        arr[right] = arr[left];
    }
    arr[left] = val;
    return left;

}
void quickSort(vector<int> &arr, int left, int right)
{
    if (left <= right)
    {
        int mid = inpartion(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
    return;
}

int main(){
    vector<int> test1 = {3,1,7,5,0};
    vector<int> test2 = {1};
    vector<int> test = {1,1,2,2,5,5,2,2};
    quickSort(test,0,test.size()-1);
    for(auto it :test){
        cout << it<<" ";
    }
}
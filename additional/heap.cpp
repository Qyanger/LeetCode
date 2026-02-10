#include<iostream>
#include<vector>
using namespace std;
/* 大根堆
       0
      / \
     1   2
    / \ / \ 
   3  4 5  6
*/
// 重点在于写adjust
void adjust(vector<int>& arr,int size,int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int adjustpos = i;
    if(left <= size&&arr[left]>arr[i])
        adjustpos = left;
    if(right<= size&&arr[right]>arr[i])
        adjustpos = right;
    if(adjustpos == i)
        return;        

    if(left <= size&&right<= size&&arr[left]>arr[right])
        adjustpos = left;
    
    swap(arr[i] ,arr[adjustpos]);

    // int temp = arr[i];
    // arr[i] = arr[adjustpos];
    // arr[adjustpos] = temp;

    adjust(arr,size,adjustpos);

}

// 改进后的adjust
void adjustPro(vector<int>& arr,int size,int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int adjustpos = i;
    if(left <= size&&arr[left]>arr[i])
        adjustpos = left;
    if(right<= size&&arr[right]>arr[adjustpos])
        adjustpos = right;
    if(adjustpos == i)
        return;        
    
    swap(arr[i] ,arr[adjustpos]);

    adjust(arr,size,adjustpos);
}

void heapsort(vector<int>& arr){
    // 建堆
    for(int i = (arr.size()-1)/2;i>=0;--i){
        adjust(arr,arr.size()-1,i);
    }

    // DeBug
    
    // for(auto it : arr){
    //     cout << it<<" ";
    // }
    // cout << endl;

    // adjust(arr,arr.size()-1,0);
    // for(auto it : arr){
    //     cout << it<<" ";
    // }
    // cout << endl;

    // 排序
    for(int size = arr.size()-1;size >=0;--size){
        swap(arr[0],arr[size]);
        adjust(arr,size-1,0);         
    }

}

int main(){
    vector<int> arr0 = {5,3,2,1,6,7};
    vector<int> arr1 = {};
    vector<int> arr2 = {1};
    vector<int> arr = {2,2,2,2};
    heapsort(arr);
    for(auto it : arr){
        cout << it<<" ";
    }
}

#include<iostream>
#include<vector>
using namespace std;

//第二版，第二版用多的空间存储结果（ans），放弃了erase，时间缩减到了11ms
// 如果使用sort()函数，时间将缩减到3ms
// sort()的使用，添加头文件<algorithm>
// sort(a,b,c); a,b为迭代器，[a,b),左闭右开，排序不稳定，c为传入的排序函数
// vector<vector<int>> 是实际开发中多维数组的主流写法，
// sort 可以直接对其排序，默认按「行的字典序」升序排列（即先比第一个元素，第一个相等比第二个，以此类推）
int inpartion(vector<vector<int>>& arr,int left,int right){
    int val = arr[left][0];
    vector<int> temp = arr[left];
    while(left < right){
        while(arr[right][0]>=val && left<right) --right;
        arr[left] = arr[right];
        while(arr[left][0]<=val && left<right) ++left;
        arr[right] = arr[left];
    }
    arr[left] = temp;
    return left;

}
void quickSort(vector<vector<int>> &arr, int left, int right)
{
    if (left <= right)
    {
        int mid = inpartion(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
    return;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n=intervals.size();
    quickSort(intervals,0,n-1);
    vector<vector<int>> ans;
    int temp1 =intervals[0][0],temp2=intervals[0][1];
    for(int i =0;i<n-1;++i){
        if(temp2>=intervals[i+1][0]){
            temp2 = max(intervals[i+1][1],temp2);
        }
        else{
            ans.push_back({temp1,temp2});
            temp1 =intervals[i+1][0],temp2=intervals[i+1][1];
        }
    }
    ans.push_back({temp1,temp2});

    return ans;
}

int main(){
    vector<vector<int>> test = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(test);
    for(auto it: ans){
        for(auto it2:it){
            cout << it2 <<" ";
        }
        cout<<endl;
    }
}

// 第一版，不知道sort可以直接排序，手搓了快速排序，
// merge函数中，erase操作特别耗时（430ms），这点非常重要，直接影响了输出效率

// int inpartion(vector<vector<int>>& arr,int left,int right){
//     int val = arr[left][0];
//     vector<int> temp = arr[left];
//     while(left < right){
//         while(arr[right][0]>=val && left<right) --right;
//         arr[left] = arr[right];
//         while(arr[left][0]<=val && left<right) ++left;
//         arr[right] = arr[left];
//     }
//     arr[left] = temp;
//     return left;

// }
// void quickSort(vector<vector<int>> &arr, int left, int right)
// {
//     if (left <= right)
//     {
//         int mid = inpartion(arr, left, right);
//         quickSort(arr, left, mid - 1);
//         quickSort(arr, mid + 1, right);
//     }
//     return;
// }

// vector<vector<int>> merge(vector<vector<int>> &intervals)
// {
//     int n=intervals.size();
//     quickSort(intervals,0,n-1);

//     for(int i =0;i<n-1;){
//         if(intervals[i][1]>=intervals[i+1][0]){
//             int temp1 = intervals[i][0];
//             int temp2 = intervals[i][1];
//             intervals.erase(intervals.begin()+i);
//             intervals[i][0] = temp1;
//             intervals[i][1] = max(intervals[i][1],temp2);
//             --n;
//         }
//         else{
//             ++i;
//         }
//     }
//     return intervals;
// }
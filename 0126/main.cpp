#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
// #include<pair>
using namespace std;
struct node{
    int number;
    int pos;
    int count;
};

void func(vector<int>& arr){
    int n = arr.size();
    vector<node> my;
    int curpos = -1;
    int prenumber = -1111;
    int finalpos = 0;
    for(int i =0;i<n;++i){
        if(arr[i]==prenumber){
            ++ my[curpos].count;
        }
        else{
            curpos++;
            my.push_back({arr[i],finalpos,1});
            ++finalpos;
            prenumber = arr[i];
        }
    }
    for(int i=0;i<my.size();++i){
        arr[my[i].pos] = my[i].number;
        --my[i].count;
    }

    int start = finalpos;
    for(int i=0;i<my.size()&&start<n;++i){
        while(my[i].count>0){
            arr[start] = my[i].number;
            --my[i].count;
            ++start;
        }
    }


}

int main(){
    int arr[5] = {1,2,7,4,3};
    

    vector<int> in = {1,1,2,2,2,3,4,5,5,6,7,7};
    // func(in);
    // for(auto &it :in ){
    //     cout << it <<",";
    // }
}
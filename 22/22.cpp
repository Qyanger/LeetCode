#include<iostream>
#include<vector>
using namespace std;

// 递归算法，试探着括号是否可以加入
void TryLegal(vector<string>& ans,int Lcount,int Rcount,int n,string cur){
    if((int)cur.size() == 2*n){
        ans.push_back(cur);
        return;
    }
    if(Lcount < n){
        cur.append("(");
        TryLegal(ans,Lcount+1,Rcount,n,cur);
        cur.pop_back();
    }
    if(Lcount > Rcount){
        cur.append(")");
        TryLegal(ans,Lcount,Rcount+1,n,cur);
        cur.pop_back();
    }

}

vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        TryLegal(ans,0,0,n,cur);
        return ans;
}

int main(){
    vector<string> test;
    test = generateParenthesis(3);
    for(auto it : test){
        cout << it <<" ";
    }

}
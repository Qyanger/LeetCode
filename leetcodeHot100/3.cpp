#include<iostream>
#include<unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int ans = 0;
    int left = -1,right = -1;
    unordered_set<char> window;
    for(int i =0 ;i<(int)s.length();++i){
        if(!window.count(s[i])){
            right++;
            window.insert(s[i]);
            ans = max(ans,(right-left));
        }
        else{
            right++;
            left++;
            while(s[left]!=s[i]){
                window.erase(s[left]);
                ++left;
            }
        }
    }
    return ans;
}

int main(){
    string test = "bbbbbb";
    cout << lengthOfLongestSubstring(test);
}
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int n =s.size();

    for(int i =n-1;i>=0;--i){
        if(st.empty())
            st.push(s[i]);
        else if(s[i] == '}'||s[i] == ']'||s[i] == ')'){
            st.push(s[i]);
        }
        else{
            switch(s[i]){
                case '{':
                if(st.top()=='}')
                    st.pop();
                else
                    st.push('{');
                break;

                case '[':
                if(st.top()==']')
                    st.pop();
                else
                    st.push('[');
                break;

                case '(':
                if(st.top()==')')
                    st.pop();
                else
                    st.push('(');
                break;
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main(){
    string test = "([])";
    cout << isValid(test);
}
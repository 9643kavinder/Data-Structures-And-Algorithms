#include <bits/stdc++.h>
using namespace std;
bool is_balanced(string s1){
    stack<char>s;
    for(int i=0;i<s1.length();i++){
        char c = s1[i];
        if(c=='('){
            s.push(c);
        }
        else{
            if(s.empty() or s.top()!='('){
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    return s.empty();
}
int main() {
    string s;
    cin>>s;
    if(is_balanced(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
void reverseHelper(stack<int>&s,int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    //Recursive Case
    int y = s.top();
    s.pop();
    reverseHelper(s, x);
    s.push(y);
    return;
}
void reverseStack(stack<int>&s){
    //Base Case
    if(s.empty()){
        return;
    }
    //Recursive Case
    int x = s.top();
    s.pop();
    reverseStack(s);
    reverseHelper(s, x);
    return;
}
int main(){
    // Reverse Stack Using Recursion
    int n;
    cin>>n;
    stack<int>s;
    for(int i=1;i<=n;i++){
        int value;
        cin>>value;
        s.push(value);
    }
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}
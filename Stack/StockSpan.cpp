#include <bits/stdc++.h>
using namespace std;
vector<int> stock_span(int *a,int n){
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<n;i++){
        int num = a[i];
        while(!s.empty() and a[s.top()]<a[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(i+1);
        }
        else{
            ans.push_back((i-s.top()));
        }
        s.push(i);
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans = stock_span(a,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"END";

}

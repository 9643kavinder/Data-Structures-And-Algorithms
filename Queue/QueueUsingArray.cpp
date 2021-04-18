/* --------KAVINDER PANWAR---------  */
#include<iostream>
using namespace std;
// Implement a circular queue using array
class queue{
    public:
    int *a;
    int cs,ms,front,rear;
    queue(int ds=10){
        a = new int[ds];
        ms = ds;
        cs = 0;
        front = 0;
        rear = ms-1;
    }
    void push(int data){
        rear = (rear+1)%ms;
        a[rear] = data;
        cs++;
    }
    void pop(){
        front = (front+1)%ms;
        cs--;
    }
    bool empty(){
        return cs==0;
    }
    int front_element(){
        return a[front];
    }
    
};
int main()
{
    queue q;
    for(int i=1;i<=10;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.front_element()<<" ";
        q.pop();
    }
    
    return 0;
}
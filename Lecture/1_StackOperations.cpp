#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 20

//Create an empty stack
class Stack{
private:
    int arr[MAX_SIZE];
    int top;

public: 
    //Constructor to initialize an empty stack 
    Stack(){
        top = -1;
    }

    //Add a new item
    void push(int value){
        if(top >= MAX_SIZE - 1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    //Remove the item that was added most recently
    int pop(){
        if(top < 0){
            cout << "Stack Underflow\n";
        }
        return arr[top--];
    }

    //Determine whether a stack is empty
    bool isEmpty(){
        return top == -1;
    }
    
    bool isFull(){
        return top == MAX_SIZE - 1;
    }

    //Retrieve the item that was added most recently 
    int peek(){
        if(top < 0){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void destroy(){
        top = -1;
    }

};

//Destroy stack

int main(){
    Stack s;
    s.push(7);
    s.push(8);
    s.push(10);
    s.push(6);
    cout << s.peek();


    while(!s.isFull()){
        s.push(rand());
    }
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    return 0;
}
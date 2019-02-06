#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct _stack{
    int data;
    struct _stack* next;
} stack;

class Stack{
public:
    stack* top = NULL;    // set stack's top as NULL
    
    // insert a node at the stack top
    void push(int value){
        if(top == NULL){
            stack* startStack = new stack;    // allocate memory for new node
            startStack -> data = value;    // put value in stack
            startStack -> next = NULL;
            top = startStack;
        }
        else{
            stack* addStack = new stack;
            addStack -> data = value;
            addStack -> next = top;
            top = addStack;
        }
    }
    
    void print(){
        stack* currentStack;
        currentStack = top;
        
        cout << endl << "Stack: ";
        while(currentStack!=NULL){
            cout << currentStack->data << " ";    // print LIFO
            currentStack = currentStack->next;
        }
        cout << endl;
    }
};



int main(){
    Stack s;
    
    cout << "------ Enter 5 integers ------ " << endl;;
    for(int i=0; i<5; i++){
        int item;
        cin >> item;
        s.push(item);
    }
    
    s.print();
}

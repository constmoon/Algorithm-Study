#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct _stack{
    int data;
    struct _stack *link;
}stack;

class stack_operation{
    
    public :
    stack* top = NULL;
    
    void add(int item){
        if(top == NULL){
            stack *_s = new stack;
            _s->data = item;
            _s->link = NULL;
            top = _s;
        }
        else{
            stack* temp = new stack;
            temp -> data = item;
            temp -> link = top;
            top = temp;
        }
    }
    void stack_delete(int item){
        stack *cnode, *pnode;
        pnode = NULL;
        cnode = top;
        while(cnode!=NULL){
            if(cnode -> data == item)
                break;
            pnode = cnode;
            cnode = cnode -> link;
        }
        if(cnode == NULL){
            cout << "Can't find the item" <<endl;
            return;
        }
        if(cnode == top){
            top = top->link;
            delete(cnode);
        }
        else{
            pnode -> link = cnode -> link;
            delete(cnode);
        }
    }
    void print(){
        stack* cnode;
        cnode = top;
        cout << "Stack : ";
        while(cnode!=NULL) {
            cout << cnode->data <<" ";
            cnode = cnode->link;
        }
        cout << endl;
    }
    void stack_max(){
        int max;
        stack* cnode;
        cnode = top;
        if(top == NULL){
            cout << "Stack is empty!" <<endl;
            return;
        }
        max = cnode -> data;
        while(cnode != NULL){
            if(cnode->data > max)
                max = cnode -> data;
            cnode = cnode->link;
        }
        cout << "Maximum data in stack : " << max << endl;
    }
    void stack_min(){
        int min;
        stack* cnode;
        cnode = top;
        if(top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        min = cnode -> data;
        while(cnode != NULL){
            if(cnode->data < min)
                min = cnode -> data;
            cnode= cnode ->link;
        }
        cout << "Minimum data in stack : "<< min << endl;
    }
    void find(int item){
        int order = 1;
        stack* cnode;
        cnode = top;
        while(cnode!=NULL){
            if(cnode -> data == item) {
                cout << "Order of item : "<< order << endl;
                break;
            }
            
            cnode = cnode -> link;
            order ++;
        }
        if(cnode == NULL){
            cout << "Can't find item" << endl;
        }
    }
    void show_num(){
        int num=0;
        stack* cnode;
        cnode = top;
        if(top == NULL){
            cout << "Stack is empty!" << endl;
        }
        while(cnode!=NULL){
            num++;
            cnode = cnode->link;
        }
        cout << "Num of stack is : " << num << endl;
    }
    
};

int main(int argc, const char * argv[]){
    stack_operation stack;
    int choice, item;
    do{
        cout << "==================================================" << endl;
        cout << "              Stack Operations Menu              " << endl;
        cout << "==================================================" << endl;
        
        cout << "1. Add items" << endl;
        cout << "2. Delete items" << endl;
        cout << "3. Show the number of items" << endl;
        cout << "4. Show min and max items" << endl;
        cout << "5. Find an item" << endl;
        cout << "6. Print all items" << endl;
        cout << "7. Exit" << endl;
        
        cin >> choice;
        
        switch(choice){
            case 1 :
                cout << "Input to add : ";
                cin >> item;
                stack.add(item);
                cout << endl;
                break;
            case 2 :
                cout << "Input to delete : ";
                cin >> item;
                stack.stack_delete(item);
                cout << endl;
                break;
            case 3 :
                stack.show_num();
                cout << endl;
                break;
            case 4 :
                stack.stack_max();
                stack.stack_min();
                cout << endl;
                break;
            case 5 :
                cout << "Input to find : ";
                cin >> item;
                stack.find(item);
                cout << endl;
                break;
            case 6 :
                stack.print();
                cout << endl;
                break;
            case 7 :
                return 0;
            default :
                cout << "invalid num! try again" << endl;
                cout << endl;
                break;
        }
    }while(choice != 7);
    
    return 0;
}

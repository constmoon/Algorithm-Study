#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{   // node(data) structure
    int data;
    struct node* next;
}Node;

typedef struct queue{   // queue structure
    Node* front;
    Node* rear;
}Queue;

class QueueClass{
public:
    
    Queue* queue = new Queue;
    
    void initQueue(){   // initialize queue
        queue->front = NULL;    // front and rear points NULL
        queue->rear = NULL;
    }
    
    // 1.ADD
    void add(int value){    // insert node using Dynamic memory allocation
        Node* newNode = new Node;    // allocate new node and save in newNode
        newNode->data = value;
        newNode->next = NULL;    // newNode->next points NULL(the last)
        
        if(queue->front == NULL){    // if queue is empty
            queue->front = newNode;    // newNode will be the first value
            queue->rear = newNode;    // front and rear all point newNode
        }
        else{    // if queue is not empty
            queue->rear->next = newNode;    // save newNode in rear->next
            queue->rear = newNode;    // current rear points newNode
        }
    }
    
    
    // 2.DELETE
    void deleteNode(int value){
        Node* deleteNode = queue->front;
        
        while(deleteNode != NULL){
            if(deleteNode->data == value)
                break;
            deleteNode = deleteNode->next;
        }
        
        // if node is delete in front
        if(deleteNode == queue->front){
            queue->front = deleteNode->next;
            delete(deleteNode);
        }
        else if(deleteNode == queue->rear){
            queue->rear = deleteNode->next;
            delete(deleteNode);
        }
        else if(deleteNode == queue->front && deleteNode == queue->rear){
            delete(deleteNode);
            queue->front = NULL;
            queue->rear = NULL;
        }
        else{
            if(deleteNode == NULL){
                cout << "None!" << endl;
            }
        }
    }

    
    // 3.SHOW NUMBER
    void showNum(){
        int num=0;
        Node* tmpNode = queue->front;
        
        // if queue is empty
        if(queue->rear == NULL){
            cout << "Number of queue is: " << 0 << endl;
        }
        // until reaches to empty
        while(tmpNode != NULL){
            num++;
            tmpNode = tmpNode->next;
        }
        cout << "Number of queue is: " << num << endl;
    }
    
    
    
    // 4.MAX item
    void queueMax(){
        int max;
        Node* currentNode = queue->front;
        
        max = currentNode->data;
        while(currentNode != NULL){
            if(currentNode->data > max){
                max = currentNode->data;
            }
            currentNode = currentNode->next;
        }
        cout << "Maximum item: " << max << endl;
    }
    
    
    // 4.MIN item
    void queueMin(){
        int min;
        Node* currentNode = queue->front;
        
        min = currentNode->data;
        while(currentNode != NULL){
            if(currentNode->data < min){
                min = currentNode->data;
            }
            currentNode = currentNode->next;
        }
        cout << "Minimum item: " << min << endl;
    }
    
    
    // 5.Find item
    void find(int value){
        int idx=0;
        Node* currentNode = queue->front;
        
        while(currentNode != NULL){
            if(currentNode->data == value){
                cout << "Index of " << value << " is : " << idx << endl;
                break;
            }
            currentNode = currentNode->next;
            idx++;
        }
        if(currentNode==NULL){
            cout << "None!" << endl;
        }
    }
    
    
    // 6.Print queue
    void print(){
        Node* currentNode = queue->front;
        
        cout << "Queue: ";
        while(currentNode != NULL){    // if data available
            cout << currentNode->data << " ";    // print LIFO
            currentNode = currentNode->next;
        }
        cout << endl;
    }
    
    
};



int main(){
    QueueClass queueOperation;
    
    int choice, item;
    
    cout << "==================================================" << endl;
    cout << "               Queue Operations Menu              " << endl;
    cout << "==================================================" << endl;
    
    cout << "1. Add items" << endl;
    cout << "2. Delete items" << endl;
    cout << "3. Show the number of items" << endl;
    cout << "4. Show min and max items" << endl;
    cout << "5. Find an item" << endl;
    cout << "6. Print all items" << endl;
    cout << "7. Exit" << endl;

    queueOperation.initQueue();
    
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter item to add: ";
                cin >> item;
                queueOperation.add(item);
                break;
                
            case 2:
                cout << "Enter item to delete: ";
                cin >> item;
                queueOperation.deleteNode(item);
                break;
                
            case 3:
                queueOperation.showNum();
                break;
                
            case 4:
                queueOperation.queueMax();
                queueOperation.queueMin();
                break;
                
            case 5:
                cout << "Enter item to find: ";
                cin >> item;
                queueOperation.find(item);
                break;
                
            case 6:
                queueOperation.print();
                break;
                
            default:
                cout << "Invalid choice! try again." << endl;
                break;
        }
    }while(choice>0);

}

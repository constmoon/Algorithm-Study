#include <iostream>
using namespace std;

typedef struct _queue{
    int data;
    struct _queue *link;
}queue;

class Queue{
    queue* front;
    queue* rear;
    public :
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void add (int item) {
        if(front == NULL && rear == NULL) {
            queue *q = new queue;
            q->data = item;
            q->link = NULL;
            front = q;
            rear = q;
        } else {
            queue* temp = new queue;
            temp -> data = item;
            rear->link = temp;
            rear = rear->link;
        }
    }
    int dequeue() {
        int item;
        
        if(front == NULL && rear == NULL) {
            return NULL;
        }
        item = front->data;
        front = front->link;
        return item;
    }
};

int main(int argc, const char * argv[]) {
    Queue q;
    int item;
    
    for(int i=0; i<30; i++) {
        q.add(i+1);
    }
    cout << "Queue : ";
    for(int i=0; i<5; i++) {
        item = q.dequeue();
        cout << item << " ";
    }
    cout << endl;
    return 0;
}

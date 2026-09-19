#include <iostream>
using namespace std;
class node{
    public:
    int data;
    int pr;
    node*next;
    node(int val,int priority){
        data=val;
        pr=priority;
        next=NULL;
    }
};
class PriorityQueue{
    private:
    node*front;
    public:
    PriorityQueue(){
        front=NULL;
    }
    bool isempty(){
        return front==NULL;
    }
    void enqueue(int val,int priority){
        node*newnode=new node(val,priority);
        if(isempty()){
            front=newnode ;
        }
        else if(newnode->pr<front->pr){
            newnode -> next =front;
            front=newnode;
        }
        else{
            node*temp=front;
            while(temp->next!=NULL && temp->next->pr<newnode->pr){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    void dequeu(){
        if(isempty()){

        }
    }









    // we can also add a arranging function so when the priority gets same then the arrangement 
    // will be on the basis of value
    void dequeue(){
        if(isempty()){
            cout<<"UNDERFLOW";
            return;
        }
        node*temp=front;
        front=front->next;
        cout<<"Deleted value: "<<temp->data<<endl;
        cout<<"Deleted priority: "<<temp->pr<<endl;
        delete temp;
    }
    int peek(){
        if(isempty()){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        return front->data;
    }
    void display(){
        if(isempty()){
            cout<<"Underflow";
            return;
        }
        node*temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" -> "<<temp->pr<<"\n";
            temp=temp->next;
        }
    }
};










int main(){
    PriorityQueue q;
    q.enqueue(50,1);
    q.enqueue(20,2);
    q.enqueue(10,5);
    q.enqueue(30,3);
    q.enqueue(10,1);
    q.enqueue(40,1);
    q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.display();

    
    return 0;
}
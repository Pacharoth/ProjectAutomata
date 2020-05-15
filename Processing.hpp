#include <iostream>
#include <cstring>
using namespace std;
//All structure for character data use in to automata Algorithm
//and language to do operate with character
struct Element{
  char data;
  Element *next;
  Element *prev;
};
typedef struct Element Element;
struct Queue{
  int n;
  Element *front;
  Element *rear;
};
typedef struct Queue Queue;

struct Element1{
    string language;
    Element1 *next;
    Element1 *prev;
};
typedef struct Element1 element;
struct Stack{
    int n;
    element *top;
};
typedef struct Stack stack;

//ALl Algorithm
class algo{
public:

    //create the Queue
    Queue *createQueue(){
        Queue *q;
        q= new Queue();
        q->n=0;
        q->front=NULL;
        q->rear=NULL;
        return q;
    }

    //begin Queue
    void beQueue(Queue *q,char newdata){
        Element *e;
        e=new Element();
        e->data =newdata;
        e->prev=NULL;
        e->next= q->front;
        if (q->n==0) {
            q->rear=e;
        }
        if (q->n!=0) {
            q->front->prev=e;
        }
        q->front=e;
        q->n++;
    }

    //add enQueue
    void enQueue(Queue *q,char newdata){
        Element *e;
        if (q->n==0) {
            beQueue(q,newdata);
        }else{
            e=new Element();
            e->data =newdata;
            e->next=NULL;
            q->rear->next=e;
            e->prev=q->rear;
            q->rear =e;
            q->n++;
        }
    }

    //deQueue
    void deQueue(Queue *q){
        Element *tmp;
        tmp =q->front;
        if (q->n==0) {
            cout<<"You cant delete the data";
        }else{
            q->front =q->front->next;
            if (q->n>=2) {
                /* code */
                q->front->prev=NULL;
            }
            delete tmp;
            if (q->n==1) {
                q->rear =NULL;
            }
            q->n--;
        }
    }


    //display Queue
    void displayQueue(Queue *q){
        Element *tmp;
        tmp=q->front;
        while (tmp!=NULL) {
            cout<<tmp->data<<"\t";
            tmp=tmp->next;
        }
        cout<<endl;
    }

    //create stack
    stack *createStack(){
        stack *s;
        s= new stack();
        s->n=0;
        s->top=NULL;
        return s;
    }

    //Push data
    void push(stack *s,string newData){
        element *e;
        e=new element();
        e->language=newData;
        e->next=s->top;
        if (s->n>=2) {
            s->top->prev=e;
        }
        s->top =e;
        s->n++;
    }

    //pop data
    void pop(stack *s){
        element *tmp;
        if (s->n==0) {
            cout<<"You cannot delete";
        }else{
            tmp=s->top;
            s->top=s->top->next;
            if (s->n>=2) {
                s->top->prev=NULL;
            }
            delete tmp;
            s->n--;
        }
    }

    //display push
    void displayStack(stack *s){
        element *tmp;
        tmp=s->top;
        while (tmp!=NULL) {
            cout<<tmp->language<<"\t";
            tmp=tmp->next;
        }
    }
}algo;


//Automata Algorithm
class automata{
public:
    //design Automata
    //from start state

}automata;


//All Menu
class Menu{
public:

    void mainMenu(){
        cout<<"\t\t1.Input the strings.\n\n";
        cout<<"\t\t2.Check the strings(FA or DFA).\n\n";
        cout<<"\t\t3.Check strings accept by a FA or not.\n\n";
        cout<<"\t\t4.Construct an equivalent DFA from an NFA.\n\n";
        cout<<"\t\t5. Minimize a DFA.\n\n";
        cout<<"\t\t6. Exit the program.\n\n";
    }
}menu;

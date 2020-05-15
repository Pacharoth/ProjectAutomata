#include <iostream>
#include <cstring>
struct Element{
  int data;
  Element *next;
  Element *prev;
};
struct Queue{
  int n;
  Element *front;
  Element *rear;
};
class algo{
public:

  //create the Queue
  Queue *createQueue(){
    Queue *q;
    q->n=0;
    q->front=NULL;
    q->rear=0
    return q;
  }


  //add enQueue
  void enQueue(Queue *q,int newdata){
    Element *e;
    e=new Element();
    e->data =newdata;
    if (ls->n==0) {
      e->next= q->front;
      if (q->n==0) {
        q->rear=e;
      }
      if (q->n!=0) {
        q->rear->prev=NULL;
      }
      q->front=e;
      q->n++
    }else{
      q->next=NULL;
      q->rear->next=e;
      e->prev=q->rear;
      q->rear=e;
      q->n++;
    }
  }

  //deQueue
  void deQueue(Queue *q,int newdata){
    
  }
  //display Queue
};

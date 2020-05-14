#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

// create the queue
struct Element{
    string data;
    Element *next;
    Element *prev;

};
struct queue{
    int n;
    Element *front;
    Element *rear;
};

//Block algorithm
class algo{
    public:
        queue *Queue();
        void beQueue(queue *q,string newData);//insert the begin data
        void enQueue(queue *q,string newData);//insert data end
        void displayQueue(queue *q);//show data from the queue
        void deQueueAll(queue *q);//delete all the data from the queue
        void deBeQueue(queue *q);//delete begin of queue
        void deEnQueue(queue *q);//delete end of queue
};



int main(){
    algo Queue;
    queue *q;
    q= Queue.Queue();
    Queue.beQueue(q,"hello" );
    Queue.beQueue(q,"hello" );
    Queue.displayQueue(q);
    // Queue.deQueueAll(q);
    Queue.deEnQueue(q);
    // Queue.deBeQueue(q);
    // Queue.deBeQueue(q);
    Queue.displayQueue(q);

}


//creating the queue
queue* algo::Queue(){
    queue *q;
    q=new queue();
    q->n=0;
    q->front=NULL;
    q->rear=NULL;
    return q;
}


//create beQueue
void algo::beQueue(queue *q,string newData){
    Element *e;
    e=new Element();
    e->data=newData;
    e->next= q->front;
    e->prev=NULL;
    q->front=e;
    if(q->n==0){
        q->rear=e;
    }
    if(q->n!=0){
        q->rear->prev=e;
    }
    q->n++;
}


//add enQueue
void algo::enQueue(queue *q, string newData){
    Element *e;
    if(q->n==0){
        beQueue(q, newData);
    }
    else{
        e= new Element();
        e->data=newData;
        e->next=NULL;
        q->rear->next=e;
        e->prev=q->rear;
        q->rear=e;
        q->n++;
    }
}


//display Queue
void algo::displayQueue(queue *q){
    Element *tmp;
    tmp =q->front;
    int i=0;
    cout<<"ID\t\tLanguage"<<endl;
    if(q->n==0){
        cout<<"No language!\n";
    }
    while(tmp!=NULL){
        cout<<i<<"\t\t"<<tmp->data<<endl;
        i++;
        tmp=tmp->next;
    }
}

//delete end
void algo::deEnQueue(queue *q){
    Element *tmp;
      if (q->n==1) {
          deBeQueue(q);
      }else{
          tmp=q->rear;//access from rear
          q->rear=q->rear->prev;// rear like double link list access back
          q->rear->next =NULL;//set next null
          delete tmp;//delete to free memory
          if (q->n==1) {
              q->front =NULL;//set front null
          }
          q->n--;
      }
}


//delete begin
void algo::deBeQueue(queue *q){
    Element *tmp;
    if (q->n==0) {
      cout<<"no data\n";
    }else{
      tmp =q->front;
      q->front = q->front->next;
      if (q->n>=2) {
        q->front->prev=NULL;
      }
      delete tmp;
      if (q->n==1) {
          q->rear=NULL;
      }
      q->n--;
    }


}

//delete all
void algo::deQueueAll(queue *q){
    if (q->n>=1) {
        while(q->n>=1){
            deBeQueue(q);
        }
        cout<<"Delete successful\n\n";
    }else{
        cout<<"There is no data\n";

    }
}

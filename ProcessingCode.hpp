#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
    string      language;
    Element     *next;
    Element     *previous;
}Element;

typedef struct{
    int         access_element;
    Element     *front;
    Element     *rear;
}Queue;

//declare class do Algorithm
class algorithm_part{
public:
    Queue       *createQueue();         //create the queue
    void        beQueue(Queue *queueList,string newLanguage);       //insert queue to use in end queue
    void        enQueue(Queue *queueList,string newLanguage);
    void        deQueue(Queue *queueList);
private:
    string      languageForUserInput;
    Queue       *queueList;
};

//declare class automata
class automata_part{
public:
    void        startState(string check_language);                  //create start state
    void        normalStateFirst(string checkLanguageFirst);        //create first state
    void        normalStateSecond(string checkLanguageSecond);      //create second state
};

//declare class Database
class database_part{
public:
    void        splitSentence(string splitString);
    static int  callback(void *data,int init_string,char **row_data,char **colName);        //create callback to store data into queue

    void        createDatabase();
    void        insertDatabase(Queue *queueList);
    void        selectDatbase(Queue *queueList,string initString);
};

//part algorithm
Queue* algorithm_part:: createQueue(){
    Queue *list_Data;
    list_Data = new Queue();
    list_Data->access_element = 0;
    list_Data->front = NULL:
    list_Data->rear = NULL;
    queueList = list_Data;
    return queueList;
}

void algorithm_part::beQueue(Queue *queueList,string newLanguage){
    Element *newElement;
    newElement = new Element();
    languageForUserInput = newLanguage;
    newElement->langauge = languageForUserInput;        //set langauge in queque as data parameter
    newElement->previous = NULL;                        //set previous of newElement point null
    newElement->next = queueList->front;                //set next of queue become front
    if (queueList->access_element == 0)
        quequeList->rear = e;                             //if element 0 so data will set at rear too
    if (queueList->access_element != 0)
        quequeList->front->previous = e;                  //if element bigger than 0 so front point back so we can access back
    queueList->access_element++;                        //increment to next element, but element change the whole thing
                                                        //like first 1 and then all of list element change to 2
}

void algorithm_part::enQueue(Queue *queueList,string newLanguage){
    Element *newElement;
    if (queueList->access_element == 0) {
        beQueue(queueList,newLanguage);
    }else{
        newElement = new Element();
        newElement->next = NULL;                         //next of newElement set to null  
        quequeList->rear->next = newElement;             //rear next set newElement
        newElement->previous = queueList->rear;          //newelement previous set as rear
        quequeList->rear = newElement;                   //set data to rear so last element
    }
}

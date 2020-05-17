#include <iostream>
#include <cstring>
#include <sqlite3.h>
#include <bits/stdc++.h>

using namespace std;

struct Element{
    string      language;
    Element     *next,*previous;
};
typedef struct Element Element;

struct Queue{
    int         access_element;
    Element     *front,*rear;
};
typedef struct Queue Queue;

//declare class do Algorithm
class algorithm_part{
public:
    Queue       *createQueue();         //create the queue
    void        beQueue(Queue *queueList, string newLanguage);       //insert queue to use in end queue
    void        enQueue(Queue *queueList, string newLanguage);
    void        deQueue(Queue *queueList);
    void        displayQueue(Queue *queueList);
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
    static int  callback(void* data,int init_string,char** column_data,char** colName){
        database_part database;
        fprintf(stderr, "%s\n",(const char*)data );                     //convert those data as string


        for (int i = 0; i < init_string; i++) {
            if (i == 1) {
                database.splitSentence((string)column_data[i]);                     //check the column to take a column data
            }
        }
        printf("\n" );
        return 0;
    }
    void        splitSentence(string splitString);

    void        createDatabase();
    void        insertDatabase(Queue *queueList);
    void        selectDatbase(Queue *queueList,string initString);
private:
    sqlite3     *db;
    char        exit=0;
    char        hey=0;
    char        *message;
};

//part algorithm
//create queue
Queue* algorithm_part::createQueue(){
    Queue *queueList;
    queueList = new Queue();
    queueList->front = NULL;
    queueList->rear = NULL;
    return queueList;
}

//add begin
void algorithm_part::beQueue(Queue *queueList, string newLanguage){
    Element *newElement;
    newElement = new Element();

    newElement->language = newLanguage;
    newElement->previous = NULL;                            //previous of new element no need to point to anything for first time
    newElement->next = queueList->front;                   //set next as front

    if (queueList->access_element == 0)
        queueList->rear = newElement;                      //check if no data set rear to has those data
    if (queueList->access_element != 0)
        queueList->front->previous = newElement;          //check if bigger then 0 or opposite than 0 set previous of front has data

    queueList->front = newElement;                        //set front point to new element so data will set there
    queueList->access_element++;
}

//add enQueue
void algorithm_part::enQueue(Queue *queueList, string newLanguage){
    Element *newElement;

    if (queueList->access_element == 0) {
        beQueue(queueList, newLanguage);
    }else{
        newElement = new Element();
        newElement->language = newLanguage;
        newElement->next = NULL;
        newElement->previous = queueList->rear;
        queueList->rear->next = newElement;
        queueList->rear = newElement;
        queueList->access_element++;
    }
}

//delete begin queueList
void algorithm_part::deQueue(Queue *queueList){
    Element *temporary;
    if (queueList == 0) {
        cout<<"You cant delete\n";
    }else{
        temporary = queueList->front;
        queueList->front = queueList->front->next;
        if (queueList->access_element >= 2)
            queueList->front->previous = NULL;
        delete temporary;
        if (queueList->access_element == 1)
            queueList->rear = NULL;
        queueList->access_element--;
    }
}

//show the result
void algorithm_part::displayQueue(Queue *queueList){
    Element *temporary;

    temporary = queueList->front;
    while (temporary != NULL) {
        cout<<temporary->language<<endl;
        temporary = temporary->next;
    }
}

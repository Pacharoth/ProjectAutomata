#include <iostream>
#include <sqlite3.h>
#include <cstring>
using namespace std;
//create link list
struct Element{
    string data;
    Element *next;
};
struct List{
    int n;
    Element *head;
    Element *tail;
};
//Create empty link list
List *createList();
//check begin link list
void createToBegin(List *ls,string data1);
//check endlinkList
void endOfList(List *ls,string data1);
//check language 
int checkHeadTail(List *ls,string data1);
void designMenu();

void chooseLanguage();

void inputLanguage();

int main(){
    //declare variable 
    int choice;

    while (1)
    {
        cout<<"\t\t\t=================================\n";
        cout<<"\t\t\t|Welcome to Automata Program -_-|\n";
        cout<<"\t\t\t=================================\n\n";
        designMenu();
        cout<<"Input your choice:";
        cin>>choice;
        if (choice==1)
        {
            chooseLanguage();
        }else if (choice==6)
        {
            cout<<"Exit the program\n\n";
            break;
        }
    }
}
//Menu Tell what to do
void designMenu(){
    cout<<"\t\t1.Input the strings.\n\n";
    cout<<"\t\t2.Check the strings(FA or DFA).\n\n";
    cout<<"\t\t3.Check strings accept by a FA or not.\n\n";
    cout<<"\t\t4.Construct an equivalent DFA from an NFA.\n\n";
    cout<<"\t\t5. Minimize a DFA.\n\n";
    cout<<"\t\t6. Exit the program.\n\n";
}
void chooseLanguage(){
    cout<<"1.Choose language below";
    cout<<"L={W|W={ab}^n} ,n>0\n";

}

//I want to try a language which ab start and ba end 
void inputLanguage(){
    
}
List *createList(){
    List *ls= new List;
    ls->n=0;
    ls->head =NULL;
    ls->tail=NULL;
    return ls;
}
void createToBegin(List *ls,string data1){
    Element *e=new Element;
    e->data = data1;
    e->next = ls->head;//next equal to head
    ls->head =e;//set head to value that is in next
    if (ls->n==0)
    {
        ls->tail=e;//empty data so tail has value null
    }
    ls->n++; //increment one
}
void endOfList(List *ls,string data1){
    Element *e=new Element;
    if (ls->n==0)
    {
        ls->head=NULL;
        createToBegin(ls,data1);
        ls->tail=NULL;
    }
        e->data = data1;
        e->next=NULL;
        ls->tail->next =e;
        ls->tail=e;
        ls->n++;
}

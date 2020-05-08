#include <iostream>
#include <sqlite3.h>
#include <cstring>
using namespace std;
struct Element{
    string data;
    Element *next;
};
struct List{
    int n;
    Element *front,*rear;
};
class algo_LinkList{
    public:
        //Checking queue()
        List *Queue();
        //create beQueue(begin)
        void beQueue(List *ls,string newData);
        //create enQueue(end)
        void enQueue(List *ls,string newData);
        //create deQueue(delete)
        void deQueue();
};
class mainMenu{
    public:
       void designMenu();//display the main Menu
       void chooseLanguage();// choose lannguage main Menu
};
//the processing in automata
class Automata{
    public:


};
//All load edit delete save to database
class Database{
    public:
        //create database
        void createDatabase();
        //insert to database
        void insertData(List *ls);
        //Load database
        void loadData();
    private:
        string sql;
        sqlite3 *db;
        char exit=0;
        char hey=0;
        char *message;
};
int main(){
    //declare variable
    int choice;
    string data;
    List *ls;
    algo_LinkList Link;
    ls=Link.Queue();
    mainMenu mainMenu;
    Database database;

    database.createDatabase();
    while (1)
    {

        cout<<"\t\t\t=================================\n";
        cout<<"\t\t\t|Welcome to Automata Program -_-|\n";
        cout<<"\t\t\t=================================\n\n";
        mainMenu.designMenu();
        cout<<"Input your choice:";
        cin>>choice;
        if (choice==1)
        {
            mainMenu.chooseLanguage();
            cout<<"Insert language:";
            cin>>data;
            Link.enQueue(ls,data);
        }
        else if (choice==2) {
          /* code */
        }
        else if (choice==6)
        {
            database.insertData(ls);
            cout<<"Exit the program\n\n";
            break;
        }
    }
}
//display main Menu
void mainMenu::designMenu(){
    cout<<"\t\t1.Input the strings.\n\n";
    cout<<"\t\t2.Check the strings(FA or DFA).\n\n";
    cout<<"\t\t3.Check strings accept by a FA or not.\n\n";
    cout<<"\t\t4.Construct an equivalent DFA from an NFA.\n\n";
    cout<<"\t\t5. Minimize a DFA.\n\n";
    cout<<"\t\t6. Exit the program.\n\n";
}
//choose the language menu in choice number 1
void mainMenu::chooseLanguage(){
    cout<<"1.Choose language below";
    cout<<"L={W|W={ab}^n} ,n>0\n";
}
//Check Queue empty
List* algo_LinkList::Queue(){
    List *ls;
    ls=new List();
    ls->n=0;
    ls->rear=ls->front=NULL;
    return ls;
}
void algo_LinkList::beQueue(List *ls,string newData){
    //declare variable
    Element *e;
    //create new Element
    e= new Element();
    e->data=newData;
    e->next =ls->front;
    ls->front=e;
    if (ls->n==0) {
        //set rear to NULL
        ls->rear=e;
    }
    ls->n++;
}
void algo_LinkList::enQueue(List *ls,string newData){
    //declare
    Element *e;
    if (ls->n==0) {
        //insert first to avoid from error
        beQueue(ls,newData);
    }else{
        //start new Element
        e= new Element();
        e->data=newData;
        e->next =NULL;
        //set next to null and set rear become data so rear has the next data
        ls->rear->next=e;
        ls->rear=e;
        ls->n++;
    }
}
void Database::createDatabase(){
    sql="create table Language("
        "lid integer primary key autoincrement,"
        "data char(100) not null unique);";
    //create database
    exit=sqlite3_open("automata.db",&db);
    //execute the query
    exit =sqlite3_exec(db,sql.c_str(),0,NULL,&message);
    //check if successful create or not
    if(hey!=SQLITE_OK){
        cout<<"Fail create database\n";
    }else{
        cout<<"Can create database\n";
    }
    if(exit!=SQLITE_OK){
        cout<<"Fail create Table\n";
    }else{
        cout<<"Successful create the table\n";
    }
    sqlite3_close(db);
}
void Database::insertData(List *ls){
    Element *tmp;
    tmp =ls->front;
    while(tmp!=NULL){
        sql="insert into Language(data) values('"+tmp->data+"');";
        tmp->next;
    }
    // sql="insert into Language(data) values('"+tmp->data+"');";
    exit=sqlite3_open("automata.db",&db);
    exit=sqlite3_exec(db,sql.c_str(),0,NULL,&message);
    if(exit!=SQLITE_OK){
        cout<<"Fail record\n";
    }else{
        cout<<"Successful record\n";
    }
    sqlite3_close(db);
}

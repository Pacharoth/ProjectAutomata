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
        List *Queue();//Checking queue()
        void beQueue(List *ls,string newData); //create beQueue(begin)
        void enQueue(List *ls,string newData);//create enQueue(end)
        void showQueue(List *ls);//show the queque
        void deQueue(List *ls);  //create deQueue(delete)
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
        void createDatabase();//create database
        void insertData(List *ls);//insert to database
        static int callback(void *data, int argc,char **argv,char** azColName){
          int i;
          fprintf(stderr, "%s:", (const char*)data );
          for ( i = 0; i < argc; i++) {
              printf("%s=%s\n",azColName[i],argv[i]?argv[i]:"NULL" );
          }
          printf("\n");
          return 0;
        }
        void loadData(List *ls,string data);//Load data from database into list
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
          Link.showQueue(ls);
        }
        else if (choice==3) {
          Link.deQueue(ls);
        }
        else if (choice==4) {
          database.loadData(ls,data);
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

//Algorithm
List* algo_LinkList::Queue(){
    List *ls;
    ls=new List();
    ls->n=0;
    ls->rear=NULL;
    ls->front=NULL;
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
    ls->n=ls->n+1;
}
void algo_LinkList::enQueue(List *ls,string newData){
    //declare
    Element *e;
    if (ls->n==0) {
        //insert first to avoid from error
        beQueue(ls,newData);
    }else{
        e= new Element();//start new Element
        e->data=newData;
        e->next =NULL;
        //set next to null and set rear become data so rear has the next data
        ls->rear->next=e;
        ls->rear=e;
        ls->n=ls->n+1;

    }
}
void algo_LinkList::deQueue(List *ls){
    Element *tmp;
    if (ls->n==0) {
        cout<<"You cant delete\n\n";
    }
    else{
        tmp=ls->front;
        ls->front=ls->front->next;
        delete tmp;
        if (ls->n==0) {
            ls->rear=NULL;
        }
        ls->n=ls->n-1;
        cout<<"Successful Delete\n\n";
    }
}

//Database
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
    Element *tmp,*tmp1;
    tmp =ls->front;
    exit=sqlite3_open("automata.db",&db);
    while (tmp!=NULL) {
        sql="insert into Language(data) values('"+tmp->data+"');";
        tmp=tmp->next;
        exit=sqlite3_exec(db,sql.c_str(),0,NULL,&message);
    }
    if(exit!=SQLITE_OK){
        cout<<"Fail record\n";
    }else{
        cout<<"Successful record\n";
    }
    sqlite3_close(db);
}
void algo_LinkList::showQueue(List *ls){
    Element *tmp;
    tmp=ls->front;
    if (ls->n==0) {
        cout<<"No Language\n";
    }
    while (tmp !=NULL) {
        cout<<" "<<tmp->data<<endl;
        tmp=tmp->next;
    }
    cout<<"\n";
}
void Database::loadData(List *ls,string data){
    sql="select * from Language;";
    exit =sqlite3_open("automata.db",&db);
    exit=sqlite3_exec(db,sql.c_str(),callback,(void *)data.c_str(),NULL);

}

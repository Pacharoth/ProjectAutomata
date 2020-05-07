#include <iostream>
#include <sqlite3.h>
#include <cstring>
using namespace std;
struct Element{
    string data;
    Element *next;
    Element *tail;
};
struct List{
    int n;
    Element *head;
    Element *tail;
};
//create List
 List* createList(){
    List *ls;
    ls=new List();
    ls->n=0;
    ls->head=NULL;
    ls->tail=NULL;
    return ls;
}
class mainMenu{
    public:
       void designMenu();//display the main Menu
       void chooseLanguage();// choose lannguage main Menu
};
//the processing in automata
class Automata{
    public:


};
class Database{
    public:
        void insertData(ls);

    private:
        sqlite3 *db;
        char exit=0;
        char *message;
        string sql;
};
int main(){
    //declare variable 
    int choice;
    string data;
    mainMenu mainMenu;
    Database database;

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
        }
        else if (choice==6)
        {
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
void Database::insertData(ls){
    
}
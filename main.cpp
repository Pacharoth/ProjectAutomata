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
    Element *head;
    Element *tail;
};
class mainMenu{
    public:
       void designMenu();
       void chooseLanguage();
};
class Database{
    
};
int main(){
    //declare variable 
    int choice;
    mainMenu mainMenu;
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
        }else if (choice==6)
        {
            cout<<"Exit the program\n\n";
            break;
        }
    }
}
void mainMenu::designMenu(){
    cout<<"\t\t1.Input the strings.\n\n";
    cout<<"\t\t2.Check the strings(FA or DFA).\n\n";
    cout<<"\t\t3.Check strings accept by a FA or not.\n\n";
    cout<<"\t\t4.Construct an equivalent DFA from an NFA.\n\n";
    cout<<"\t\t5. Minimize a DFA.\n\n";
    cout<<"\t\t6. Exit the program.\n\n";
}
void mainMenu::chooseLanguage(){
    cout<<"1.Choose language below";
    cout<<"L={W|W={ab}^n} ,n>0\n";

}

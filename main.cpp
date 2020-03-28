#include <iostream>
#include <sqlite3.h>
#include <cstring>
using namespace std;
void designMenu();

void chooseLanguage();
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

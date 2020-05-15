#include"Processing.hpp"

int main(){
    Queue *q;
    stack *s;
    s=algo.createStack();
    q=algo.createQueue();
    algo.beQueue(q,1);
    algo.enQueue(q,2);
    algo.displayQueue(q);
    algo.push(s,"Hello");
    algo.push(s,"World");
    algo.push(s,"World");
    algo.push(s,"World");
    algo.pop(s);
    algo.displayStack(s);

}

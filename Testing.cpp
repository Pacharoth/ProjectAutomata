#include"ProcessingCode.hpp"

int main(int argc, char const *argv[]) {
    algorithm_part algorithm;
    Queue *queueList;

    queueList = algorithm.createQueue();
    algorithm.beQueue(queueList,"hello");
    algorithm.enQueue(queueList,"hello1");
    algorithm.displayQueue(queueList);
    algorithm.deQueue(queueList);
    algorithm.displayQueue(queueList);
    
    return 0;
}

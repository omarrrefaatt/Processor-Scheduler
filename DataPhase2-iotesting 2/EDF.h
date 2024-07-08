#pragma once
#include "Processor.h"
#include "Process.h"
#include "LinkedList.h"
#include "Queue.h"
#include "PrioQueue.h"
class EDF : public Processor {
private:
    PriorityQueue<Process*> Readylist;
public:
    EDF();
    void ScheduleAlgo();
    void AddProcessRd(Process*);
    bool isEmpty();
    void printRDY();
    Queue<Process*> getmigration();
    int getnready() ;

};

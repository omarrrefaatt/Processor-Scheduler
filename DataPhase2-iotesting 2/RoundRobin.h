#pragma once
#include "Processor.h"
#include "Process.h"
#include "Queue.h"
class RoundRobin :public Processor {
private:
    Queue<Process*> ReadyList;
    bool status;
    int timeslice;
    int timesum;
    Queue<Process*> tosjf;
    int RTF;
public:
    RoundRobin(int r);
    void settimeslice(int t);
    virtual void ScheduleAlgo();
    void AddProcessRd(Process* p);
    void AddProcessRn(Process* p);
    Queue<Process*> getmigration();
    int getnready();
    void printRDY();
    bool virtual isEmpty();
};

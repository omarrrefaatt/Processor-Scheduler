#include "EDF.h"
EDF::EDF() {
    Type = "EDF";
}
void EDF::ScheduleAlgo() {
    if (Readylist.isEmpty())
        return;
    if (Run == nullptr) {
        Run = Readylist.dequeue();
        return;
    }
    Readylist.enqueue(Run, Run->getdeadline());
    Run = Readylist.dequeue();
}
void EDF::AddProcessRd(Process* p) {
    Readylist.enqueue(p, p->getdeadline());
    FinishTime += p->getcpu_time();
}
bool EDF::isEmpty()
{
    if (Readylist.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int EDF::getnready() {
    return Readylist.getCount();
}
void EDF::printRDY() {
    Readylist.printQueue();
}
Queue<Process*> EDF::getmigration() {
    Queue<Process*> p;
    return p;
}
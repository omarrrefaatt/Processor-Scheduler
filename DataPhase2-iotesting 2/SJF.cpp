#include "SJF.h"

SJF::SJF()
{
    status = true;
    Type = "SJF";
    FinishTime = 0;
}
void SJF::ScheduleAlgo()
{

    if (Run == nullptr && !ReadyList.isEmpty()) {
        Process*p=ReadyList.dequeue();
        Run = p;
    }
   
}

Queue<Process*> SJF::getmigration() {
    Queue<Process*> p;
    return p;
}


void SJF::AddProcessRd(Process* p)
{
	ReadyList.enqueue( p, p->getcpu_time());
    FinishTime += p->getcpu_time();
}

void SJF::AddProcessRn(Process* p)
{
	Run = p;
    Rd = false;
}
int SJF::getnready() {
    return ReadyList.getCount();
}

bool SJF::isEmpty()
{
    if (ReadyList.isEmpty())
    {
        return true;
    }
    else return false;
}

void SJF::printRDY() {
  
    ReadyList.printQueue();
}
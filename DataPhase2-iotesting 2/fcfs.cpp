#include "FCFS.h"
FCFS::FCFS(int m)
{
    Run=nullptr ;
    status = true;
    Type = "FCFS";
    FinishTime = 0;
    MAXW = m;
}
void FCFS::ScheduleAlgo()
{
    toRR.deletequeue();
    while (Run == nullptr && ReadyList.count() != 0) {
        Process* scheduledProcess = ReadyList.getFront();
        ReadyList.DeleteFirst();
        if ((timestep - scheduledProcess->getarrival_time()) > MAXW && !scheduledProcess->getforked())
            toRR.enqueue(scheduledProcess);
        else
            Run = scheduledProcess;
    }
    
}
bool FCFS::isEmpty()
{
    if (ReadyList.isempty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void FCFS::AddProcessRd(Process* p)
{
	ReadyList.InsertEnd(p);
    FinishTime += p->getcpu_time();
    Rd = true;
}

void FCFS::AddProcessRn(Process* p)
{
	Run = p;
}
Process* FCFS::kill(int id) {
    if (ReadyList.count() == 0 && Run == nullptr)
        return nullptr;
    if (Run != nullptr) {
        if (Run->getprocess_id() == id) {
            Process* P = Run;
            removerun();
            if (ReadyList.count() != 0) {
                Run = ReadyList.getFront();
                ReadyList.DeleteFirst();
            }

            return P;
        }
    }
    if (ReadyList.isempty()) {
        return nullptr;
    }
    Node<Process*>* temp = ReadyList.gethead();
    while (temp) {
        if (temp->getItem()->getprocess_id() == id) {
            cout << "top";
            Process* p = temp->getItem();
            ReadyList.DeleteNode(temp->getItem());
            return p;
        }
        temp = temp->getNext();
    }
    return nullptr;
}
int FCFS::getnready() {
    return ReadyList.count();
}

Queue<Process*> FCFS::getmigration() {

    return toRR;
}
void FCFS::printRDY() {
    ReadyList.PrintList();
   
}



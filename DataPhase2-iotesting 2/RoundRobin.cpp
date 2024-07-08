
#include "RoundRobin.h"

RoundRobin::RoundRobin(int n)
{
	status = true;
    RTF = n;
	Type = "RoundRobin";
	FinishTime = 0;
}
void RoundRobin::settimeslice(int t) {
	timeslice = t;

}

void RoundRobin::ScheduleAlgo()
{
        if (Run == nullptr && ReadyList.isEmpty())
            return;
        if (Run == nullptr && !ReadyList.isEmpty()) {
            Process* scheduledProcess = ReadyList.dequeue();
            Run = scheduledProcess;
        }
        tosjf.deletequeue();
        if (Run->gettimeRobin() >= Run->gettimeslice() && !ReadyList.isEmpty()){
            Run->setRobin(0);
            ReadyList.enqueue(Run);
            Run = nullptr;
            while (Run == nullptr && !ReadyList.isEmpty()) {
                if (ReadyList.peek()->getRemainingtime() < RTF && !ReadyList.peek()->getforked()) {
                    Process* scheduledProcess = ReadyList.dequeue();
                    tosjf.enqueue(scheduledProcess);
                    cout << endl;
                }
                else {
                    Process* scheduledProcess = ReadyList.dequeue();
                    Run = scheduledProcess;
                }
            }
        }
        Run->setRobin(Run->gettimeRobin() + 1);
    }

bool RoundRobin::isEmpty()
{
    if (ReadyList.isEmpty())
    {
        return true;
    }
    else return false;
}
Queue<Process*> RoundRobin::getmigration() {
    return tosjf;
}


    

void RoundRobin::AddProcessRd(Process* p)
{
	ReadyList.enqueue(p);
	FinishTime += p->getcpu_time();
	Rd = false;
}

void RoundRobin::AddProcessRn(Process* p)
{
	Run = p;
}


void RoundRobin::printRDY() {

	ReadyList.printQueue();
	}
int RoundRobin::getnready() {
    return ReadyList.getCount();
}




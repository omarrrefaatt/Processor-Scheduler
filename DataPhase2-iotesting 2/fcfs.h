#pragma once
#include "Processor.h"
#include "Process.h"
#include "LinkedList.h"
#include "Queue.h"
#include "PrioQueue.h"

class FCFS : public Processor
{
private:
	LinkedList<Process*> ReadyList;
	bool status;
	Queue<Process*> toRR;
	int MAXW;
public:
	FCFS(int m);
    virtual void ScheduleAlgo();
	void AddProcessRd(Process* p);
	void AddProcessRn(Process* p);
	Process* kill(int id);
	Queue<Process*> getmigration();
    int getnready();
	void printRDY();
	bool virtual isEmpty();

};
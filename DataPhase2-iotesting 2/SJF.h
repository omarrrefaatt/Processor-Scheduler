#pragma once
#include "Processor.h"
#include "PrioQueue.h"


class SJF :public Processor
{
private:
	PriorityQueue<Process*> ReadyList;
	int priority;
public:
	SJF();
	virtual void ScheduleAlgo();
	void AddProcessRd(Process* p);
	void AddProcessRn(Process* p);
    int getnready();
	Queue<Process*> getmigration();
	void printRDY();
	bool virtual isEmpty();
};

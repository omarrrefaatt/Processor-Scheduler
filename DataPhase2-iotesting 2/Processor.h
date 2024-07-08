#pragma once
#include "LinkedList.h"
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "Process.h"

class Processor
{
protected:
	int timestep;
	int busytime;
	bool status;
	bool Rd;
	bool Busy;
	bool Idle;
	int FinishTime;
	Process* Run;
	Process* BacktoRdy=nullptr;
	string Type;
public:
	Processor();
	void virtual AddProcessRd(Process* P) = 0;
	virtual void ScheduleAlgo() = 0;
	virtual Queue<Process*> getmigration() = 0;
	void SetStatus(bool s);
	bool GetStatus();
	bool Empty();
	void setimestep(int n);
	bool virtual isEmpty() = 0;
	void virtual setBusy(bool s);
	bool virtual getBusy();
    virtual int getnready()=0;
	void virtual setIdle(bool s);
	bool virtual getIdle();
	int virtual PLoad();
	int virtual PUtil();
	string return_Type();
    Process* getRun();
	void setBacktoRdy(Process *P);
	virtual Process* kill(int id);
	Process* getBacktoRdy();
	void virtual printRDY() = 0;
	int getfinishtime();
	void setFinishtime(int n);
	void removerun();
};
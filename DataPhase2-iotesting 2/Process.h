#pragma once
#include <iostream>
using namespace std;
#include "Queue.h"
class Process
{
private:
	int process_id;
	int Noio;
	float arrival_time;
	float response_time;
	float cpu_time;
	int  timeinRobin;
	int Remainingtime;
	float termination_time;
	float turnaround_time;
	float waiting_time;
	int timeslice;
	float randFP;
	int deadline;		
	Process* child;
    int  Nready;
	bool blocked=false;
	Queue<int> ioR;
	Queue<int> ioD;
	bool forked=false;

public:
	bool getblocked();
	void setblocked(bool b);
	Process();
	Process* getchild();
	bool getforked();
	void setforked(bool t);
	void addchild(Process* c);

	void printio();
	void setNoio(int n);
	int getNoio();
	bool getio(int c);
	void addIo(int n, char c);
	int getprocess_id()const;
	int getarrival_time() const;
	float getresponse_time() const;
	float getwaiting_time() const;
	float getturnaround_time() const;
	float getcpu_time() const;
	float gettermination_time()const;
	int getdeadline();
	void setdeadline(int t);

	float getFP();
	void nextio();
	int  io_finish();
	void setFP(float f);
	void setwaiting_time(float time);
	void setturnaround_time(float time);
	void setprocess_id(int id);
	void setarrival_time(float time);
	void setresponse_time(float time);
	void setcpu_time(float time);
	void settermination_time(float time);
	int getRemainingtime();
	void decRemtime();
	void settimeslice(int t);
	int gettimeRobin();
	void setRobin(int);
	int gettimeslice();
	friend ostream& operator<<(ostream& output, Process P) {
		output << " " << P.getprocess_id() << ", ";
		return output;
	}
};
#pragma once
#include <iostream>
#include "Queue.h"
#include "PrioQueue.h"
#include "Process.h"
#include "Processor.h"
using namespace std;

class ui {
public:
	ui() {

	}
	void print(Processor* p[], int numprocessor, Queue<Process*> &blk, Queue<Process*> &trm, int timestep);
};
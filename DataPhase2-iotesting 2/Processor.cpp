#include "Processor.h"


Processor::Processor()
{
	status = true;
	Rd = false;
	FinishTime = 0;
	Run = nullptr;
}
bool Processor::Empty() {
	return Rd;
}

void Processor::removerun() {
	Run = nullptr;
}

void Processor::SetStatus(bool s)
{
	status = s;  //TRUE=IDLE FALSE=BUSY
}
string Processor::return_Type() {
	return Type;
}

int Processor::getfinishtime()
{

	return FinishTime;
}

void Processor::setBusy(bool s)
{
	Busy = s;
}

bool Processor::getBusy()
{
	return Busy;
}



void Processor::setIdle(bool s)
{
	Idle = s;
}

bool Processor::getIdle()
{
	return Idle;
}

void Processor::setFinishtime(int n)
{
	FinishTime = n;
}

bool Processor::GetStatus()
{
	return status;
}
Process* Processor::getRun()
{
	return Run;
}
void Processor::setimestep(int t) {
	timestep = t;
}

void Processor::setBacktoRdy(Process*P)
{
	BacktoRdy = P;
}

Process* Processor::getBacktoRdy()
{
	return BacktoRdy;
}



int Processor::PLoad()
{
	return busytime;
}



int Processor::PUtil()
{
	return busytime;
}

Process* Processor::kill(int id) {
	return nullptr;
}
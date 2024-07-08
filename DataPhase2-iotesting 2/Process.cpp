#include "Process.h"


void Process::addIo(int n, char c)
{
    if (c == 'r')
        ioR.enqueue(n);
    else {
        ioD.enqueue(n);

    }
}
bool Process::getblocked()
{
    return blocked;
}
void Process::setblocked(bool b)
{
    blocked = b;
}
Process::Process() {
    Remainingtime = cpu_time;
    timeinRobin=0;
}
Process* Process::getchild() {
    return child;
}
bool Process::getforked()
{
    return forked;
}
void Process::setforked(bool t)
{
    forked = t;
}
void Process::addchild(Process* c)
{
    child = c;
}

void Process::printio() {
   
   
}
void Process::setNoio(int n)
{
    Noio = n;
}
int Process::getNoio() {
    return Noio;
}
bool Process::getio(int t) {
    while(ioR.peek()<t){
       nextio();
        if(Noio==0)
            return false;
    }
        if(ioR.peek()==t)
            return true;
       else
            return false;

}

int Process::getprocess_id()const {
    return process_id;
}
int Process::getarrival_time() const {
    return arrival_time;
}
float Process::getcpu_time() const {
    return cpu_time;
}
float Process::gettermination_time()const {
    return termination_time;
}
int Process::getdeadline()
{
    return deadline;
}
float Process::getwaiting_time() const {
    return waiting_time;
}
int Process::io_finish() {
    return (ioR.peek() + ioD.peek());
}
float Process::getturnaround_time() const {
    return turnaround_time;
}

float Process::getresponse_time() const {
    return response_time;
}
void Process::nextio() {
    ioR.dequeue();
    ioD.dequeue();
    Noio--;
}
void Process::setprocess_id(int id) {
    process_id = id;
}
void Process::setarrival_time(float time) {
    arrival_time = time;
}
void Process::setresponse_time(float time) {
    response_time = time;
}
void Process::setcpu_time(float time) {
    cpu_time = time;
    Remainingtime = time;

}
void Process::settermination_time(float time) {
    termination_time = time;
}
void Process::setwaiting_time(float time) {
    waiting_time = turnaround_time-cpu_time;
}
void Process::setturnaround_time(float time) {
    turnaround_time = termination_time - arrival_time;
}

int Process::getRemainingtime() {
    return Remainingtime;
}
void Process::decRemtime()
{
    Remainingtime--;
}
int Process::gettimeRobin() {
    return timeinRobin;
}
void Process::settimeslice(int t){
    timeslice = t;
}
void Process::setRobin(int x) {
    
    timeinRobin = x;
}
int Process::gettimeslice() {
    return timeslice;
}

void Process::setFP(float f)
{
    randFP = f;
}

float Process::getFP()
{
    return randFP;
}
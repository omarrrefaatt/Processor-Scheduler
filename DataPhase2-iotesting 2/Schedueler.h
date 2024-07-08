

#include "LinkedList.h"
#include "Queue.h"
#include "SJF.h"
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RoundRobin.h"
#include "Processor.h"
#include "UI.h"
#include "kill.h"
#include "EDF.h"

class Schedueler
{
private:

    Queue<Process*> newlist;
    Queue<Process*> ReturnRobin;
    Queue<Process*> Blk;
    Queue<Process*> TRM;
    Process* orph;
    int timestep ;
    int NF, NS, NR,NE;
    int M;
    int forkprob;
    int n;
    FCFS* arrF;
    SJF* arrS;
    RoundRobin* arrR;
    Processor** arrP;
    Queue<kill*> killsignals;
    char x;
    int countfp = 0;

public:
    Schedueler();
    void load();
    void kill();
    void  migrate(Queue<Process*>& p, int c);
    void NEWRDY(Queue<Process*> &L);
    void GenerateFP();
    void Io();
    void shortestFcfs(Process* p);
    void terminate();
    void orphan(Process* p);
    void simulate();
};

#include "Schedueler.h"
#include "UI.h"
#include <iostream>
#include <fstream>

using namespace std;

Schedueler::Schedueler()
{
	timestep = 0;
	x = 'y';

}


void Schedueler::load()
{
	ifstream fin("/Users/omarrrefaat/Desktop/DataPhase2-iotesting 2/DataPhase2-iotesting 2/test3.txt");
	
		if (fin.fail())
		{
			std::cout << "Error opening input file\n";
		}


	// read number of processors for each scheduling algorithm
	fin >> NF >> NS >> NR>>NE;




	// read time slice for RR scheduling
	int time_slice;
	fin >> time_slice;

	// read RTF, Max, STL, and fork probability
	int RTF, Max, STL;

	fin >> RTF >> Max >> STL >> forkprob;

	// read number of processes

	fin >> M;


	int* arrival_times = new int[M];
	int* process_id = new int[M];
	int* cpu_time = new int[M];
	int* deadlines = new int[M];
	int* N = new int[M];
	int* killtimes = new int[M];
	int* IdKs = new int[M];
	int** io_times = new int* [M];




	for (int i = 0; i < M; i++) {
		fin >> arrival_times[i] >> process_id[i] >> cpu_time[i] >> deadlines[i] >> N[i];

		io_times[i] = new int[N[i] * 2];
		for (int j = 0; j < N[i] * 2; j += 2) {
			char c;
			fin >> c;
			fin >> io_times[i][j] >> c >> io_times[i][j + 1];
			fin >> c;
		}
	}

	string line;
	int killtime;
	int killid;
	while (!fin.eof()) {
		fin >> killtime >> killid;
		class  kill* k = new class kill;
		k->setpid(killid);
		k->setkilltime(killtime);
		killsignals.enqueue(k);
	}
	fin.close();
	//creating the processors
	arrP = new Processor * [NF + NS + NR+NE];
	for (int i = 0; i < NF; i++) {
		FCFS* F = new FCFS(Max); // Dynamically allocate FCFS object
		arrP[i] = F; // Store the pointer to the allocated object
	}

	for (int i = NF; i < NS + NF; i++) {
		SJF* S = new SJF(); // Dynamically allocate SJF object
		arrP[i] = S; // Store the pointer to the allocated object
	}
	for (int i = NS + NF; i < NR + NS + NF; i++) {
		RoundRobin* R = new RoundRobin(RTF); // Dynamically allocate RoundRobin object
		arrP[i] = R; // Store the pointer to the allocated object
	}
	for (int i = NR + NS + NF; i < NR + NS + NF + NE; i++) {
		EDF* E = new EDF(); // Dynamically allocate EDF object
		arrP[i] = E;
	}




	for (int i = 0; i < M; i++)
	{

		Process* p = new Process;

		p->setarrival_time(arrival_times[i]);
		p->setprocess_id(process_id[i]);
		p->setcpu_time(cpu_time[i]);
		p->setNoio(N[i]);
		p->settimeslice(time_slice);

		for (int j = 0; j < N[i] * 2; j += 2) {

			p->addIo(io_times[i][j], 'r');
			p->addIo(io_times[i][j + 1], 'd');
		}

		newlist.enqueue(p);

	}


	delete[] arrival_times;
	delete[] process_id;
	delete[] cpu_time;

	for (int i = 0; i < M; i++)
	{
		delete[] io_times[i];
	}

	delete[] io_times;
	delete[] killtimes;
	delete[] IdKs;

}
void Schedueler::NEWRDY(Queue<Process*>& L) {
	//NEW TO READY OF SHORTEST RDY QUEUE
	int iLeast = 0;
	while (!L.isEmpty() && L.peek()->getarrival_time() <= timestep) {
		int c = 10000000;
		int i = 0;
		for (i; i < NF + NS + NR+NE; i++) {
			if (arrP[i]->getfinishtime() < c) {
				c = arrP[i]->getfinishtime();
				iLeast = i;
			}
		}
		Process* P = L.dequeue();
		arrP[iLeast]->AddProcessRd(P);
	}
}
void Schedueler::Io() {
	for (int i = 0; i < NF + NS + NR+NE; ++i) {
		if (arrP[i]->getRun() == nullptr) {
			continue;
		}
		if (arrP[i]->getRun()->getNoio() > 0) {
			if (arrP[i]->getRun()->getio(timestep)) {
				Process* p = arrP[i]->getRun();
				arrP[i]->getRun()->setblocked(true);
				Blk.enqueue(p);
				arrP[i]->removerun();
			}
		}
	}
	int count = 0;
	int blkc = Blk.getCount();
	Process* p;
	Queue<Process*> io_queue;
	while (count != blkc) {
		p = Blk.dequeue();
		if (p->io_finish() == timestep) {
			p->setblocked(false);
			io_queue.enqueue(p);
			p->nextio();
		}
		else {
			Blk.enqueue(p);
		}
		count++;
	}
	NEWRDY(io_queue);
}
void Schedueler::shortestFcfs(Process* p) {
	//NEW TO READY OF SHORTEST RDY QUEUE
	int iLeast = 0;
		int c = 10000000;
		int i = 0;
		for (i; i < NF ; i++) {
			if (arrP[i]->getfinishtime() < c) {
				c = arrP[i]->getfinishtime();
				iLeast = i;
			}
		}
		arrP[iLeast]->AddProcessRd(p);
	}

void Schedueler::migrate(Queue<Process*>& p, int n) {
	if (p.isEmpty())
		return;
	if (n == 1) {
        if(NS==0){
            NEWRDY(p);
            return;
        }
		int iLeast = 0;
		while (!p.isEmpty()) {
			int c = 10000000;
			for (int i = NF; i < NF + NS; i++) {
				if (arrP[i]->getfinishtime() < c) {
					c = arrP[i]->getfinishtime();
					iLeast = i;
				}
			}
			arrP[iLeast]->AddProcessRd(p.dequeue());
		}
	}
	else if (n == 2) {
        if(NR==0){
            NEWRDY(p);
            return;
        }
		int iLeast = 0;
		while (!p.isEmpty()) {
			int min = 10000000;
			for (int i = NS + NF; i < NR + NS + NF; i++) {
				if (arrP[i]->getfinishtime() < min) {
					min = arrP[i]->getfinishtime();
					iLeast = i;
				}
			}
			Process* P = p.dequeue();
			arrP[iLeast]->AddProcessRd(P);
		}
	}

}


void Schedueler::GenerateFP()
{
	srand(time(0));
	int j = 0;
	float x;
	arrP[j]->setBusy(true);

	for (int i = 0; i < NF; i++)
	{
		x = rand() % 100;
		if (arrP[i]->getRun()) {
			if (!arrP[i]->getRun()->getforked() && x <= forkprob) {

				arrP[i]->getRun()->setforked(true);
		
				
				cout << "Random number is " << x << endl;
				if (arrP[i]->getRun()->getprocess_id() == 44) {
					cout << "Grandchild created";
				}
				cout << "Process forked Id= " << arrP[i]->getRun()->getprocess_id() << endl;
				Process* child = new Process; 
				countfp++;
				M++;
				//Child Process Created
				child->setarrival_time(timestep);      // AT-child=timetsep ,Ct-child= rem time run
				child->setprocess_id(M);
				child->setcpu_time(arrP[i]->getRun()->getRemainingtime());
				arrP[i]->getRun()->addchild(child);
				shortestFcfs(child);
			}
		}
	}
}





void Schedueler::terminate() {
	for (int i = 0; i < NF + NS + NR+NE; ++i) {
		arrP[i]->setimestep(timestep);
		if (arrP[i]->getRun()) {
			if (arrP[i]->getRun()->getRemainingtime() == 1) {
				arrP[i]->getRun()->settermination_time(timestep);
				TRM.enqueue(arrP[i]->getRun());
				if (arrP[i]->getRun()->getforked()) { //orphan check
				orphan(arrP[i]->getRun()->getchild());
			}
				arrP[i]->removerun();
			}
			else {
				arrP[i]->getRun()->decRemtime();
			}

		}

	}
}
void Schedueler::orphan(Process* orph) {
	for (int i = 0; i < NF; i++) {
		Process* p = arrP[i]->kill(orph->getprocess_id());
		if (p != nullptr) {
			TRM.enqueue(p);
			break;
		}
	}

}
void Schedueler::kill() {
	if (killsignals.isEmpty())
        return;
		while (killsignals.peek()->getkilltime() == timestep) {
			int  id = killsignals.dequeue()->getpid();
			for (int i = 0; i < NF; i++) {
				Process* p = arrP[i]->kill(id);
				if (p != nullptr) {
					TRM.enqueue(p);
                    break;
				}
			}
			if (killsignals.getCount() == 0)
                return;

		}

}



void Schedueler::simulate()
{
    int mode;
    cout<<"plZ enter the mode"<<endl;
    cin>>mode;
	load();
	//update new
	while (TRM.getCount() != M) {
		for (int i = 0; i < NF + NS + NR+NE; i++)
		{
			arrP[i]->ScheduleAlgo();

		}
		NEWRDY(newlist);
		Io();
        for (int i = 0; i < NF + NS + NR; i++) {
            if (arrP[i]->getmigration().isEmpty())
                continue;
            Queue<Process*> p = arrP[i]->getmigration();
            if (i < NF)
                migrate(p, 2);
            else if (i >= NF + NS)
                migrate(p, 1);
        }
		GenerateFP();
		terminate();
		kill();
        ui u;
		u.print(arrP, NF + NS + NR + NE, Blk, TRM, timestep);
		timestep++;
        if(mode==1){
            cout<<"press enter for time step ("<<timestep<<")"<<endl;
            cin.ignore();
        }

	}
	

}


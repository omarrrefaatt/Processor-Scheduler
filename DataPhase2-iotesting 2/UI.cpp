#include "UI.h"
void ui::print(Processor* p[], int numprocessor, Queue<Process*> &blk, Queue<Process*> &trm, int timestep) {
    int c=0;
    cout << "current Timestep:" << timestep << endl;
    cout << "-----------------------------   RDY processes ____________________________" << endl;
    for (int i = 0; i < numprocessor; i++) {
        if(p[i]->getRun()){
            c++;
        }
        cout << "processor " << i + 1 << "  [" << p[i]->return_Type() << "]" << ": " <<"( "<<p[i]->getnready()<<" )"<< "RDY";
        p[i]->printRDY();
        cout << endl;
    }
 
    cout << "-----------------   RUN processes __________" << endl;
    cout <<"( "<<c<<" )"<< " RUN: ";
    for (int i = 0; i < numprocessor; ++i) {
        if (p[i]->getRun()) {
            cout << "Running is" << p[i]->getRun()->getprocess_id() << "(p" << i + 1 << "),  ";
        }
    }
    cout << endl;
    cout << "-----------------   BLK processes __________" << endl;
    cout <<"( "<<blk.getCount()<<" )" << " BLK: ";
    blk.printQueue();
    cout << endl;
    cout << "-----------------   TRM processes __________" << endl;
    cout <<"( "<<trm.getCount()<<" )" << " TRM: ";
    trm.printQueue();
    cout << endl;

}
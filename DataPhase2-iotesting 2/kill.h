#pragma once
#include <iostream>
using namespace std;
class kill {
private:
    int processid;
    int killtime;
public:
    int getpid();
    void setpid(int p);
    int getkilltime();
    void setkilltime(int t);
    friend ostream& operator<<(ostream& output, kill k) {
        output << " " << k.getpid() << ", " << k.getkilltime() << endl;
        return output;
    }
};




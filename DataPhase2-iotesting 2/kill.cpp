#include "kill.h"
void kill::setkilltime(int t) {
    killtime = t;
}
int kill::getkilltime() {
    return killtime;
}
void kill::setpid(int p) {
    processid = p;
}
int kill::getpid() {
    return processid;
}
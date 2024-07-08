cmake_minimum_required(VERSION 3.23)
project(DataPhase2_iotesting_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DataPhase2_iotesting_2
        fcfs.cpp
        fcfs.h
        LinkedList.h
        Main.cpp
        Node.h
        PrioQueue.h
        PrioQueueNode.h
        Process.cpp
        Process.h
        Processor.cpp
        Processor.h
        Queue.h
        RoundRobin.cpp
        RoundRobin.h
        Schedueler.cpp
        Schedueler.h
        SJF.cpp
        SJF.h
        Stack.cpp
        Stack.h
        UI.cpp
        UI.h)

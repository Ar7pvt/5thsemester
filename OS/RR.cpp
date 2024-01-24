#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Process {
public:
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int priority;

    Process(int pid, int at, int bt, int pr) {
        processID = pid;
        arrivalTime = at;
        burstTime = bt;
        remainingTime = bt;
        priority = pr;
        completionTime = 0;
        turnaroundTime = 0;
    }
};

class CPU_Scheduler {
public:
    vector<Process> processes;
    int timeQuantum;

    void inputProcesses() {
        int n;
        cout << "Enter the number of processes: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int pid, at, bt;
            cout << "Enter details for Process " << i + 1 << ":\n";
            cout << "Arrival Time: ";
            cin >> at;
            cout << "Burst Time: ";
            cin >> bt;
            processes.push_back(Process(i + 1, at, bt, 0)); // Priority is not used in RR
        }

        cout << "Enter the time quantum for Round Robin: ";
        cin >> timeQuantum;
    }

    void roundRobin() {
        int currentTime = 0;
        queue<Process*> readyQueue;
        int remainingProcesses = processes.size();

        cout << "Round Robin Gantt Chart:\n";
        while (remainingProcesses > 0) {
            for (auto& process : processes) {
                if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                    readyQueue.push(&process);
                }
            }

            if (!readyQueue.empty()) {
                Process* currentProcess = readyQueue.front();
                readyQueue.pop();

                int executionTime = min(timeQuantum, currentProcess->remainingTime);
                currentProcess->remainingTime -= executionTime;
                currentTime += executionTime;

                if (currentProcess->remainingTime == 0) {
                    currentProcess->completionTime = currentTime;
                    currentProcess->turnaroundTime = currentTime - currentProcess->arrivalTime;
                    remainingProcesses--;
                }

                cout << "| P" << currentProcess->processID << " ";
            } else {
                cout << "| Idle ";
                currentTime++;
            }
        }

        cout << "|\n";
        printProcessDetails();
    }

    void printProcessDetails() {
        cout << "\nProcess\tCT\tTAT\n";
        for (const auto& process : processes) {
            cout << process.processID << "\t" << process.completionTime << "\t" << process.turnaroundTime << "\n";
        }
    }
};

int main() {
    CPU_Scheduler scheduler;

    scheduler.inputProcesses();
    scheduler.roundRobin();

    return 0;
}

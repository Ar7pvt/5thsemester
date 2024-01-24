#include <iostream>
#include <vector>
#include <algorithm>

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
            processes.push_back(Process(i + 1, at, bt, 0)); // Priority is not used in LRTF
        }
    }

    void longestRemainingTimeFirst() {
        int currentTime = 0;
        int remainingProcesses = processes.size();

        cout << "Longest Remaining Time First Gantt Chart:\n";
        while (remainingProcesses > 0) {
            auto it = max_element(processes.begin(), processes.end(),
                                  [currentTime](const Process& p1, const Process& p2) {
                                      return p1.remainingTime < p2.remainingTime && p1.arrivalTime <= currentTime;
                                  });

            if (it != processes.end()) {
                Process& currentProcess = *it;
                int executionTime = 1; // Preempt after 1 unit time
                currentProcess.remainingTime -= executionTime;
                currentTime += executionTime;

                if (currentProcess.remainingTime == 0) {
                    currentProcess.completionTime = currentTime;
                    currentProcess.turnaroundTime = currentTime - currentProcess.arrivalTime;
                    remainingProcesses--;
                }

                cout << "| P" << currentProcess.processID << " ";
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
    scheduler.longestRemainingTimeFirst();

    return 0;
}

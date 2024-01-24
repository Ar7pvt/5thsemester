#include <bits/stdc++.h>


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
            int pid, at, bt, pr;
            cout << "Enter details for Process " << i + 1 << ":\n";
            cout << "Arrival Time: ";
            cin >> at;
            cout << "Burst Time: ";
            cin >> bt;
            cout << "Priority: ";
            cin >> pr;
            processes.push_back(Process(i + 1, at, bt, pr));
        }
    }

    void roundRobin(int timeQuantum) {
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

    void shortestRemainingTimeFirst() {
        int currentTime = 0;
        int remainingProcesses = processes.size();

        cout << "Shortest Remaining Time First Gantt Chart:\n";
        while (remainingProcesses > 0) {
            Process* shortestJob = nullptr;
            int shortestTime = INT_MAX;

            for (auto& process : processes) {
                if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                    if (process.remainingTime < shortestTime) {
                        shortestJob = &process;
                        shortestTime = process.remainingTime;
                    }
                }
            }

            if (shortestJob != nullptr) {
                int executionTime = shortestJob->remainingTime;
                currentTime += executionTime;

                shortestJob->completionTime = currentTime;
                shortestJob->turnaroundTime = currentTime - shortestJob->arrivalTime;
                shortestJob->remainingTime = 0;

                remainingProcesses--;

                cout << "| P" << shortestJob->processID << " ";
            } else {
                cout << "| Idle ";
                currentTime++;
            }
        }

        cout << "|\n";
        printProcessDetails();
    }

    void longestRemainingTimeFirst() {
        int currentTime = 0;
        int remainingProcesses = processes.size();

        cout << "Longest Remaining Time First Gantt Chart:\n";
        while (remainingProcesses > 0) {
            Process* longestJob = nullptr;
            int longestTime = 0;

            for (auto& process : processes) {
                if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                    if (process.remainingTime > longestTime) {
                        longestJob = &process;
                        longestTime = process.remainingTime;
                    }
                }
            }

            if (longestJob != nullptr) {
                int executionTime = longestJob->remainingTime;
                currentTime += executionTime;

                longestJob->completionTime = currentTime;
                longestJob->turnaroundTime = currentTime - longestJob->arrivalTime;
                longestJob->remainingTime = 0;

                remainingProcesses--;

                cout << "| P" << longestJob->processID << " ";
            } else {
                cout << "| Idle ";
                currentTime++;
            }
        }

        cout << "|\n";
        printProcessDetails();
    }

    void priorityScheduling() {
        int currentTime = 0;
        int remainingProcesses = processes.size();

        cout << "Priority Scheduling Gantt Chart:\n";
        while (remainingProcesses > 0) {
            Process* highestPriorityJob = nullptr;
            int highestPriority = INT_MAX;

            for (auto& process : processes) {
                if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                    if (process.priority < highestPriority) {
                        highestPriorityJob = &process;
                        highestPriority = process.priority;
                    }
                }
            }

            if (highestPriorityJob != nullptr) {
                int executionTime = highestPriorityJob->remainingTime;
                currentTime += executionTime;

                highestPriorityJob->completionTime = currentTime;
                highestPriorityJob->turnaroundTime = currentTime - highestPriorityJob->arrivalTime;
                highestPriorityJob->remainingTime = 0;

                remainingProcesses--;

                cout << "| P" << highestPriorityJob->processID << " ";
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
    int timeQuantum;

    scheduler.inputProcesses();

    cout << "\nEnter Time Quantum for Round Robin Scheduling (Enter 0 for non-preemptive algorithms): ";
    cin >> timeQuantum;

    scheduler.roundRobin(timeQuantum);
    scheduler.shortestRemainingTimeFirst();
    scheduler.longestRemainingTimeFirst();
    scheduler.priorityScheduling();

    return 0;
}

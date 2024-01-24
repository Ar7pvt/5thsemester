#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Process {
public:
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;

    Process(int i, int at, int bt, int prio) {
        id = i;
        arrival_time = at;
        burst_time = bt;
        priority = prio;
        completion_time = 0;
        turnaround_time = 0;
    }
};

// Function to calculate Completion Time (CT) and Turnaround Time (TAT) for each process
void calculateTimes(vector<Process>& processes, vector<int>& completionTimes) {
    int currentTime = 0;

    for (int i = 0; i < processes.size(); ++i) {
        processes[i].completion_time = currentTime + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        completionTimes.push_back(processes[i].completion_time);
        currentTime = processes[i].completion_time;
    }
}

// Function to display Gantt chart
void displayGanttChart(vector<Process>& processes, vector<int>& completionTimes) {
    cout << "Gantt Chart:\n";
    cout << "|";
    for (int i = 0; i < processes.size(); ++i) {
        cout << " P" << processes[i].id << " |";
    }
    cout << "\n";

    for (int i = 0; i < processes.size(); ++i) {
        cout << completionTimes[i] << "\t";
    }
    cout << completionTimes[completionTimes.size() - 1] << "\n";
}

// Function to implement FCFS scheduling algorithm
void fcfs(vector<Process>& processes) {
    vector<int> completionTimes;
    calculateTimes(processes, completionTimes);

    // Display CT, TAT, and Gantt Chart
    cout << "\nFCFS Scheduling:\n";
    for (int i = 0; i < processes.size(); ++i) {
        cout << "Process " << processes[i].id << ": CT=" << processes[i].completion_time
             << ", TAT=" << processes[i].turnaround_time << "\n";
    }

    displayGanttChart(processes, completionTimes);
}

// Function to implement SJF scheduling algorithm
void sjf(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burst_time < b.burst_time;
    });

    vector<int> completionTimes;
    calculateTimes(processes, completionTimes);

    // Display CT, TAT, and Gantt Chart
    cout << "\nSJF Scheduling:\n";
    for (int i = 0; i < processes.size(); ++i) {
        cout << "Process " << processes[i].id << ": CT=" << processes[i].completion_time
             << ", TAT=" << processes[i].turnaround_time << "\n";
    }

    displayGanttChart(processes, completionTimes);
}

// Function to implement LJF scheduling algorithm
void ljf(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burst_time > b.burst_time;
    });

    vector<int> completionTimes;
    calculateTimes(processes, completionTimes);

    // Display CT, TAT, and Gantt Chart
    cout << "\nLJF Scheduling:\n";
    for (int i = 0; i < processes.size(); ++i) {
        cout << "Process " << processes[i].id << ": CT=" << processes[i].completion_time
             << ", TAT=" << processes[i].turnaround_time << "\n";
    }

    displayGanttChart(processes, completionTimes);
}

// Function to implement Priority-based scheduling algorithm
void priorityScheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority < b.priority;
    });

    vector<int> completionTimes;
    calculateTimes(processes, completionTimes);

    // Display CT, TAT, and Gantt Chart
    cout << "\nPriority-based Scheduling:\n";
    for (int i = 0; i < processes.size(); ++i) {
        cout << "Process " << processes[i].id << ": CT=" << processes[i].completion_time
             << ", TAT=" << processes[i].turnaround_time << "\n";
    }

    displayGanttChart(processes, completionTimes);
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; ++i) {
        int at, bt, prio;
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> at >> bt >> prio;
        processes.push_back(Process(i + 1, at, bt, prio));
    }

    fcfs(processes); // First Come First Serve
    sjf(processes);  // Shortest Job First
    ljf(processes);  // Longest Job First
    priorityScheduling(processes);  // Priority-based

    return 0;
}

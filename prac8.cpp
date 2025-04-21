#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int pid;            // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time;    // Waiting time

    Process(int id, int arrival, int burst) {
        pid = id;
        arrival_time = arrival;
        burst_time = burst;
        completion_time = 0;
        turnaround_time = 0;
        waiting_time = 0;
    }
};

// Function to find FCFS scheduling
void findFCFSScheduling(vector<Process>& processes) {
    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process& a, Process& b) {
        return a.arrival_time < b.arrival_time;
    });

    int current_time = 0;

    for (auto& process : processes) {
        if (current_time < process.arrival_time) {
            current_time = process.arrival_time;
        }
        current_time += process.burst_time;
        process.completion_time = current_time;
        process.turnaround_time = process.completion_time - process.arrival_time;
        process.waiting_time = process.turnaround_time - process.burst_time;
    }
}

// Function to print process details
void printProcesses(const vector<Process>& processes) {
    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (const auto& process : processes) {
        cout << process.pid << "\t"
             << process.arrival_time << "\t\t"
             << process.burst_time << "\t\t"
             << process.completion_time << "\t\t"
             << process.turnaround_time << "\t\t"
             << process.waiting_time << endl;
    }
}

int main() {
    // Example processes
    vector<Process> processes = {
        Process(1, 0, 5),
        Process(2, 1, 3),
        Process(3, 2, 8),
        Process(4, 3, 6)
    };

    findFCFSScheduling(processes);
    printProcesses(processes);

    return 0;
}

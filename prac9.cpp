#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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

// Function to find SJF scheduling
void findSJFScheduling(vector<Process>& processes) {
    int current_time = 0;
    int completed_processes = 0;
    int n = processes.size();

    while (completed_processes < n) {
        // Get the list of processes that have arrived
        vector<Process*> available_processes;
        for (auto& process : processes) {
            if (process.arrival_time <= current_time && process.completion_time == 0) {
                available_processes.push_back(&process);
            }
        }
        if (!available_processes.empty()) {
            // Select the process with the shortest burst time
            Process* next_process = *min_element(available_processes.begin(), available_processes.end(),
                [](Process* a, Process* b) { return a->burst_time < b->burst_time; });

            current_time += next_process->burst_time;
            next_process->completion_time = current_time;
            next_process->turnaround_time = next_process->completion_time - next_process->arrival_time;
            next_process->waiting_time = next_process->turnaround_time - next_process->burst_time;
            completed_processes++;
        } else {
            current_time++; // If no process is available, increment time
        }
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

// Function to calculate average waiting and turnaround times
void calculateAverageTimes(const vector<Process>& processes) {
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    int n = processes.size();

    for (const auto& process : processes) {
        total_waiting_time += process.waiting_time;
        total_turnaround_time += process.turnaround_time;
    }

    cout << fixed << setprecision(2); // Set precision for average times
    cout << "Average Waiting Time: " << total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << total_turnaround_time / n << endl;
}

int main() {
    // Example processes
    vector<Process> processes = {
        Process(1, 0, 8),
        Process(2, 1, 4),
        Process(3, 2, 9),
        Process(4, 3, 5)
    };

    findSJFScheduling(processes);
    printProcesses(processes);
    calculateAverageTimes(processes);

    return 0;
}

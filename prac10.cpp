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
    int priority;       // Priority
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time;    // Waiting time

    Process(int id, int arrival, int burst, int prio) {
        pid = id;
        arrival_time = arrival;
        burst_time = burst;
        priority = prio;
        completion_time = 0;
        turnaround_time = 0;
        waiting_time = 0;
    }
};

// Function to find non-preemptive priority scheduling
void findPriorityScheduling(vector<Process>& processes) {
    int current_time = 0;
    int completed_processes = 0;
    int n = processes.size();

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process& a, Process& b) {
        return a.arrival_time < b.arrival_time;
    });

    while (completed_processes < n) {
         // Get the list of processes that have arrived
        vector<Process*> available_processes;
        for (auto& process : processes) {
            if (process.arrival_time <= current_time && process.completion_time == 0) {
                available_processes.push_back(&process);
            }
        }

        if (!available_processes.empty()) {
            // Select the process with the highest priority (lowest priority number)
            Process* next_process = *min_element(available_processes.begin(), available_processes.end(),
                [](Process* a, Process* b) { return a->priority < b->priority; });

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
    cout << "PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (const auto& process : processes) {
        cout << process.pid << "\t"
             << process.arrival_time << "\t\t"
             << process.burst_time << "\t\t"
             << process.priority << "\t\t"
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
        Process(1, 0, 5, 2),  // PID 1, Arrival Time 0, Burst Time 5, Priority 2
        Process(2, 1, 3, 1),  // PID 2, Arrival Time 1, Burst Time 3, Priority 1
        Process(3, 2, 8, 3),  // PID 3, Arrival Time 2, Burst Time 8, Priority 3
        Process(4, 3, 6, 2)   // PID 4, Arrival Time 3, Burst Time 6, Priority 2
    };

    findPriorityScheduling(processes);
    printProcesses(processes);
    calculateAverageTimes(processes);

    return 0;
}

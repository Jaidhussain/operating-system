#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

// Structure to hold the data for the thread
struct ThreadData {
    vector<int> numbers; // Vector to hold the numbers
    long sum;            // Variable to hold the sum
};

// Function to be executed by the thread
void* calculateSum(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    data->sum = 0; // Initialize sum to 0

    // Calculate the sum of the numbers
    for (int num : data->numbers) {
        data->sum += num;
    }

    return nullptr; // Return from the thread
}

int main() {
    int n;

    // Ask the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create a vector to hold the numbers
    vector<int> numbers(n);
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Create a ThreadData structure to pass to the thread
    ThreadData data;
    data.numbers = numbers;

    // Create a thread
    pthread_t thread;
    if (pthread_create(&thread, nullptr, calculateSum, &data) != 0) {
        cerr << "Error creating thread" << endl;
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, nullptr);

    // Output the result
    cout << "The sum of the numbers is: " << data.sum << endl;

    return 0;
}

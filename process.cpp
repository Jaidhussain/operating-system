#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int n = fork();
    if (n > 0) { // Parent process
        wait(NULL);
        cout << "hello from parent!" << getpid() << endl;
    } else if (n == 0) { // Child process
        cout << "hello from child!" << getpid() << endl;
    } else { // Error
        cout << "child not created!" << endl;
    }
    return 0;
}

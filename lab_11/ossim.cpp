// Author (in part): Derek Sifford
// --------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                     ossim.cs
//
//  (Shell) Operating system task scheduling simulation
//
// --------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include "PriorityQueue.cpp"

using namespace std;

struct TaskData {
	// Returns the priority. Needed by the heap.
	int getPriority() const { return priority; }

	int priority; // Task's priority
	int arrived;  // Time when task was enqueued
};

int main() {
	PriorityQueue<TaskData, int, Less<int> > taskPQ;
	TaskData *taskin;
	TaskData taskout;
	int simLength;    // Length of simulation (minutes)
	int minute;       // Current minute
	int numArrivals;  // Number of new tasks arriving
	int numTasks = 0; // Running count of pending tasks

	// Seed the random number generator
	srand((unsigned int) time(NULL));

	cout << "Enter the length of time to run the simulator : ";
	cin >> simLength;

	for (minute = 0; minute < simLength; minute++) {
		cout << "Minute " << minute << " (" << numTasks << " pending tasks):" << endl;
		if (!taskPQ.isEmpty()) {
			taskout = taskPQ.dequeue();
			numTasks--;
			cout
			        << "  - Task Dequeued (Pty: "
			        << taskout.priority << ", "
			        << "Enqueued at: "
			        << taskout.arrived << ", "
			        << "Wait time: "
			        << minute - taskout.arrived
			        << ")" << endl;
		}
		else {
			cout << "  - Queue empty" << endl;
		}

		numArrivals = (rand() % 3) + 1;

		switch (numArrivals) {
			case 2:
				taskin = new TaskData;
				taskin->priority = rand() % 2;
				taskin->arrived = minute;
				taskPQ.enqueue(*taskin);
				numTasks++;
				cout << "  - Task Enqueued (Pty: " << taskin->priority << ")" << endl;
			case 1:
				taskin = new TaskData;
				taskin->priority = rand() % 2;
				taskin->arrived = minute;
				taskPQ.enqueue(*taskin);
				numTasks++;
				cout << "  - Task Enqueued (Pty: " << taskin->priority << ")" << endl;
				break;
			default:
				break;
		}
	}

	return 0;
}

/* ==================================WORKSHOP 2 PART 2=================================
NAME: RISHITA RAJENDRAKUMAR PATEL
ID: 141921205
MAIL: rrpatel42@myseneca.ca
SECTION: OOP 345 NBB
DATE: 31 JANUARY 2022
=======================================================================================*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "TimedTask.h"

namespace sdds {

	TimedTask::TimedTask()
	{
		//default constructor....
	}

	void TimedTask::startClock()
		//a modifier that starts the timer for an event....
	{
		time_of_start = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock()
		//a modifier that stops the timer for an event....
	{
		time_of_end = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(std::string task_name)
	{
		//stores into the name attribute the C-style string received as parameter....
		taskss[current_records].task_name = task_name;

		taskss[current_records].task_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(time_of_end - time_of_start);

		taskss[current_records].units_of_time = "nanoseconds";

		current_records += 1;
	}


	ostream& operator<<(std::ostream& os, const TimedTask& taskobj)
	{
		os << "--------------------------" << endl
			<< "Execution Times:\n--------------------------" << endl;

		for (int i = 0; i < taskobj.current_records; i++)
		{
			//name of the task should be in a field of size 21....
			os << std::setw(21) << std::left << taskobj.taskss[i].task_name << " ";
			//duration should be in a field of size 13....
			os << std::setw(13) << std::right << taskobj.taskss[i].task_duration.count() << " " << taskobj.taskss[i].units_of_time << endl;
		}
		return os << "--------------------------\n";
	}

}

/* ==================================WORKSHOP 2 PART 2=================================
NAME: RISHITA RAJENDRAKUMAR PATEL
ID: 141921205
MAIL: rrpatel42@myseneca.ca
SECTION: OOP 345 NBB
DATE: 31 JANUARY 2022
=======================================================================================*/

#include <iostream>
#include<chrono>
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

using namespace std;
namespace sdds
{
	//class predefines the maximum number of event objects at 10....
	const int MAX_NUM_EVENTS = 10;

	class TimedTask
	{
	public:

		struct Task
		{
			std::string task_name;		//string with the task name.....
			std::string units_of_time;		//string with the units of time..
			std::chrono::steady_clock::duration task_duration;		//duration of the task....
		};

		Task taskss[MAX_NUM_EVENTS];
		int current_records = 0;		//the number of records currently stored
		std::chrono::steady_clock::time_point time_of_start;		//start time for the current task....
		std::chrono::steady_clock::time_point time_of_end;		//end time for the current task....

		TimedTask();
		void startClock();
		void stopClock();
		void addTask(std::string task_name);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& taskobj);

	};

}

#endif

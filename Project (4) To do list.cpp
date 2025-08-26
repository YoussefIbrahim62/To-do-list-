
#include <iostream>
#include<string>
#include <vector>
#include <iomanip>
#include "ToDoAppMyLib.h"

using namespace std;
using namespace SecondaryFunctions;


// app main structs and enums

enum enTaskStatus
{
	completed = 1,
	ToDo = 2,
	InProgress = 3
};

enum enUserOptions
{
	AddTask = 1,
	EditTaskName = 2,
	ChangeTaskStatus = 3
};

struct stTask
{
	string TaskName;
	string TaskStatus;

};



// app main functions

int AskUserForHowManyTasks()
{
	int NumberOfTasks = ReadHowMany("How many tasks do you want to add? ");
	return NumberOfTasks;
}

enTaskStatus AskUserAboutStatus()
{
	int input;

	cout << "Please enter the status? [1] Completed  [2] To Do  [3] In Progress\n";

	input = GetNumbersInRange(1, 3);

	return (enTaskStatus)input;
}

string SetStatus(enTaskStatus Status)
{
	switch (Status) 
	{
	 case enTaskStatus::completed:
		return "Completed";
	 case enTaskStatus::InProgress:
		 return "In Progress";
	 case enTaskStatus::ToDo:
		 return "To Do";

	}

}

stTask AddATask()
{
	stTask TempTask;

	cout << "\nPlease enter the task name: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, TempTask.TaskName);

	TempTask.TaskStatus = SetStatus(AskUserAboutStatus());

	return TempTask;
}


void FillVectorWithTasks(vector<stTask> &vTasks, int NumberOfTasks) 
{
	stTask TempTask;

	for (int i = 0; i < NumberOfTasks; i++)
	{
		cout << "\nTask [" << i + 1 << "]\n";
		TempTask = AddATask();

		vTasks.push_back(TempTask);
	}

}


void ShowToDoList(vector<stTask>& vTasks)
{
	cout << "\n\n\n\n";
	cout << "\t\t|-----|------------------------------|---------------|\n";
	cout << "\t\t| Num |          Task name           |     Status    |\n";
	cout << "\t\t|-----|------------------------------|---------------|\n";

	for (int i = 0; i < vTasks.size(); i++)
	{
		cout << "\t\t|" << left << setw(5) << i+1 << "|" << setw(30) << vTasks[i].TaskName << "|" << setw(15) << vTasks[i].TaskStatus << "|\n";
	}

	cout << "\t\t|-----|------------------------------|---------------|\n\n\n";

}

enUserOptions showOptions()
{
	int input;

	cout << "[1] Add Task [2] Edit task name  [3] Edit task status\n\n";

	cout << "What do you want to do ?  ";
	input = GetNumbersInRange(1, 3);

	return (enUserOptions)input;

}

void ApplyOptions(enUserOptions options, vector<stTask>& vTasks)
{
	if (options == enUserOptions::AddTask)
	{
		vTasks.push_back(AddATask());
	}
	else if (options == enUserOptions::EditTaskName)
	{
		int TaskNumber;
		string NewTaskName;

		cout << "Please enter the task number:  ";
		cin >> TaskNumber;

		cout << "Please enter new name:  ";

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, NewTaskName);

		vTasks[TaskNumber - 1].TaskName = NewTaskName;

	}
	else 
	{
		int TaskNumber;

		cout << "Please enter the task number:  ";
		cin >> TaskNumber;

		vTasks[TaskNumber - 1].TaskStatus = SetStatus(AskUserAboutStatus());

	}
}



void RunApp()
{
	vector<stTask> vTasks =
	{
		{"C++ course","To Do"},
		{"English course","In Progress"},
		{"Python","Completed"}
	};

 AppHeader("   To Do list App");
 
 
 FillVectorWithTasks(vTasks, AskUserForHowManyTasks());
 
 char input = 'Y';

 do
 {
	 ShowToDoList(vTasks);
	 ApplyOptions(showOptions(), vTasks);

	 ShowToDoList(vTasks);

	 cout << "Are you done? [Y] or [N] ";
	 cin >> input;

 } while (input == 'N' || input == 'n');
 
}


int main()
{

	RunApp();
}


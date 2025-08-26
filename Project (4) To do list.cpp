
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
	ModifiyTask = 2,
	ChangeTaskStatus = 3
};

struct stTask
{
	string TaskName;
	enTaskStatus TaskStatus;

};



// app main functions

int AskUserForHowManyTasks()
{
	int NumberOfTasks = ReadHowMany("How many tasks do you want to add? ");
	return NumberOfTasks;
}

//void RunApp()
//{
// AppHeader("   To Do list App");
// 
// AskUserForHowManyTasks();
// 
// FillVectorWithTasks();
// 
// showToDoList()
// 
// showOptions() --> addTtask() setStatus();
// 
//
//}


int main()
{
	cout << AskUserForHowManyTasks();
}


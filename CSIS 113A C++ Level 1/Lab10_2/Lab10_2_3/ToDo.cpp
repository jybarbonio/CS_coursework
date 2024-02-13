#include <iostream>
#include "ToDo.h"

using namespace std;

ToDoList::ToDoList()
	:head(0), tail(-1)
{}

bool ToDoList::addToList(const MyToDo &td) 
{
	if(head < MAXLIST) 
	{
		if(tail == -1) 
			tail++;
			toDoList[head] = td;
			head++;
			return true;
		return false;
	}
}
bool ToDoList::addToList(string description, string date, int priority) 
{
	MyToDo td;
	td.description = description;
	td.dueDate = date;
	td.priority = priority;
	return addToList(td);
}
bool ToDoList::getNextItem(MyToDo &td)
{
	if (tail >= 0)
	{
		if (tail >= MAXLIST)
			tail = 0;
		td = toDoList[tail];
		tail++;
		return true;
	}
	return false;
}
bool ToDoList::getNextItem(string &description, string &date, int &priority)
{
	MyToDo tmp;
	bool status = getNextItem(tmp);
	if(status == true) 
	{
		description = tmp.description;
		date = tmp.dueDate;
		priority = tmp.priority;
	}
	return status;
}
void ToDoList::printToDo()
{
	for(int i = 0; i < head; i++) 
	{
		cout << "Description: " << toDoList[i].description << endl;
		cout << "Due Date: " << toDoList[i].dueDate << endl;
		cout << "Priority: " << toDoList[i].priority << endl;
	}
}
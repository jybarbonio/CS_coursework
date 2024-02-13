#include <iostream>
#include "ToDo.h"

using namespace std;

int main() 
{
	ToDoList tdl;

	tdl.addToList("Dentist", "Oct. 4", 2);
	tdl.addToList("Homework", "Oct. 4", 2);
	tdl.addToList("Shopping", "Oct. 3", 2);
	tdl.addToList("Concert", "Oct. 5", 2);
	tdl.addToList("Watch TV", "Oct. 7", 2);
	tdl.addToList("Go To Gym", "Oct. 9", 2);

	tdl.printToDo();

	system("pause");
	return 0;
}
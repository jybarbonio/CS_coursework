#ifndef TODO
#define TODO
#include <string>

using std::string;

const int MAXLIST = 10;

struct MyToDo
{
	string description;
	string dueDate;
	int priority;
};
class ToDoList
{
private:
	MyToDo toDoList[MAXLIST];
	int head;
	int tail;
public:
	ToDoList();
	bool addToList(const MyToDo& td);
	bool addToList(string description, string date, int priority);
	bool getNextItem(MyToDo& td);
	bool getNextItem(string& description, string& date, int& priority);
	void printToDo();

};

#endif
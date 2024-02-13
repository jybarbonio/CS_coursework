#pragma once
#include "LinkedList.h"
// directed (digraph)
class Graph
{
private:
	int size;
	LinkedList<std::string>* graphArray;
	LinkedList<bool>* visited;
public:
	Graph(int size) { this->createGraph(size); }

	void createGraph(int size);
	void depthFirstTraversal(int index);
	void addEdge(std::string src, std::string dst);
	//void printGraph();
};
void Graph::createGraph(int size)
{
	this->graphArray = new LinkedList<std::string>[size];
}
void Graph::depthFirstTraversal(int index)
{
	/*
	//std::cout << index << ".\t" << names[index] << std::endl;
	Node<std::string>* p = this->graphArray[index].getHead();

	visited[index] = true;
	while(p != NULL)
	{
		index = p->vertex;
		if(!visited[index])
		{
			this->depthFirstTraversal(index);
			p = p->Next;
		}
	}
	*/
}
void Graph::addEdge(std::string src, std::string dst)
{
	Node<std::string>* p;
	
	for (int i = 0; i < size; i++)
	{
		p = graphArray[i].getHead();
		if(p == NULL)
		{
			graphArray[i].addToFront(src);
			graphArray[i].addToFront(dst);
			break;
		}
		else if(p->Data == src)
		{
			graphArray[i].addToFront(dst);
			break;
		}
	}
}

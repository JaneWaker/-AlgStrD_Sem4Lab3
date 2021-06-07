#pragma once
#include <fstream>
#include "List.cpp"

class Graph
{
private:
	BiList<string> Node, Information;
	int** Matrix;
	size_t size;
	void Summarize();

public:
	Graph();
	void input(string filename = "in.txt");
	void clear();
	size_t FloydWarshall(size_t, size_t);
	~Graph();
};


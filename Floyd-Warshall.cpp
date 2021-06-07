#include "Floyd-Warshall.h"
#include <iostream>

#define inf INT_MAX/2-1

using namespace std;

Graph::Graph()
{
	Matrix = NULL;
	size = 0;
}

Graph::~Graph()
{
	clear();
}

void Graph::input(string filename)
{
	Information.clear(); Node.clear();
	if (filename == "") {
		filename = "in.txt";
	}
	string temp;
	ifstream File;
	File.open(filename.c_str(), ios::in);
	if (File.bad()) {
		throw "Error";
	}
	while (!File.eof())
	{
		getline(File, temp);
		Information.push_back(temp);
	}
	Summarize();
}

size_t Graph::FloydWarshall(size_t first, size_t other)
{
	if (first == other) {
		return 0;
	}
	int* Length = new int[Node.get_size()];
	int* Way = new int[Node.get_size()];
	for (size_t i = 0; i < Node.get_size(); i++)
	{
		if (i != first) {
			Length[i] = Matrix[first][i];
		}
		else {
			Length[i] = 0;
		}
		Way[i] = -1;
	}
	for (size_t k = 0; k < Node.get_size(); k++)
	{
		bool A = false;
		for (size_t i = 0; i < Node.get_size(); i++)
		{
			for (size_t j = 0; j < Node.get_size(); j++)
			{
				if (i != j && (Length[j] + Matrix[j][i]) < Length[i])
				{
					Length[i] = Length[j] + Matrix[j][i];
					Way[k] = (int)j;
					A = true;
				}
			}
		}
		if (!A) break;
	}
	if (Length[other] == inf) {
		cout << "Пути нет" << endl;
	}
	else
	{
		cout << "Путь:" << Length[other] << endl;
		cout << "Маршрут: " << Node.at(first);
		for (size_t i = 0; i < Node.get_size(); i++)
		{
			if (Way[i] == -1 || Way[i] == other)
				break;
			cout << " -> " << Node.at(Way[i]);
		}
		cout << "->" << Node.at(other) << endl;
	}
	size_t result = Length[other];
	delete[] Length; delete[] Way;
	return result;
}

void Graph::clear()
{
	Node.clear();
	Information.clear();
	for (size_t i = 0; i < size; i++)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
	Matrix = NULL;
	size = 0;
}

void Graph::Summarize()
{
	size_t Iterator = Information.get_size();
	int** temp1 = new int* [Iterator];
	for (size_t i = 0; i < Iterator; i++) {
		temp1[i] = new int[4];
	}
	for (size_t i = 0; i < Iterator; i++)
	{
		string temp = Information.at(i), name = "";
		string Way[4] = { "","","","" };
		size_t k = 0;
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (temp[j] == ';') {
				k++;
			}
			else {
				Way[k].push_back(temp[j]);
			}
		}
		for (size_t k = 0; k < 2; k++)
		{
			if (Node.find(Way[k]) == -1) {
				Node.push_back(Way[k]);
			}
			if (Way[k + 2][0] == 'N') {
				temp1[i][k + 2] = inf;
			}
			else {
				temp1[i][k + 2] = stoi(Way[k + 2]);
			}
		}
		temp1[i][0] = Node.find(Way[0]);
		temp1[i][1] = Node.find(Way[1]);
	}
	size = Node.get_size();
	Matrix = new int* [size];
	for (size_t i = 0; i < size; i++)
	{
		Matrix[i] = new int[size];
		for (size_t j = 0; j < Node.get_size(); j++) {
			Matrix[i][j] = inf;
		}
	}
	for (size_t i = 0; i < Iterator; i++)
	{
		Matrix[temp1[i][0]][temp1[i][1]] = temp1[i][2];
		Matrix[temp1[i][1]][temp1[i][0]] = temp1[i][3];
		delete[] temp1[i];
	}
	delete[] temp1;
}


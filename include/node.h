#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>

struct Node {
	int id;
	std::string text;
	std::vector<Node*> neighbors;
	Node *parent;
	
	bool sorted;
	
	Node(std::string = "", Node *parent = nullptr);
	
	inline bool isRoot() const
	{
		return this->parent == nullptr;
	}
	inline int getID() const
	{
		return this->id;
	}
	inline std::string getText() const
	{
		return this->text;
	}


	void setText(const std::string text);
	Node *createNode(std::string text = "");
	Node *connectTo(Node *node);
	void sort();
	std::map<int, std::vector<Node *>> neighborsInducedGraph();
	void print();
};

#endif

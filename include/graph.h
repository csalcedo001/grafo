#include <iostream>
#include <map>

#include "node.h"

class Graph {
	public:
	std::map<int, Node*> nodes;
	Node *currentNode;
	
	Graph();
	
	void mapNode(Node *node);
	void insertNode(std::string text = ""); 
	void updateNode(int id, std::string s);
	Node* getNode(int id);
	void deleteNode(int id);
	void moveTo(int id);
	void connectNodes(int id1, int id2);
	void print();
	
	~Graph();
};

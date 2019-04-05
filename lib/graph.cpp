#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>

#include "node.h"
#include "graph.h"

Graph::Graph() {
	this->currentNode = new Node();
	this->mapNode(this->currentNode);
}

void Graph::mapNode(Node *node) {
	this->nodes[node->getID()] = node;
}

// Inserts a node on the current node edge list
void Graph::insertNode(std::string text) {
	this->mapNode(this->currentNode->createNode(text));
}

Node* Graph::getNode(int id) {
	return this->nodes[id];
}

void Graph::moveTo(int id) {
	this->currentNode = nodes[id];
}

void Graph::connectNodes(int id1, int id2) {
	this->nodes[id1]->connectTo(this->nodes[id2]);
}

void Graph::print() {
	for (auto source : this->nodes) {
		std::cout << source.first << " |";
		
		for (auto dest : source.second->neighbors) {
			std::cout << ' ' << dest->getID();
		}
		
		std::cout << std::endl;
	}
}

Graph::~Graph() {
	for (auto pair : this->nodes) {
		delete pair.second;
	}
}

#endif

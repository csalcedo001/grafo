#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>

#include "node.h"

int IDCount = 0;

Node::Node(std::string text, Node *parent) :
	id(IDCount++),
	text(text),
	parent(parent),
	sorted(true) {};

void Node::setText(const std::string text) {
	this->text = text;
}

Node *Node::createNode(std::string) {
	return this->connectTo(new Node(text, this));
}

Node *Node::connectTo(Node *node) {
	this->neighbors.push_back(node);
	this->sorted = false;
	return node;
}

void Node::sort() {
	if (!this->sorted) {
		std::sort(
			this->neighbors.begin(),
			this->neighbors.end());
		
		this->sorted = true;
	}
}

std::map<int, std::vector<Node *>> Node::neighborsInducedGraph() {
	std::map<int, std::vector<Node *>> result;
	
	this->sort();
	
	for (auto source : this->neighbors) {
		source->sort();
		
		std::set_intersection(
			this->neighbors.begin(),
			this->neighbors.end(),
			source->neighbors.begin(),
			source->neighbors.end(),
			std::back_inserter(result[source->getID()]));
	}
	
	return result;
}

void Node::print() {
	std::cout << this->id << ": \"" << this->text << '\"' << std::endl;
	
	for (auto node : this->neighbors) {
		std::cout << node->getID() << ' ';
	}
	
	std::cout << std::endl;
}

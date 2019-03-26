#include <map>

#include "node.h"

class Graph {
	public:
	std::map<int, Node*> nodes; // id-node mapping
	Node *currentNode;
	
	Graph() {
		this->currentNode = new Node();
		this->mapNode(this->currentNode);
	}
	
	void mapNode(Node *node) {
		this->nodes[node->getID()] = node;
	}
	
	// Inserts a node on the current node edge list
	void insertNode(std::string text = "") {
		this->mapNode(this->currentNode->createNode(text));
	}
	void updateNode(int id, std::string s);
	Node* getNode(int id) {
		return this->nodes[id];
	}
	void deleteNode(int id);
	void moveTo(int id) {
		this->currentNode = nodes[id];
	}
	void connectNodes(int id1, int id2) {
		this->nodes[id1]->connectTo(this->nodes[id2]);
	}
	void print() {
		for (auto source : this->nodes) {
			std::cout << source.first << " |";
			
			for (auto dest : source.second->neighbors) {
				std::cout << ' ' << dest->getID();
			}
			
			std::cout << std::endl;
		}
	}
	
	~Graph() {
		for (auto pair : this->nodes) {
			delete pair.second;
		}
	}
};

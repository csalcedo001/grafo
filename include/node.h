#include <vector>
#include <iterator>
#include <algorithm>

int IDCount = 0;

struct Node {
	int id;
	std::string text;
	std::vector<Node*> neighbors;
	Node *parent;
	
	bool sorted;
	
	Node(std::string text = "", Node *parent = nullptr) :
		id(IDCount++),
		text(text),
		parent(parent),
		sorted(true) {};
	
	inline bool isRoot() const {
		return this->parent == nullptr;
	}
	
	inline int getID() const {
		return this->id;
	}
	
	inline std::string getText() const {
		return this->text;
	}
	
	void setText(const std::string text) {
		this->text = text;
	}
	
	Node *createNode(std::string text = "") {
		return this->connectTo(new Node(text, this));
	}
	Node *connectTo(Node *node) {
		this->neighbors.push_back(node);
		this->sorted = false;
		return node;
	}
	void sort() {
		if (!this->sorted) {
			std::sort(
				this->neighbors.begin(),
				this->neighbors.end());
			
			this->sorted = true;
		}
	}
	std::map<int, std::vector<Node *>> neighborsInducedGraph() {
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
	void print() {
		std::cout << this->id << ": \"" << this->text << '\"' << std::endl;
		
		for (auto node : this->neighbors) {
			std::cout << node->getID() << ' ';
		}
		
		std::cout << std::endl;
	}
};

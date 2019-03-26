#include <iostream>
// #include <GLUT/GLUT.h>

#include "graph.h"

using namespace std;

// int main(int argc, char **argv) {
// 	glutInit(&argc, argv);
// 	
// 	
// 	return 0;
// }
int main(void) {
	Graph g;
	
	g.insertNode("Idea 1");
	g.insertNode("Idea 2");
	g.insertNode("Idea 3");
	g.insertNode("Idea 4");
	
	g.connectNodes(1, 2);
	g.connectNodes(1, 3);
	g.connectNodes(1, 4);
	g.connectNodes(2, 4);
	
	for (auto pair : g.getNode(0)->neighborsInducedGraph()) {
		cout << pair.first << " |";
		
		for (auto node : pair.second) {
			cout << ' ' << node->getID();
		}
		
		cout << endl;
	}
	
	return 0;
}

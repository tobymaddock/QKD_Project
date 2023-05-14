// member definitions for the node class
# include "node.hpp"

Node::Node(string name) {
	itsName = name;
}

Node::~Node(){
	std::cout << "Node Destructor";
}

string Node::getName() { return itsName; }
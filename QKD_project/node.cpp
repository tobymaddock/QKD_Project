// member definitions for the node class
# include "node.hpp"
# include "protocols.hpp"

using namespace std;

Node::Node(string name) {
	itsName = name;
}

Node::~Node(){
	std::cout << "Node Destructor";
}

string Node::getName() {return itsName;}

void QKD_Node::communicateClassically(){
	std::cout << "will add";
}
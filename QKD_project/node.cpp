// member definitions for the node class
# include "node.hpp"
# include "protocols.hpp"

using namespace std;

// IMPLEMENTATIONS FOR QKD_NODE:
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

// IMPLEMENTATIONS FOR QKD_NODE_SOURCE:
void QKD_Node_Source::sendBits(keyBits message) {

	
}

// IMPLEMENTATIONS FOR QKD_NODE_RECEIVER:
void QKD_Node_Receiver::setReceivedKeys(keyBits key) {
	*receivedKeys =  key;
}
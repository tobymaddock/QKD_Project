// node classes - idea is that various nodes (source, receiver etc) inherit from this
#include "protocols.hpp"
# include <iostream>
# include <bitset>
# include <vector>
# include <sstream>
# include <string>
# include <algorithm>

using namespace std;

// might make this an abstract class
class Node {
public:
	/*
	* Constructor for the Node class. 
	* name: name of the given node
	*/
	string name;
	Node(string name) {
		name = name;
	}
};

class QKD_Node: private Node {
protected:

public:
	
};

class QKD_Node_Source: private QKD_Node {
public:
	void send_bits() {
	}
};

class QKD_Node_receiver : private QKD_Node {
public:
	void get_bits() {
	}
};
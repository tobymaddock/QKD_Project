// node classes - idea is that various nodes (source, receiver etc) inherit from this
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

	Node(string name); //constructor
	~Node(); // node destructor
	string getName(); // accessor

private:
	string itsName; //atribute
};

class QKD_Node: private Node {
public:
	void communicateClassically();
private:
};

class QKD_Node_Source: private QKD_Node {
public:
	void sendBits();
private:
	string lightSource;
};

class QKD_Node_Receiver : private QKD_Node {
public:
	void get_bits();
};
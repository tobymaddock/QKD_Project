// node classes - idea is that various nodes (source, receiver etc) inherit from this
# include <iostream>
# include <bitset>
# include <vector>
# include <sstream>
# include <string>
# include <algorithm>
# include "keyBits.hpp"

using namespace std;
class QKD_Node_Receiver;
class QKD_Node_Source;

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

class QKD_Node : private Node {
public:
	void communicateClassically();
private:
};

class QKD_Node_Source : private QKD_Node {
public:
	void sendBits(const keyBits message);
	void setReceiver(QKD_Node_Receiver Bob);

private:
	string lightSource;
	keyBits* keysToSend;
	QKD_Node_Receiver* Receiver = nullptr;
};

class QKD_Node_Receiver : private QKD_Node {
public:
	void setReceivedKeys(keyBits);
private:
	keyBits* receivedKeys;
	QKD_Node_Source Sender;
};


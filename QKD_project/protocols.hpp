// classes corresponding to each QKD protocol

class Protocol {
public:
	void checkMatchingBasis();
	void getSiftedKey();
};

class BB84: private Protocol {
public:
	BB84() {}


};

class BBM92: private Protocol {
public:
	BBM92() {}
};

class E91 : private Protocol {
public:
	E91() {}
};
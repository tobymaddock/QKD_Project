# include "keyBits.hpp"

// constructor
keyBits::keyBits(int size) {
	itsSize = size;
	pKeys = new bool[size];
	for (int i = 0; i < size; i++) {
		pKeys[i] = 1;
	}
}

// constructor
keyBits::keyBits(const keyBits& rhs) {
	pKeys = new bool[rhs.getSize()];
	*pKeys = *(rhs.pKeys);
}

// accessor
int keyBits::keyBits::getSize() const {
	return itsSize;
}

// accessor
void keyBits:: setKey(const bool* arr) {
	for (int i = 0; i < itsSize; i++) {
		pKeys[i] = arr[i];
	}
}

// accessor


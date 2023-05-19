#include <algorithm>
#include <string>
#include <iostream>

#ifndef KEYBITS_HPP
#define KEYBITS_HPP

// generic class for storing/mainipulating key bits for qkd protocols
// will store 'bits' as a list of bools
// will apportion bits to the heap
// can handle weird cases, like adding key lists of different lengths
class keyBits {
public:
	// constructors
	keyBits(int size);
	// function passes a string to generate a valid key and appropriate key length
	keyBits(const std::string& bitAsString);

	keyBits(bool* keyArray, int size) {
		itsSize = size;
		pKeys = keyArray;
	}

	// copy constructor
	keyBits(const keyBits& rhs);

	// destructor
	~keyBits() { delete pKeys; }

	// accessors
	int getSize() const;
	const bool* getKey() const{
		return pKeys;
	}

	void setKey(const bool* arr);

	//operators:
	//assignment operator:
	keyBits& operator=(const keyBits& rhs) {
		if (this == &rhs) 
		return *this;
		// copy pointer to new object
		*pKeys = rhs.getKey();
		return *this;
	}
	

	//indexing:
	bool& operator[](int offSet) {
		return pKeys[offSet];
	}

	//'^' to XOR two keyBits objects:
	keyBits operator^(const keyBits& rhs) const {
		if (itsSize == rhs.getSize()) {
			// obviously I should just add another constructor to account for a bool array input
			bool* xorResult = new bool[itsSize];
			const bool* leftKey = this->getKey();
			const bool* rightKey = rhs.getKey();
			for (int i = 0; i < itsSize; i++) {
				xorResult[i] = (leftKey[i] != rightKey[i]);
			}
			keyBits key(xorResult, itsSize);
			std::cout << "size: " << key.getSize() << "\n";
			return key;
		}
	}

	// '+' to return an object with the rhs appended to the lhs

	keyBits operator+(const keyBits& rhs) const {
		const int sum = itsSize + rhs.getSize();
		keyBits key(sum);
		bool* result = new bool[sum];
		concatenateArrays(pKeys, itsSize, rhs.getKey(), rhs.getSize(), result);
		key.setKey(result);
		return key;
	}

private:
	// function to concatenate arrays
	void concatenateArrays(const bool* arr1, int size1, const bool* arr2, int size2, bool* result) const{
		std::copy(arr1, arr1 + size1, result);
		std::copy(arr2, arr2 + size2, result + size1);
	}
	int itsSize;
	bool* pKeys;

};

#endif
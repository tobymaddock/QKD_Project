
// generic class for storing/mainipulating key bits for qkd protocols
// will store 'bits' as a list of bools
// will apportion bits to the heap
// can handle weird cases, like adding key lists of different lengths
class keyBits {
public:
	// constructors
	keyBits(int size = 0) {
		itsSize = size;
		pKeys = new bool[size];
		for (int i = 0; i < size; i++) {
			pKeys[i] = 1;
		}
	}

	// copy constructor
	keyBits(const keyBits& rhs) {
		pKeys = new bool[rhs.getSize()];
		*pKeys = *(rhs.pKeys);
	}

	// destructor
	~keyBits() { delete pKeys; }

	// accessors
	int getSize() const {
		return itsSize;
	}

	//operators:
	//indexing:
	bool& operator[](int offSet) {
		return pKeys[offSet];
	}

	//'^' to XOR two keyBits objects:

	// '+' to return an object with the rhs appended to the lhs
	keyBits operator+(const keyBits& rhs) const {
		int sum = itsSize + rhs.getSize();
		keyBits key(sum);
		return key;
	}

private:
	int itsSize;
	bool* pKeys;
};
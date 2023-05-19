# include <iostream>
# include <bitset>
# include <vector>
# include <sstream>
# include <string>
# include <algorithm>
# include "node.hpp"
# include "keyBits.hpp"

using namespace std;

void unitTest_XOR() {

	// will use this to test 



}


void unitTest_addition() {





}






int bb84_protocol(std::bitset<7> & alice_basis, std::bitset<7> & bob_basis,
	std::bitset<7> & alice_states, std::bitset<7> & bob_states) {
	// gonna break this down into a bunch of steps - for now will skip
	// measurement etc and assume the sender (alice) is privy to a preparation basis list with
	// states and bob a measurement basis list and measurement outcomes

	// step 1: perform basis reconciliation
	std::vector<int> matching_indices;
	for (int i = 0; i < alice_states.size(); i++) {
		if (alice_basis[i] == bob_basis[i]) {
			matching_indices.push_back(i);
		}
	}

	std::stringstream ss;
	std::copy(matching_indices.begin(), matching_indices.end(), std::ostream_iterator<int>(ss, " "));
	std::string s = ss.str();
	s = s.substr(0, s.length() - 1);

	// step 2 TODO: extract the sifted key

	// step 3: compare the sifted keys for errors
	int index = 0;
	int errors = 0;
	for (int i = 0; i < matching_indices.size(); i++) {
		index = matching_indices[i];
		if (alice_states[index] != bob_states[index]) {
			errors += 1;
		}
	}
	return errors;
}







void printKey(const bool arr[], int indexSize) {
	
	for (int i = 0; i < indexSize; i++) {
		std::cout << arr[i];
	}
}


int main() {
	keyBits krey("11111");
	keyBits krey2("11111");
	keyBits krey3 = krey^krey2; // XOR operation
	std::cout << "new size: " << krey3.getSize() << "\n";
	const bool* arr = krey3.getKey();
	printKey(arr, krey3.getSize());


	//std::bitset<7>  alice_basis("1010100");
	//std::bitset<7>  bob_basis("1000110");

	// step 2: generate the states/measurement outcomes
	//std::bitset<7> alice_states("1111111");
	//std::bitset<7> bob_states("1111111");

	//std::cout << "bb84 protocol:" << bb84_protocol(alice_basis, bob_basis, alice_states,
	//	bob_states) << "\n";

	//Node firstNode = Node("importantNode");
	//std::cout << firstNode.getName();
	return 0;
}
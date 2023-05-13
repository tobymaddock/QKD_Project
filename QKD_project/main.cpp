# include <iostream>
# include <bitset>
# include <vector>
# include <sstream>
# include <string>
# include <algorithm>

using namespace std;

int bb84_protocol() {
	// gonna break this down into a bunch of steps - for now will skip
	// measurement etc and assume the sender (alice) is privy to a preparation basis list with
	// states and bob a measurement basis list and measurement outcomes

	// step 1: generate the lists
	std::bitset<7>  alice_basis("1010100");
	std::bitset<7>  bob_basis("1000110");

	// step 2: generate the states/measurement outcomes
	std::bitset<7> alice_states("1111111");
	std::bitset<7> bob_states("1111111");

	// step 3: perform basis reconciliation
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

	// step 4: extract the sifted key

	// step 5: compare the sifted keys for errors
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

int bbm92_protocol() {
	return 1;
}

int e91_protocol() {
	return 2;
}

int main() {
	// write a command to the console
	std::cout << "This is my QKD project" << "\n";

	// basic bitwise addition
	std::bitset<5>  a("10101");
	std::bitset<5> const b("11111");
	a ^= b;
	std::cout << a << "\n";
	std::cout << "bb84 protocol:" << bb84_protocol() << "\n";
	std::cout << e91_protocol() << "\n";
	std::cout << bbm92_protocol() << "\n";

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>
#include <utility>

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(*a))
#endif

using namespace std;

class KingSort {
public:
	static unsigned int getOrdinal(const std::string &value) {
		unsigned int result = 0;
		unsigned int xCount = 0;
		unsigned int iCount = 0;
		for(unsigned int i = 0; i < value.size(); i++) {
			switch(value[i]) {
				case 'L': {
					if (xCount == 0) {
						result += 50;
					} else if (xCount == 1) {
						result += 30;
					} else {
						assert(false);
					}
					break;
				}
				case 'X': {
					if (iCount == 0) {
						result += 10;
					} else if (iCount == 1) {
						result += 8;
					} else {
						assert(false);
					}
					xCount++;
					break;
				}
				case 'V': {
					if (iCount == 0) {
						result += 5;
					} else if (iCount == 1) {
						result += 3;
					} else {
						assert(false);
					}
					break;
				}
				case 'I': {
					result += 1;
					iCount++;
					break;
				}
				default: {
					assert(false);
					break;
				}
			}
		}
		return result;
	}
	static bool mySortFunc(const std::string &left, const std::string &right) {
		const std::string::const_iterator leftIt = std::find(left.begin(), left.end(), ' ') + 1;
		const std::string::const_iterator rightIt = std::find(right.begin(), right.end(), ' ') + 1;
		const int nameComp = left.compare(0, std::distance(left.begin(), leftIt), right.substr(0, std::distance(right.begin(), rightIt)));
		if (nameComp != 0) {
			return nameComp < 0;
		}
		const unsigned int leftOrdinal = getOrdinal(left.substr(std::distance(left.begin(), leftIt)));
		const unsigned int rightOrdinal = getOrdinal(right.substr(std::distance(right.begin(), rightIt)));
		return leftOrdinal < rightOrdinal;
	}
	vector <string> getSortedList(vector <string> kings) {
		std::sort(kings.begin(), kings.end(), &mySortFunc);
		return kings;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Louis IX", "Louis VIII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis VIII", "Louis IX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
	void test_case_1() { string Arr0[] = {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
	void test_case_2() { string Arr0[] = {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
	void test_case_3() { string Arr0[] = {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
	void test_case_4() { string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
	void test_case_5() { string Arr0[] = {"Philippe II", "Philip II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Philip II", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	KingSort ___test;
	___test.run_test(-1);
	::getchar();
	return 0;
}
// END CUT HERE

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits.h>
#include <ctype.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>
#include <utility>

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(*a))
#endif

using namespace std;

class DengklekMakingChains {
public:
	int maxBeauty(vector <string> chains) {
		unsigned int singleMax = 0;
		for (unsigned int i = 0; i < chains.size(); i++) {
			if (chains[i][0] == '.' && ::isdigit(chains[i][1]) != 0 && chains[i][2] == '.') {
				singleMax = std::max(singleMax, static_cast<unsigned int>(chains[i][1] - '0'));
			}
		}
		unsigned int leftMax = 0;
		for (unsigned int i = 0; i < chains.size(); i++) {
			if (chains[i][0] == '.' && ::isdigit(chains[i][2]) != 0) {
				unsigned int value = chains[i][2] - '0';
				if (::isdigit(chains[i][1]) != 0) {
					value += (chains[i][1] - '0');
				}
				leftMax = std::max(leftMax, value);
			}
		}
		unsigned int rightMax = 0;
		for (unsigned int i = 0; i < chains.size(); i++) {
			if (::isdigit(chains[i][0]) != 0 && chains[i][2] == '.') {
				unsigned int value = chains[i][0] - '0';
				if (::isdigit(chains[i][1]) != 0) {
					value += (chains[i][1] - '0');
				}
				rightMax = std::max(rightMax, value);
			}
		}
		unsigned int center = 0;
		for (unsigned int i = 0; i < chains.size(); i++) {
			if (::isdigit(chains[i][0]) != 0 && ::isdigit(chains[i][1]) != 0 && ::isdigit(chains[i][2]) != 0) {
				const unsigned int value = (chains[i][0] - '0') + (chains[i][1] - '0') + (chains[i][2] - '0');
				center += value;
			}
		}
		std::vector<std::pair<unsigned int, unsigned int> > left(2);
		std::vector<std::pair<unsigned int, unsigned int> > right(2);
		for (unsigned int i = 0; i < chains.size(); i++) {
			if (::isdigit(chains[i][0]) != 0 && chains[i][1] == '.' && ::isdigit(chains[i][2]) != 0) {
				const unsigned int rValue = chains[i][0] - '0';
				const unsigned int lValue = chains[i][2] - '0';
				if (left[0].first < lValue) {
					left[1] = left[0];
					left[0] = std::make_pair(lValue, i);
				} else if(left[1].first < lValue) {
					left[1] = std::make_pair(lValue, i);
				}
				if (right[0].first < rValue) {
					right[1] = right[0];
					right[0] = std::make_pair(rValue, i);
				} else if(right[1].first < rValue) {
					right[1] = std::make_pair(rValue, i);
				}
			}
		}
		if (left[0].second != right[0].second || left[0].first < leftMax || right[0].first < rightMax) {
			return std::max(singleMax, std::max(left[0].first, leftMax) + center + std::max(right[0].first, rightMax));
		}
		return std::max(singleMax, center + std::max(left[0].first + std::max(right[1].first, rightMax), std::max(left[1].first, leftMax) + right[0].first));
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }
	void test_case_6() { string Arr0[] = {"..3", "4.4", "0.2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(6, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	DengklekMakingChains ___test;
	___test.run_test(-1);
	::getchar();
	return 0;
}
// END CUT HERE

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits.h>

#include <iostream>
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

using namespace std;

class Cut {
public:
	int getMaximum(vector<int> eelLengths, int maxCuts) {
		unsigned int result = 0;
		std::sort(eelLengths.begin(), eelLengths.end());

		{
			vector<int>::iterator eraseIt = eelLengths.begin();
			for(; eraseIt < eelLengths.end() && *eraseIt < 10; eraseIt++);
			eelLengths.erase(eelLengths.begin(), eraseIt);
		}
		
		{
			vector<int>::iterator eraseIt = eelLengths.begin();
			for(; eraseIt < eelLengths.end() && *eraseIt == 10; eraseIt++, result++);
			eelLengths.erase(eelLengths.begin(), eraseIt);
		}

		for(unsigned int i = 0; i < eelLengths.size(); i++) {
			if((eelLengths[i]%10) == 0 && eelLengths[i]/10-1 <= maxCuts) {
				result += eelLengths[i] / 10;
				maxCuts -= eelLengths[i] /10 - 1;
				eelLengths.erase(eelLengths.begin() + i);
				i--;
			}
		}
		
		unsigned int count = 0;
		for(unsigned int i = 0; i < eelLengths.size(); i++) {
			count += eelLengths[i]/10;
		}
		result += std::min(count, static_cast<unsigned int>(maxCuts));
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {13, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {34, 10, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {30, 50, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 350; int Arg2 = 16; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {160, 60, 10, 30, 200, 60, 100, 180, 200, 100, 170, 180, 60, 200, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 163; int Arg2 = 175; verify_case(4, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	Cut ___test;
	___test.run_test(-1);
	::getchar();
	return 0;
}
// END CUT HERE

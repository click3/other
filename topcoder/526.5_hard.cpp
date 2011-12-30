
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

class MagicNaming {
public:
	std::string magicName;
	std::vector<std::vector<std::pair<std::string, int> > > memo;
	int impl(unsigned int start, std::string &ret, const std::string &last = std::string()) {
		if(start == magicName.size()) {
			const int result = 0;
			memo[start].push_back(std::make_pair(last, result));
			return result;
		}
		int result = INT_MIN;
		std::string resultString;
		for(unsigned int i = 1; start + i <= magicName.size(); i++) {
			const std::string curString = magicName.substr(start, i);
			
			if(!last.empty()) {
				const unsigned int len = std::min(i, last.size());
				const int compareResult = last.compare(0, len, curString, 0, len);
				if(compareResult > 0 || (compareResult == 0 && last.size() < curString.size())) {
					if(last.size() > i && compareResult == 0) {
						continue;
					}
					break;
				}
			}
			/*
			const int compareResult = last.compare(0, i, curString, 0, i);
			if(compareResult > 0 || (compareResult == 0 && last.size() > curString.size())) {
				if(last.size() > i && compareResult == 0) {
					continue;
				}
				break;
			}*/
			std::string retString;
			const int tmpResult = impl(start + i, retString, curString);
			if(tmpResult == INT_MIN) {
				continue;
			}
			const int curResult = tmpResult + 1;
			if(curResult > result) {
				resultString = curString + " " + retString;
			}
			result = std::max(result, curResult);
		}
		memo[start].push_back(std::make_pair(last, result));
		ret = resultString;
		return result;
	}
	int maxReindeers(string magicName) {
		this->magicName = magicName;
		memo.clear();
		memo.resize(magicName.size() + 1);
		std::string result;
		const int ret = impl(0, result);
		std::cout << result << std::endl;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 2; verify_case(0, Arg1, maxReindeers(Arg0)); }
	void test_case_1() { string Arg0 = "babbaba"; int Arg1 = 2; verify_case(1, Arg1, maxReindeers(Arg0)); }
	void test_case_2() { string Arg0 = "philosophersstone"; int Arg1 = 5; verify_case(2, Arg1, maxReindeers(Arg0)); }
	void test_case_3() { string Arg0 = "knuthmorrispratt"; int Arg1 = 7; verify_case(3, Arg1, maxReindeers(Arg0)); }
	void test_case_4() { string Arg0 = "acrushpetrtourist"; int Arg1 = 7; verify_case(4, Arg1, maxReindeers(Arg0)); }
	void test_case_5() { string Arg0 = "zzzzz"; int Arg1 = 5; verify_case(5, Arg1, maxReindeers(Arg0)); }
	void test_case_6() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 50; verify_case(6, Arg1, maxReindeers(Arg0)); }
	void test_case_7() { string Arg0 = "babaaaba"; int Arg1 = 2; verify_case(7, Arg1, maxReindeers(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	MagicNaming ___test;
	___test.run_test(1);
	::getchar();
	return 0;
}
// END CUT HERE

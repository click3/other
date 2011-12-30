#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits.h>

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

using namespace std;

class P8XCoinChangeAnother {
public:
	vector<long long int> solve(int N, const long long coins_sum, const long long coins_count) {
		std::vector<unsigned long long int> coins;
		for(unsigned long long int i = 0, value = 1; i < N; i++, value <<= 1) {
			coins.push_back(value);
		}
		std::vector<long long int> result(N);
		long long int sumValue = coins_sum;
		for(int i = result.size() - 1; sumValue > 0 && i >= 0; i--) {
			const unsigned long long int count = sumValue / coins[i];
			result[i] = count;
			sumValue -= coins[i] * count;
		}
		const unsigned long long int minCount = std::accumulate(result.begin(), result.end(), 0LL);
		if(coins_count < minCount) {
			return vector<long long int>();
		}
		unsigned long long int upCount = coins_count - minCount;
		for(unsigned int i = result.size() - 1; i > 0; i--) {
			if(result[i] > upCount) {
				result[i] -= upCount;
				result[i - 1] += upCount * 2;
				break;
			} else {
				upCount -= result[i];
				result[i - 1] += result[i] * 2;
				result[i] = 0;
			}
		}
		const unsigned long long int lastCount = std::accumulate(result.begin(), result.end(), 0LL);
		if(coins_count != lastCount) {
			return vector<long long int>();
		}
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; long long Arg2 = 3LL; long Arr3[] = {2, 1 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 6LL; long long Arg2 = 3LL; long Arr3[] = {0, 3, 0 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; long long Arg1 = 8LL; long long Arg2 = 1LL; vector<long long> Arg3; verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; long long Arg1 = 10000000000LL; long long Arg2 = 10000000000LL; long long Arr3[] = {10000000000 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 58; long long Arg1 = 576460752303423487LL; long long Arg2 = 58LL; vector<long long> Arg3; verify_case(4, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 30; long long Arg1 = 481822894139105859LL; long long Arg2 = 893324030869997217LL; vector<long long> Arg3; verify_case(5, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	P8XCoinChangeAnother ___test;
	___test.run_test(5);
	::getchar();
	return 0;
}
// END CUT HERE

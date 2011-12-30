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

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(*a))
#endif

using namespace std;

class Mosquitoes {
public:
	int getMaximum(const vector<int> xInit, const vector<int> v, const int R) {
		const unsigned int bomb = R * 2;
		std::vector<double> minTimeBaseList;
		std::vector<double> minTimeDivList;
		std::vector<double> maxTimeBaseList;
		std::vector<double> maxTimeDivList;
		std::vector<int> minIndex;
		for(unsigned int i = 0; i < v.size() - 1; i++) {
			for(unsigned int j = i + 1; j < v.size(); j++) {
				const unsigned int b = xInit[i] > xInit[j] ? i : j;
				const unsigned int s = b == i ? j : i;
				const int curDis = xInit[b] - xInit[s];
				const int speed = v[b] - v[s];
				if(curDis > bomb && speed >= 0) {
					continue;
				}
				if(curDis <= bomb) {
					minTimeBaseList.push_back(0);
					minTimeDivList.push_back(1);
				} else {
					minTimeBaseList.push_back(curDis - bomb);
					minTimeDivList.push_back(-speed);
				}
				if(speed < 0) {
					maxTimeBaseList.push_back(curDis + bomb);
					maxTimeDivList.push_back(-speed);
				} else if(speed > 0) {
					maxTimeBaseList.push_back(bomb - curDis);
					maxTimeDivList.push_back(speed);
				} else {
					maxTimeBaseList.push_back(201);
					maxTimeDivList.push_back(1);
				}
				minIndex.push_back(s);
			}
		}
		unsigned int result = 1;
		for(unsigned int i = 0; i < minTimeBaseList.size(); i++) {
			unsigned int curResult = 0;
			for(unsigned int j = 0; j < v.size(); j++) {
				const double pos = xInit[j] + v[j] * minTimeBaseList[i] / minTimeDivList[i];
				if(xInit[minIndex[i]] + v[minIndex[i]] * minTimeBaseList[i] / minTimeDivList[i] <= pos + std::numeric_limits<double>::epsilon()
					&& pos - std::numeric_limits<double>::epsilon() <= xInit[minIndex[i]] + static_cast<int>(bomb) + v[minIndex[i]] * minTimeBaseList[i] / minTimeDivList[i])
				{
					curResult++;
				}
			}
			result = std::max(result, curResult);
			curResult = 0;
			for(unsigned int j = 0; j < v.size(); j++) {
				const double pos = xInit[j] + v[j] * maxTimeBaseList[i] / maxTimeDivList[i];
				if(xInit[minIndex[i]] + v[minIndex[i]] * maxTimeBaseList[i] / maxTimeDivList[i] <= pos + std::numeric_limits<double>::epsilon()
					&& pos - std::numeric_limits<double>::epsilon() <= xInit[minIndex[i]] + static_cast<int>(bomb) + v[minIndex[i]] * maxTimeBaseList[i] / maxTimeDivList[i])
				{
					curResult++;
				}
			}
			result = std::max(result, curResult);
		}
		unsigned int a = R + result;
		return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 2; verify_case(0, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, -100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 1; verify_case(1, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, -1, 10, -11, 99, -99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1, -3, 3, 47, -47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 1; verify_case(3, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {12,34,56,78,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,-3,4,-5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(4, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 50; verify_case(5, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {2, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(6, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {18, -1, -9, 15, 10, -55, 27, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-31, -7, 0, -28, -20, 56, -42, -4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 8; verify_case(7, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_8() { int Arr0[] = {78, 79, -25, 42, -20, -70, -79, 52, -98, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {85, -3, -36, -54, -96, 66, 27, 72, -11, -40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 3; verify_case(8, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_9() { int Arr0[] = {-8, -32, 46, -53, 58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22, 55, -88, 98, -99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 5; verify_case(9, Arg3, getMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	Mosquitoes ___test;
	___test.run_test(-1);
	::getchar();
	return 0;
}
// END CUT HERE

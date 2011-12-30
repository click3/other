#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

class MyDouble {
private:
	double abs;
	double base;
	double mul;
	double div;
public:
	MyDouble() : abs(0), base(1), mul(1), div(1) { }
	MyDouble(const double base) : abs(0), base(base), mul(1), div(1) { }
	MyDouble(const MyDouble &other) : abs(other.abs), base(other.base), mul(other.mul), div(other.div) { }
	MyDouble &AddBase(const double value) {
		this->base += value;
		return *this;
	}
	MyDouble AddBaseT(const double value) const {
		MyDouble result = *this;
		return result.AddBase(value);
	}
	MyDouble &AddAbs(const double value) {
		this->abs += value;
		return *this;
	}
	MyDouble AddAbsT(const double value) const {
		MyDouble result = *this;
		return result.AddAbs(value);
	}
	MyDouble &operator*=(const double value) {
		this->mul *= value;
		return *this;
	}
	MyDouble operator*(const double value) const {
		MyDouble result = *this;
		result *= value;
		return result;
	}
	MyDouble &operator/=(const double value) {
		this->div *= value;
		return *this;
	}
	MyDouble operator/(const double value) const {
		MyDouble result = *this;
		result /= value;
		return result;
	}
	bool operator<(const double value) const {
		return Calc() - std::numeric_limits<double>::epsilon() < value;
	}
	bool operator<=(const double value) const {
		return *this < value || *this == value;
	}
	bool operator>(const double value) const {
		return Calc() + std::numeric_limits<double>::epsilon() > value;
	}
	bool operator>=(const double value) const {
		return *this > value || *this == value;
	}
	bool operator==(const double value) const {
		return Calc() == value || (*this < value && *this > value);
	}
	bool operator<(const MyDouble &value) const {
		return Calc() - std::numeric_limits<double>::epsilon() < value.Calc();
	}
	bool operator<=(const MyDouble &value) const {
		return *this < value || *this == value;
	}
	bool operator>(const MyDouble &value) const {
		return Calc() + std::numeric_limits<double>::epsilon() > value.Calc();
	}
	bool operator>=(const MyDouble &value) const {
		return *this > value || *this == value;
	}
	bool operator==(const MyDouble &value) const {
		return Calc() == value.Calc() || (*this < value && *this > value);
	}
	double Calc() const {
		return this->abs + this->base * this->mul / this->div;
	}
};

using namespace std;

class Mosquitoes {
public:
	int getMaximum(const vector<int> xInit, const vector<int> v, const int R) {
		const unsigned int bomb = R * 2;
		std::vector<MyDouble> minTimeList;
		std::vector<MyDouble> minStartList;
		std::vector<MyDouble> maxTimeList;
		std::vector<MyDouble> maxStartList;
		for(unsigned int i = 0; i < v.size() - 1; i++) {
			for(unsigned int j = i + 1; j < v.size(); j++) {
				const unsigned int b = xInit[i] > xInit[j] ? i : j;
				const unsigned int s = b == i ? j : i;
				const int curDis = xInit[b] - xInit[s];
				const int speed = v[b] - v[s];
				if(curDis > bomb && speed >= 0) {
					continue;
				}
				MyDouble minT = 1;
				MyDouble maxT = 1;
				if(curDis <= bomb) {
					minT = 0;
				} else {
					minT = minT * (curDis - bomb) / -speed;
				}
				if(speed < 0) {
					maxT = maxT * (curDis + bomb) / -speed;
				} else if(speed > 0) {
					maxT = maxT * (bomb - curDis) / speed;
				} else {
					maxT = 201;
				}
				minTimeList.push_back(minT);
				maxTimeList.push_back(maxT);
				minStartList.push_back((minT * v[s]).AddAbsT(xInit[s]));
				maxStartList.push_back((maxT * v[s]).AddAbsT(xInit[s]));
			}
		}
		unsigned int result = 1;
		for(unsigned int i = 0; i < minTimeList.size(); i++) {
			unsigned int curResult = 0;
			for(unsigned int j = 0; j < v.size(); j++) {
				const MyDouble pos = (minTimeList[i] * v[j]).AddAbsT(xInit[j]);
				if(minStartList[i] <= pos && pos <= minStartList[i].AddAbsT(bomb))
				{
					curResult++;
				}
			}
			result = std::max(result, curResult);
			curResult = 0;
			for(unsigned int j = 0; j < v.size(); j++) {
				const MyDouble pos = (maxTimeList[i] * v[j]).AddAbsT(xInit[j]);
				if(maxStartList[i] <= pos && pos <= maxStartList[i].AddAbsT(bomb))
				{
					curResult++;
				}
			}
			result = std::max(result, curResult);
		}
		for(bool MY_FOREACH_BREAK_FLAG = false; !MY_FOREACH_BREAK_FLAG && true/*TODO*/;) {
			for(const int &a = 0/*TODO*/; MY_FOREACH_BREAK_FLAG = !MY_FOREACH_BREAK_FLAG; ) {
			}
		}
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

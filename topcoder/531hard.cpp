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

class KingdomReorganization {
public:
	unsigned int cost;
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		cost = 0;
		while (true) {
			const bool result = getCostimpl(kingdom, build, destroy);
			if (result) {
				return cost;
			}
		}
	}
	bool getCostimpl(std::vector<std::string> &kingdom, std::vector<std::string> build, std::vector<std::string> destroy) {
		const unsigned int N = kingdom.size();
		std::vector<std::vector<unsigned int> > destroyCost(N, std::vector<unsigned int>(N));
		std::vector<std::vector<unsigned int> > buildCost(N, std::vector<unsigned int>(N));
		for (unsigned int i = 0; i < N; i++) {
			for (unsigned int l = 0; l < N; l++) {
				destroyCost[i][l] = ::islower(destroy[i][l]) != 0 ? 26 + destroy[i][l] - 'a' : destroy[i][l] - 'A';
				buildCost[i][l] = ::islower(build[i][l]) != 0 ? 26 + build[i][l] - 'a' : build[i][l] - 'A';
			}
		}
		std::vector<unsigned int> groupIdList(N);
		std::vector<std::vector<unsigned int> > routeList(N);
		std::vector<unsigned int> waitList;
		std::vector<std::vector<unsigned int> > waitListRoute;
		unsigned int curId = 0;
		for (unsigned int i = 0; i < N; i++) {
			if (groupIdList[i] != 0) {
				continue;
			}
			curId++;
			waitList.push_back(i);
			waitListRoute.push_back(std::vector<unsigned int>());
			while (!waitList.empty()) {
				std::vector<unsigned int> route = waitListRoute.back();
				const unsigned int curKingdom = waitList.back();
				waitList.pop_back();
				waitListRoute.pop_back();
				route.push_back(curKingdom);
				if (groupIdList[curKingdom] != 0) {
					unsigned int minIndex[2];
					unsigned int min = UINT_MAX;
					for (unsigned int l = 0; l < route.size()-1; l++) {
						const std::vector<unsigned int>::iterator it = std::find(routeList[curKingdom].begin(), routeList[curKingdom].end(), route[l]);
						if (it != routeList[curKingdom].end()) {
							for (; l < route.size() - 1; l++) {
								const unsigned int cur = destroyCost[route[l]][route[l+1]];
								if (cur < min) {
									min = cur;
									minIndex[0] = route[l];
									minIndex[1] = route[l+1];
								}
							}
							unsigned int j = std::distance(it, routeList[curKingdom].begin());
							for (; j < routeList[curKingdom].size() - 1; j++) {
								const unsigned int cur = destroyCost[routeList[curKingdom][j]][routeList[curKingdom][j+1]];
								if (cur < min) {
									min = cur;
									minIndex[0] = routeList[curKingdom][j];
									minIndex[1] = routeList[curKingdom][j+1];
								}
							}
							cost += min;
							kingdom[minIndex[1]][minIndex[0]] = '0';
							kingdom[minIndex[0]][minIndex[1]] = '0';
							return false;
						}
					}
				}
				groupIdList[curKingdom] = curId;
				routeList[curKingdom] = route;
				for (unsigned int l = 0; l < N; l++) {
					if (kingdom[curKingdom][l] == '1' && (route.size() < 2 || *(route.end() - 2) != l)) {
						waitList.push_back(l);
						waitListRoute.push_back(route);
					}
				}
			}
		}
		while (true) {
			unsigned int minIndex[2];
			unsigned int minCost = UINT_MAX;
			for (unsigned int i = 0; i < N; i++) {
				for (unsigned int l = 0; l < N; l++) {
					if (i == l || groupIdList[i] == groupIdList[l] || minCost <= buildCost[i][l]) {
						continue;
					}
					minCost = buildCost[i][l];
					minIndex[0] = i;
					minIndex[1] = l;
				}
			}
			if (minCost == UINT_MAX) {
				break;
			}
			const unsigned int mergeGroupId[2] = {groupIdList[minIndex[0]], groupIdList[minIndex[1]]};
			for (unsigned int i = 0; i < N; i++) {
				if (groupIdList[i] == mergeGroupId[0]) {
					groupIdList[i] = mergeGroupId[1];
				}
			}
			cost += minCost;
		}
		return true;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABD","BAC","DCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABD","BAC","DCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"011","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABD","BAC","DCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABD","BAC","DCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"011000","101000","110000","000011","000101","000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(2, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0001","0001","0001","1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AfOj","fAcC","OcAP","jCPA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AWFH","WAxU","FxAV","HUVA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 65; verify_case(5, Arg3, getCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	KingdomReorganization ___test;
	___test.run_test(5);
	::getchar();
	return 0;
}
// END CUT HERE

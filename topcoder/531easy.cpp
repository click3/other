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

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(*a))
#endif

using namespace std;

class UnsortedSequence {
public:
	vector <int> getUnsorted(vector <int> s) {
		std::sort(s.begin(), s.end());
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != s.back()) {
				std::swap(s[i], s[i+1]);
				return s;
			}
		}
		return std::vector<int>();
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


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

class RainyRoad {
public:
	string isReachable(vector<string> road) {
		return isReachableImpl(road) ? "YES" : "NO";
	}
	bool isReachableImpl(vector<string> road) {
		for(unsigned int i = 0; i < road[0].size(); i++) {
			if(road[0][i] == 'W' && road[1][i] == 'W') {
				return false;
			}
		}
		return true;
	}
};

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

class MagicCandy {
public:
	int whichOne(int n) {
		std::vector<unsigned int> list;
		for(unsigned int i = 1; true; i++) {
			const unsigned int ps = i * i;
			if(ps > 1000000000) {
				break;
			}
			list.push_back(ps);
		}
		struct CountLastPSAndLess {
			const unsigned int lastPS;
			CountLastPSAndLess(const unsigned int lastPS) : lastPS(lastPS) {
			}
			bool operator()(const unsigned int n) const {
				return (n <= lastPS);
			}
		};
		unsigned int value = n;
		unsigned int result = n;
		while(true) {
			if(value < 4) {
				return result;
			}
			if(value == 4 || value == 6 || value == 8) {
				return result - 1;
			}
			if(value < 9) {
				return result;
			}
			unsigned int lastPSIndex = UINT_MAX;
			for(unsigned int i = 0; i < list.size(); i++) {
				if(list[i] > value) {
					lastPSIndex = i - 1;
					break;
				}
			}
			if(lastPSIndex == UINT_MAX) {
				lastPSIndex = list.size() - 1;
			}
			const unsigned int lastPS = list[lastPSIndex];
			unsigned int count = 0;
			for(unsigned int i = 0; i < list.size(); i++) {
				if(list[i] > lastPS) {
					break;
				}
				count++;
			}
			if(lastPS == value) {
				value -= count;
				result--;
				continue;
			}
			const unsigned int m = static_cast<unsigned int>(::ceil(static_cast<double>(value - lastPS) / count));
			value -= count * m;
		}
		return 0;
	}
};

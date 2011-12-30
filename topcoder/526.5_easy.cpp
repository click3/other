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

class MagicStonesStore {
public:
	bool isPrime(const int n) {
		if(n < 2) {
			return false;
		}
		if(n == 2) {
			return true;
		}
		if((n%2) == 0) {
			return false;
		}
		for(unsigned int i = 3; i * i <= n; i+=2) {
			if((n%i) == 0) {
				return false;
			}
		}
		return true;
	}
	string ableToDivide(int n) {
		for(unsigned int i = 2; i <= n; i++) {
			if(isPrime(i) && (i == 0 || isPrime(i))) {
				return "YES";
			}
		}
		return "NO";
	}
};

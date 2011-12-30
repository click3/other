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

class P8XMatrixTransformation {
public:
	static unsigned int CountOne(const std::vector<std::string> &str) {
		unsigned result = 0;
		for(unsigned int i = 0; i < str.size(); i++) {
			for(unsigned int j = 0; j < str[i].size(); j++) {
				if(str[i][j] == '1') {
					result++;
				}
			}
		}
		return result;
	}
	std::string solve(std::vector<std::string> original, std::vector<std::string> target) {
		return CountOne(original) == CountOne(target) ? "YES" : "NO";
	}
};
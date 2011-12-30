
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

class MagicalSquare {
public:
	long long getCount(vector <string> rowStrings, vector <string> columnStrings) {
		const char *row[3];
		const char *col[3];
		unsigned int row_sizes[3];
		unsigned int col_sizes[3];
		for(unsigned int i = 0; i < 3; i++) {
			row[i] = rowStrings[i].c_str();
			row_sizes[i] = rowStrings[i].size();
			col[i] = columnStrings[i].c_str();
			col_sizes[i] = columnStrings[i].size();
		}
		unsigned long long result = 0;
		for(unsigned int x1 = 0; x1 <= row_sizes[0]; x1++) {
			if(x1 > 0 && row[0][x1-1] != col[0][x1-1]) {
				break;
			}
			for(unsigned int x2 = 0; x1 + x2 <= row_sizes[0]; x2++) {
				const unsigned int x5 = row_sizes[0] - (x1 + x2);
				if(x2 > 0 && row[0][x1 + x2-1] != col[1][x2-1]) {
					break;
				}
				if(::strncmp(&row[0][x1 + x2], &col[2][0], x5) != 0) {
					continue;
				}
				for(unsigned int x3 = 0; x3 <= row_sizes[1]; x3++) {
					if(x3 > 0 && row[1][x3-1] != col[0][x1 + x3-1]) {
						break;
					}
					for(unsigned int x4 = 0; x3 + x4 <= row_sizes[1]; x4++) {
						const unsigned int x6 = row_sizes[1] - (x3 + x4);
						if(x4 > 0 && row[1][x3 + x4-1] != col[1][x2 + x4-1]) {
							break;
						}
						if(::strncmp(&row[1][x3 + x4], &col[2][x5], x6) != 0) {
							continue;
						}
						int x7 = col_sizes[0] - x1 - x3;
						if(::strncmp(&row[2][0], &col[0][x1 + x3], x7) == 0) {
							const unsigned int x8 = col_sizes[1] - x2 - x4;
							if(::strncmp(&row[2][x7], &col[1][x2 + x4], x8) == 0) {
								if(::strcmp(&row[2][x7 + x8], &col[2][x5 + x6]) == 0) {
									result++;
								}
							}
						}
					}
				}
			}
		}
		return result;
	}
};


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

class DropCoins {
public:
	vector<string> board;
	int max_x;
	int max_y;
	int sum(int x1, int y1, int x2, int y2) {
		int result = 0;
		for(int x = x1; x <= x2; x++) {
			for(int y = y1; y <= y2; y++) {
				if(board[x][y] == 'o') {
					result++;
				}
			}
		}
		return result;
	}
	int countMove(int x1, int y1, int x2, int y2) {
		const int xMinDis = min(x1, max_x - x2);
		const int xMaxDis = max(x1, max_x - x2);
		const int yMinDis = min(y1, max_y - y2);
		const int yMaxDis = max(y1, max_y - y2);
		return yMinDis * 2 + yMaxDis + xMinDis * 2 + xMaxDis;
	}
	int getMinimum(vector<string> board, int k) {
		this->board = board;
		max_x = board.size() - 1;
		max_y = board[0].size() - 1;
		if(sum(0,0, max_x, max_y) < k) {
			return -1;
		}
		if(sum(0, 0, max_x, max_y) == k) {
			return 0;
		}
		int result = INT_MAX;
		if(k == 0) {
			result = min(max_x, max_y);
		}
		for(int x1 = 0; x1 <= max_x; x1++) {
			for(int x2 = max_x; x2 >= x1; x2--) {
				for(int y1 = 0; y1 <= max_y; y1++) {
					for(int y2 = max_y; y2 >= y1; y2--) {
						if(sum(x1, y1, x2, y2) == k) {
							result = min(result, countMove(x1, y1, x2, y2));
						}
					}
				}
			}
		}
		if(result == INT_MAX) {
			result = -1;
		}
		return result;
	}
};

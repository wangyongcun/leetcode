#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <map>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<int> degree(numCourses, 0);
	vector<vector<int>> adjacent(numCourses, vector<int>());
	queue<int> degree0;
	
	for (auto edge :prerequisites){
		degree[edge[0]] ++;
		adjacent[edge[1]].push_back(edge[0]);
	}

	for (int i = 0; i < numCourses;++i) {
		if (degree[i] == 0){
			degree0.push(i);
		}
	}

	while (! degree0.empty()){
		int d0 = degree0.front();
		degree0.pop();
		numCourses--;
		for (auto a :adjacent[d0])
		{
			degree[a] --;
			if (degree[a] == 0){
				degree0.push(a);
			}
		}
	}

	return  numCourses == 0;
}

void test_leet207() {
	int n = 2;
	vector<vector<int>> vv= { {1, 0} };
	vector<vector<int>> vv2 = { {1, 0},{0, 1} };
	printf("%d", canFinish(5,vv));
	printf("%d", canFinish(5, vv2));
}



#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <map>
using namespace std;

bool dfs(vector<vector<int>>& graph,int cur,int pre,vector<bool>& visited) {
	if (visited[cur]){
		return false;
	}

	visited[cur] = true;

	for (auto node : graph[cur])
	{
		if (node != pre){
			bool re = dfs(graph, node, cur, visited);
			if (re == false) {
				return false;
			}
		}
	}

	return true;
}

int validTree(int n, vector<vector<int>>& edges) {
	if (n == 0){
		return true;
	}

	vector<vector<int>> graphic = vector<vector<int>>(n, vector<int>());
	vector<bool> vistied = vector<bool>(n, 0);
	for (auto edge : edges)
	{
		graphic[edge[0]].push_back(edge[1]);
		graphic[edge[1]].push_back(edge[0]);
	}

	bool re = dfs(graphic, 0, -1,vistied);
	if (re == false){
		return false;
	}

	for (auto v :vistied)
	{
		if (v == false){
			return false;
		}
	}

	return true;
}

void test_leet261() {
	vector<vector<int>> v = { {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} };
	vector<vector<int>> v2 = {{0, 1}, { 0, 2}, { 0, 3 }, { 1, 4 }};
	vector<vector<int>> v3 = { {0, 1},{0, 4},{1, 4},{2, 3} };
	vector<vector<int>> v4 = { {0, 1},{0, 2},{0, 3},{1, 4} };
	//printf("%d", GraphValidTree(v));
	printf("%d", validTree(5,v4));
}



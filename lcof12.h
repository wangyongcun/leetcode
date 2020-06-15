#include <vector>
#include <string>
using namespace std;
///buggy forget vector<vector<bool>> vt  reference symbol&
bool tr(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& vt, string& word,int nBegin) {

	///bug error dirction difine {-1,-1} in vector
	vector<vector<int>> dirction = { {-1,0},{0,-1},{1,0},{0,1 } };
	if (word[nBegin] == board[i][j]){
		if (nBegin == word.size()-1){
			return true;
		}

		//printf("set i,j %d,%d visited ", i, j);
		vt[i][j] = 1;

		for (int m=0;m<dirction.size();++m)
		{
			int newI = i + dirction[m][0];
			int newJ = j + dirction[m][1];
			///buggy  newI < board.size()-1 
			/// newI <= board.size()-1
			if (newI >=0 && newI <= board.size()-1
				&& newJ >=0 && newJ <= board[0].size()-1
				&& vt[newI][newJ] == 0
				){
				//printf("visit %d,%d", newI, newJ);
				bool  b= tr(board, newI, newJ, vt, word, nBegin + 1);
				if (b){
					return true;
				}
			}
		}
		//printf("unset i,j %d,%d visited \n", i, j);
		vt[i][j] = 0;
	}
	else
	{
		//printf("unset i,j %d,%d visited \n", i, j);
		vt[i][j] = 0;
		return false;
	}
}

bool exist(vector<vector<char>>& board, string word) {

	vector<vector<bool>> visited;
	for (int i = 0; i < board.size(); ++i)
	{
		vector<bool> vt;
		for (int j = 0; j < board[i].size(); ++j)
		{
			vt.push_back(false);
		}
		visited.push_back(vt);
	}

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			/// bug
			/// return tr(board, i, j, visited, word, 0);
			/// only when find can return,otherwise try another beg
			bool b= tr(board, i, j, visited, word, 0);
			if(b)
			{
				return b;
			}
		}
	}
}

void test_lcof12() {
	vector<vector<char>> board = { 
		{'A', 'B', 'C', 'E'}, 
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'} };
	string word = "ABCCED";
	printf("\n find result:%d", exist(board, word));

	word = "BFDE";
	printf("\n find result:%d", exist(board, word));
}
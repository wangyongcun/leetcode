
#include <stack>
using namespace std;

class CQueue {
private:
	stack<int> s1;
	stack<int> s2;
public:
	CQueue() {

	}

	void appendTail(int value) {
		s1.push(value);
	}

	int deleteHead() {
		if (s1.empty() && s2.empty()){
			return -1;
		}
		else {
			if (s2.empty()){
				while (!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}
			}

			int t = s2.top();
			s2.pop();
			return t;
		}
	}
};

void test_lcof09() {

}
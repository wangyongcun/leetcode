#include <stack>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */

	stack<int> data;
	stack<int> minS;

	MinStack() {

	}

	void push(int x) {
		data.push(x);
		if (minS.size() == 0){
			minS.push(x);
		}
		else {
			if (x <= minS.top())
			{
				minS.push(x);
			}
		}
	}

	void pop() {
		if (data.size() > 0) {
			
			if (data.top() == minS.top()){
				minS.pop();
			}

			data.pop();
		}
	}

	int top() {
		return data.top();
	}

	int min() {
		return minS.top();
	}
};

void test_lcof30(){
	MinStack* obj = new MinStack();
	obj->push(1);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->min();
}
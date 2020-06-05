
#include <stack>
using namespace std;

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int f0 = 0;
	int f1 = 1;
	int i = 2;
	int fn = 0;
	while (i <= n) {
		fn = (f0 + f1) % 1000000007;
		f0 = f1;
		f1 = fn;
		++i;
	}
	return fn;
}
void test_lcof10() {

}
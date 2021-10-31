#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, a, b; //维数，a,b向量的非零值个数
	cin >> n >> a >> b;
	map<int, int> mp;
	int pos, val;
	long long int result = 0; //最终结果
	for (int i = 0; i < a; ++i)
	{
		cin >> pos;
		cin >> val;
		mp[pos] = val;
	}
	for (int i = 0; i < b; ++i)
	{
		cin >> pos;
		cin >> val;
		if (mp[pos] != 0)
			result += (mp[pos] * val);
	}
	cout << result << endl;
	return 0;
}
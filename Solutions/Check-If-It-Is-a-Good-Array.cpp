/* 查看了维基百科 <裴蜀定理> */
/* 当且仅当 m 是 a, b 的最大公约数的倍数，ax + by = m 才有解, 此题中 m = 1，因此就是判断 a 和 b 互质 */

class Solution{
public:
	int gcd(int a, int b) {
		return a == 0 ? b : gcd(b % a, a);
	};
	bool isGoodArray(vector<int>& nums) {
		int a = nums[0];
		for (auto num: nums)
			a = gcd(a, num);
		return a == 1;
	};
};
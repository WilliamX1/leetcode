/* 我们使用栈把字符串中的括号依次压栈，每次压栈的规则是
* 如果栈为空，则直接压栈。如果栈顶元素是左括号，且当前元素是右括号，刚好匹配，则探出栈顶元素且不压栈当前元素。否则，将当前元素压栈。最后的栈内所有元素就是要被移除的括号。
* 每次压栈时需要记录位置信息，以便后续删除对应字符串中的括号来获得新的合法字符串。
* 因此，可以压栈一个数字，如果是左括号则用负号，右括号则用正号，下标从 1 开始。
*/

/* 测试用例: s = "(d)(f))", ans = 1 */
/* 时间复杂度: O(N), 空间复杂度: O(N) */

class Solution{
public:
	string minRemoveToMakeValid(string s){
		stack<int> ele;
		for (int i = 0; i < s.size(); i++) 
			if (s[i] == '(') ele.push(-(i + 1));
			else if (s[i] == ')') {
				if (ele.empty()) ele.push(i + 1);
				else if (ele.top() < 0) ele.pop();
				else ele.push(i + 1);
			} else {};
		string ans = "";
		int cur_idx = s.size();
		
		while (!ele.empty()) {
			int last_idx = abs(ele.top()) - 1;
			ele.pop();
			ans = s.substr(last_idx + 1, cur_idx - last_idx - 1) + ans;
			cur_idx = last_idx;
		};
		ans = s.substr(0, cur_idx - 0) + ans;
		/*for (int i = s.size() - 1; i >= 0; i--) {
			if (!ele.empty() && abs(ele.top()) - 1 == i) {
				ele.pop();
			} else {
				ans = s[i] + ans;
			};
		};*/
		return ans;
	};
};
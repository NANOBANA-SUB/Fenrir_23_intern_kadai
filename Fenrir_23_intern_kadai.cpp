#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string bracketString)
	{
		//スタックを採用することにより左括弧を追跡して一致するかどうかを確認したい。
		
		stack<char> bracketStack;//スタックの初期化

		for (char currentChar : bracketString)
		{
			//入力文字列を走査し左括弧の場合はプッシュ
			if (currentChar == '(' || currentChar == '{' || currentChar == '[')
			{
				bracketStack.push(currentChar);
			}
			//右括弧の場合、スタックが空の場合は左括弧がないためfalse。
			//それ以外の場合、スタックからポップし、現在の括弧に対応する括弧があるかを判定
			//一致しない場合はfalseを返す
			else
			{
				if (bracketStack.empty() ||
					(currentChar == ')' && bracketStack.top() != '(') ||
					(currentChar == '}' && bracketStack.top() != '{') ||
					(currentChar == ']' && bracketStack.top() != '['))
				{
					return false;
				}
				bracketStack.pop();
			}
		}
		//入力文字列を走査した後、スタックが空の場合はすべての括弧が一致していたことになるのでこれで完了となる。
		return bracketStack.empty();
	}
};

int main()
{
	Solution solution;
	string input;
	cout << "s=";
	cin >> input;
	bool result = solution.isValid(input);
	if (result)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}

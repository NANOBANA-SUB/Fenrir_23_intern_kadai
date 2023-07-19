#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValid(const string& bracketString)
    {
        //ハッシュマップを採用しif文をスッキリさせた

        stack<char> bracketStack; // スタックの初期化
        unordered_map<char, char> brackets = { {')', '('}, {'}', '{'}, {']', '['} }; // 対応する括弧を保存するマップ

        // 入力文字列を走査
        for (const char& currentChar : bracketString)
        {
            // 右括弧の場合、スタックが空か、スタックのトップが対応する括弧でない場合は、falseを返す
            if (brackets.count(currentChar)) {
                if (bracketStack.empty() || bracketStack.top() != brackets[currentChar]) {
                    return false;
                }
                bracketStack.pop();
            }
            // 左括弧の場合、それをスタックにプッシュ
            else {
                bracketStack.push(currentChar);
            }
        }
        // 入力文字列を走査した後、スタックが空なら、全ての括弧が一致していたと言える
        return bracketStack.empty();
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "s=";
    cin >> input; // 入力
    bool result = solution.isValid(input); // 括弧の組み合わせが有効かどうかを確認
    cout << (result ? "true" : "false") << endl; // 結果を出力

    return 0;
}

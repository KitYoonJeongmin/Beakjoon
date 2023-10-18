#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int N, K, cnt = 0;
	cin >> N >> K;
	cin >> s;
	stack<char> st;
	stack<char> st2;
	for (int i = 0; i < s.size(); i++)
	{
        //i번째 원소보다 작은것을 pop
        while (!st.empty() && cnt < K && s[i] > st.top())
        {
            cnt++;
            st.pop();
        }
        st.push(s[i]);
    }
    while (cnt < K) //남은 빼야되는 횟수만큼 pop
    {
        cnt++;
        st.pop();
    }
    //stack이니깐 역방향으로 출력
    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }
    while (!st2.empty())
    {
        cout << st2.top();
        st2.pop();
    }
	
	
	return 0;
}
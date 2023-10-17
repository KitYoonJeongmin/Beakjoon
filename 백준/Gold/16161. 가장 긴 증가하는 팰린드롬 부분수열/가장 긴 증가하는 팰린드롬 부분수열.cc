
#include <bits/stdc++.h>
using namespace std;

int N, val;
vector<int> A;

//! 팰린드롬의 길이를 구한다.
//! 첫 실행시, A[left]==A[right]가 보장되어야 함.
int palindrome(int left, int right){
        int len  = (left==right? 1 : 2);
        int prev = A[left]; //기준
        int s = left;
        int e = right;
        while(true){
                s--;
                e++;
                if(s==-1 || e==N || A[s]!=A[e] || prev<=A[s]) break;
                len+=2;

                //! 다음 요소는 더 작아야 함.
                prev = A[s];
        }
        return len;
}


int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N;
        for(int i=0; i<N; i++) {
                cin >> val;
                A.emplace_back(val);
        }
        A.push_back(0); // 마지막에는 dummy data 하나를 삽입.


        //정답의 크기는 항상 1보다 같거나 큼.
        int ans = 1;
        for(int i=0; i<N; i++){
                ans = max(ans, palindrome(i, i));// 1
                if(A[i] == A[i+1]) ans = max(ans, palindrome(i, i+1));//2 2
        }
        cout << ans;
}

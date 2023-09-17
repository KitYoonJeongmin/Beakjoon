//이분 탐색: 증가/감소중 한 경우에만 가능(1차 함수)
//삼분 탐색: 증가/감소가 공존하는 경우 가능(볼록, 2차함수)

//a: 첫 구간의 시작점의 좌표   b: 끝점의 좌표
// 1. 구간을 삼등분 하는 두 점을 mid1, mid2로 둠
// 2. f(mid1) > f(mid2) 일 때, [a, mid1]에는 최솟값이 존재할 수 없음 -> [mid1, b] 탐색
// 3. f(mid1) < f(mid2) 일 때, [mid2, b]에는 최솟값이 존재할 수 없음 -> [a, mid2] 탐색
// 1~3 을 반복
// 시간 복잡도: O(log N)

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<double, double> POS;

int a[2], b[2], c[2], d[2];

POS minho(double t)
{
	return {a[0] + (b[0] - a[0])*(t/100), a[1] + (b[1] - a[1])*(t/100)};
}

POS kangho(double t)
{
	return {c[0] + (d[0] - c[0])*(t/100), c[1] + (d[1] - c[1])*(t/100)};
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];
	cin >> d[0] >> d[1];
	
	double s = 0, e = 100, minRes = 20000, mid1, mid2;
	
	while(e-s >= 1e-6)
	{
		mid1 = (2*s+e)/3; // 1:2 위치
		mid2 = (s+2*e)/3; // 2:1 위치
		
		POS m_mid1 = minho(mid1);
		POS m_mid2 = minho(mid2);
		POS k_mid1 = kangho(mid1);
		POS k_mid2 = kangho(mid2);
		
		double mid1_time = pow(m_mid1.first - k_mid1.first, 2) + pow(m_mid1.second - k_mid1.second, 2);
		double mid2_time = pow(m_mid2.first - k_mid2.first, 2) + pow(m_mid2.second - k_mid2.second, 2);
		
		mid1_time = sqrt(mid1_time);
		mid2_time = sqrt(mid2_time);
		
		minRes = min(minRes, min(mid1_time, mid2_time));
		
		if(mid1_time > mid2_time) s = mid1;
		else e = mid2;
	}
	cout.precision(10);
	cout << minRes;
	
	return 0;
}


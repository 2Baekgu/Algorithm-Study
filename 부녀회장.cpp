#include <iostream>
using namespace std;

int main(){
    int T, n, k;
	cin >> T;
	int arr[15][15];
	arr[0][0] = 1;
	for (int i = 1; i<15; i++){
		arr[0][i] = i+1; // 0층에 쭉 2,3,4,5
		arr[i][0] = 1; // i 층 1호마다[0] 세로로 1을 쌓아줌
	}
	for (int i = 1; i<15; i++){
		for (int j = 1; j<15; j++){
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j]; //각 숫자가 더해지면서 바뀜
		}//[][j] 호수가 1부터 시작하지만 배열은 0부터 즉 0== 1호
	}
	for (int i = 0; i<T; i++){
		cin >> n >> k;
		cout << arr[n][k - 1] << endl;
	}
}
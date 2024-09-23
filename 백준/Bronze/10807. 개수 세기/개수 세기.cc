#include <iostream>

using namespace std;

int main() {

	int arr[201] = {0};
	int N, v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr[100 + x]++;
	}
	cin >> v;
	
	cout << arr[v + 100];

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	vector<vector<bool>> palindrome(n+1, vector<bool>(n+1, false));
	

	//길이가 1일 때
	for (int i = 1; i <=n; i++) {
		palindrome[i][i] = true;
	}

	//길이가 2일 때
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i + 1]) palindrome[i][i + 1] = true;
	}

	//길이 3이상
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <=n-i; j++) {
			//앞 뒤가 같고 가운데도 palindrome 이라면
			if (arr[j] == arr[j+i] && palindrome[j+1][j+i-1]) {
				palindrome[j][j+i] = true;
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << palindrome[s][e]<<"\n";
	}

}

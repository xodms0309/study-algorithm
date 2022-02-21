#include <iostream>
#include <algorithm>
#include <vector>	
using namespace std;

int main() {
	int N, K;
	cin >> N >>K;
	vector <int> coin(101);
	vector<int> DP(10001);
    DP[0] = 0;
    for (int i = 1; i <=N; i++) {
        cin >> coin[i];
        DP[coin[i]] = 1;
    }
    for (int i = 1; i <= K; i++) {
        DP[i] = 10001;
    }
    for (int i = 1; i <= N; i++){
        for (int j = coin[i]; j <= K; j++){
            DP[j] = min(DP[j], DP[j - coin[i]] + 1);
        }
    }

    if (DP[K] ==10001) cout << -1;
    else cout << DP[K];

}

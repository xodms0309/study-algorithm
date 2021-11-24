#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int M=maps[0].size();
    int N=maps.size();
    
    vector<vector<bool>> visited(N, vector<bool>(M,false));
    vector<vector<int>> dist(N, vector<int>(M));
    
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = {0, 0, -1, 1};
    
    visited[0][0]=true; 
    dist[0][0]=1;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()){
        pair <int, int> current=q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int nextX=current.first+dx[i];
            int nextY=current.second+dy[i];
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
				if (!visited[nextX][nextY] && maps[nextX][nextY]) {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
                    dist[nextX][nextY] = dist[current.first][current.second] + 1; 
				}
			}
        }
    }
    if (!visited[N-1][M-1]) return -1; 
    else return dist[N-1][M-1];
}

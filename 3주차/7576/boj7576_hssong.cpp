// 토마토
#include <iostream>
#include <queue>

using namespace std;

int M, N;
int graph[1001][1001];
queue<pair<int, int>> q;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (graph[nx][ny] == -1 || graph[nx][ny] == 1) continue;
			if (graph[nx][ny] == 0) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return;
}

int maxValue() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (max < graph[i][j]) {
				max = graph[i][j];
			}
			if (graph[i][j] == 0) return -1;
		}
	}
	return max - 1;
}

int main(void) {
	int check = 1;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) {
				check = 0;
			}
		}
	}
	if (check == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}
	bfs();
	cout << maxValue();
}
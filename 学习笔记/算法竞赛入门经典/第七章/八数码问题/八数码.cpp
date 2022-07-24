#include "bits/stdc++.h"
using namespace std;

constexpr int         MAX_STATE = 1000000;
typedef array<int, 9> State;
State                 st[MAX_STATE], goal;
int                   dist[MAX_STATE];
constexpr int         dx[]      = { -1, 1, 0, 0 };
constexpr int         dy[]      = { 0, 0, -1, 1 };

int BFS(){
	unordered_set<int> look_up_table;
	int                front = 1, rear = 2;
	while (front < rear) {
		State & s = st[front];

		// s 如果等于 goal 表示查找成功
		if (s == goal) {
			return front;
		}

		int z = int(find(s.begin(), s.end(), 0) - s.begin());
		int x = z / 3;
		int y = z % 3;

		// 四种移动方向
		for (int i = 0; i < 4; ++i) {

			// 计算出新的坐标
			int newx = x + dx[i];
			int newy = y + dy[i];
			int newz = newx * 3 + newy;

			if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {

				// 将该种状态保存在 rear 下
				State & t = st[rear];
				t = s;
				t[newz] = s[z];
				t[z]    = s[newz];

				// 更新步数
				dist[rear] = dist[front] + 1;

				int k = 0;
				for (int num : t) {
					k = k * 10 + num;
				}
				// 判断一下，是否是新状态，如果是 更新 rear，否则忽略本次结果
				if (look_up_table.find(k) == look_up_table.end()) {
					look_up_table.insert(k);
					rear++;
				}
			}
		}

		front ++;
	}
	return 0;
}

int main(){
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &st[1][i]);
	}
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &goal[i]);
	}

	int ans = BFS();
	if (ans > 0) {
		printf("%d\n", dist[ans]);
	}
	else {
		printf("-1\n");
	}
}
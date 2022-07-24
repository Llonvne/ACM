constexpr int maxn = 10000;
int vis[100][maxn];
int C[maxn];
int tot = 0;
int n;

void search(int cur){
	if (cur == n) {
		tot++;
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (!vis[0][i] && !vis[1][cur + 1] && !vis[2][cur - i + n]) {
				C[cur] = i;
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
				search(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
			}
		}
	}
}
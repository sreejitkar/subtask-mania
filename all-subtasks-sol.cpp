#include <bits/stdc++.h>

std::vector<std::vector<int>> g1;
std::vector<std::vector<int>> calcuatedCostGrid;

void takevectorinput(int n, int m) {
	g1.resize(n+1);
	calcuatedCostGrid.resize(n+1);
	for (int i=0; i<=n; i++) {
		g1[i].resize(m+1);
		calcuatedCostGrid[i].resize(m+1);
		if (i > 0) {
			for (int j=1; j<=m; j++) {
				std::cin >> g1[i][j];
			}
		}

	}
}

void calculateCostGrid() {
	for (int i=1; i<g1.size(); i++) {
		int zeroInitCost = 0;
		for (int j=1; j<g1[i].size(); j++) {
			if (g1[i][j] == 0) { zeroInitCost += 1; }
			calcuatedCostGrid[i][j] = zeroInitCost;
			if (i > 0) {
				calcuatedCostGrid[i][j] += calcuatedCostGrid[i-1][j];
			}
		}
	}
}


int query(int a, int b, int c, int d) {
    if (calcuatedCostGrid[c][d] - calcuatedCostGrid[a-1][d] - calcuatedCostGrid[c][b-1] + calcuatedCostGrid[a-1][b-1] > 0) return 0;
    return 1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m;
	takevectorinput(n, m);
	calculateCostGrid();
	std::cin >> q;
	while (q--) {
		int a, b, c ,d;
		std::cin >> a >> b >> c >> d;
		int totalcost = query(a, b, c, d);
		std::cout << totalcost << "\n";
	}
	return 0;
}

/**/
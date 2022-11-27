// #include <bits/stdc++.h>

// std::vector<std::vector<int>> g1;

// void takevectorinput(int m, int n) {
// 	int tmp=0;
// 	for (int i=1; i<=m; i++) {
// 		std::vector<int> store;
// 		for (int j=1; j<=n; j++)
// 		{
// 			std::cin >> tmp;
// 			store.push_back(tmp);
// 		}
// 		g1.push_back(store);
// 	}
// }

// int cheapestpath(std::pair<int, int> startingpoint, std::pair<int, int> endingpoint) {
	
// 	if (startingpoint.first == endingpoint.first && startingpoint.second == endingpoint.second) {
// 		return g1[startingpoint.first-1][startingpoint.second-1];
// 	}

// 	for (int i=startingpoint.first-1; i<=endingpoint.first-1; i++) {
// 		for (int j=startingpoint.second-1; j<=endingpoint.second-1; j++) {
// 			if (g1[i][j] == 1) { continue; }
// 			else { return 0; }
// 		}
// 	}
// 	return 1;
// }

// int main() {
// 	int m, n, q;
// 	std::cin >> m >> n;
// 	takevectorinput(m, n);
// 	std::cin >> q;
// 	while (q--) {
// 		int a, b, c ,d;
// 		std::cin >> a >> b >> c >> d;
// 		int totalcost = cheapestpath(std::make_pair(a,b), std::make_pair(c,d));
// 		std::cout << totalcost << "\n";
// 	}
// 	return 0;
// }


#include <bits/stdc++.h>

std::vector<std::vector<int>> g1;
std::vector<std::vector<int>> calcuatedCostGrid;

void takevectorinput(int n, int m) {
	g1.resize(n);
	calcuatedCostGrid.resize(n);
	for (int i=0; i<n; i++) {
		g1[i].resize(m);
		calcuatedCostGrid[i].resize(m);
		for (int j=0; j<m; j++) {
			std::cin >> g1[i][j];
		}
	}
}

void calculateCostGrid() {
	int zeroInitCost = 0;
	for (int i=0; i<g1.size(); i++) {
		for (int j=0; j<g1[i].size(); j++) {
			if (g1[i][j] == 0) { zeroInitCost += 1; }
			calcuatedCostGrid[i][j] = zeroInitCost;
		}
	}
}

void printGrid(std::vector<std::vector<int>> m1) {
	for (int i=0; i<m1.size(); i++) {
		for (int j=0; j<m1[i].size(); j++) {
			std::cout << m1[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int cheapestpath(std::pair<int, int> startingpoint, std::pair<int, int> endingpoint) {
	// std::cout << "ccg-start["<<startingpoint.first<<"]["<<startingpoint.second<<"] is " << calcuatedCostGrid[startingpoint.first][startingpoint.second] << "\n" << "ccg-end["<<endingpoint.first<<"]["<<endingpoint.second<<"] is " << calcuatedCostGrid[endingpoint.first][endingpoint.second] << "\n";
	if (g1[startingpoint.first][startingpoint.second] == 0 || g1[endingpoint.first][endingpoint.second] == 0) {
		// std::cout << "return 0 due to 0 at staring pos or ending pos\n";
		return 0;
	}
	if (calcuatedCostGrid[startingpoint.first][startingpoint.second] != calcuatedCostGrid[endingpoint.first][endingpoint.second]) {
		// std::cout << "return 0 due to ccg difference";
		return 0;
	}
	// std::cout << "return 1 here \n";
	return 1;
}

int main() {
	int n, m, q;
	std::cin >> n >> m;
	takevectorinput(n, m);
	calculateCostGrid();
	// std::cout << "\n\n";
	// printGrid(calcuatedCostGrid);
	std::cin >> q;
	while (q--) {
		// std::cout << "entering while q--\n";
		int a, b, c ,d;
		std::cin >> a >> b >> c >> d;
		// std::cout << "taking input of a b c d\n";
		int totalcost = cheapestpath(std::make_pair(a-1,b-1), std::make_pair(c-1,d-1));
		std::cout << totalcost << "\n";
	}
	return 0;
}
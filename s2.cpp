#include <bits/stdc++.h>

std::vector<std::vector<int>> g1;

void takevectorinput(int m, int n) {
	int tmp=0;
	for (int i=1; i<=m; i++) {
		std::vector<int> store;
		for (int j=1; j<=n; j++)
		{
			std::cin >> tmp;
			store.push_back(tmp);
		}
		g1.push_back(store);
	}
}

int cheapestpath(std::pair<int, int> startingpoint, std::pair<int, int> endingpoint) {
	
	// Same point
	if (startingpoint.first == endingpoint.first && startingpoint.second == endingpoint.second) {
		return g1[startingpoint.first-1][startingpoint.second-1];
	}

    //Check Distance Exists
	// for (int i=startingpoint.first-1; i<=endingpoint.first-1; i++) {
	// 	for (int j=startingpoint.second-1; j<=endingpoint.second-1; j++) {
	// 		if (g1[i][j] == 1) { continue; }
	// 		else { return 0; }
	// 	}
	// }
	return 1;
}

int main() {
	int m, n, q;
	std::cin >> m >> n;
	takevectorinput(m, n);
	std::cin >> q;
	while (q--) {
		int a, b, c ,d, totalcost;
		std::cin >> a >> b >> c >> d;
	    totalcost = cheapestpath(std::make_pair(a,b), std::make_pair(c,d));
		std::cout << totalcost << "\n";
	}
	return 0;
}
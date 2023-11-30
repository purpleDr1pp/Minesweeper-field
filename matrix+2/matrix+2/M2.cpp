#include <iostream>
#include <vector>
int main() {
	int m, n, k;
	std::cin >> m >> n >> k;
	std::vector<std::vector<int>> field(m + 2, std::vector<int>(n + 2));
	std::vector<std::vector<int>> mines(k, std::vector<int>(2));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2; j++) {
			int mine;
			std::cin >> mine;
			mines[i][j] = mine;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2; j++) {
			field[mines[i][j]][mines[i][j + 1]] = 9;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (field[i][j] != 9) {
				int cnt = 0;
				if (field[i - 1][j - 1] == 9) {
					cnt += 1;
				}
				if (field[i][j - 1] == 9) {
					cnt += 1;
				}
				if (field[i - 1][j] == 9) {
					cnt += 1;
				}
				if (field[i + 1][j] == 9) {
					cnt += 1;
				}
				if (field[i][j + 1] == 9) {
					cnt += 1;
				}
				if (field[i + 1][j + 1] == 9) {
					cnt += 1;
				}
				if (field[i - 1][j + 1] == 9) {
					cnt += 1;
				}
				if (field[i + 1][j - 1] == 9) {
					cnt += 1;
				}
				field[i][j] = cnt;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (field[i][j] == 9) {
				std::cout << '*' << " ";
			}
			else {
				std::cout << field[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}
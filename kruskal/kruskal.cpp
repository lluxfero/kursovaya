//Алгоритм Краскала
#include <iostream>
#include <Windows.h>
#include <clocale>
using namespace std;

int err_n() {
	int m, ival = 1;
	cin >> m;
	while (ival == 1) {
		if (cin.fail() || m < 1) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка! Попробуйте еще раз: ";
			cin >> m;
		}
		else
			ival = 0;
	}
	return m;
}

int err_e() {
	int m, ival = 1;
	cin >> m;
	while (ival == 1) {
		if (cin.fail() || m < 0) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка! Попробуйте еще раз: ";
			cin >> m;
		}
		else
			ival = 0;
	}
	return m;
}

void recolor(int* colors, int c1, int c2, int n) {
	for (int i = 0; i < n; i++) {
		if (colors[i] == c2) {
			colors[i] = c1;
		}
	}
}

void sorting(int** edges, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (edges[j][0] > edges[j + 1][0])
				for (int k = 0; k < 3; k++)
					swap(edges[j][k], edges[j + 1][k]);
}

int kruskal_algorithm(int** edges, int** result, int* colors, int n) {
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (colors[edges[i][1] - 1] != colors[edges[i][2] - 1]) {
			recolor(colors, colors[edges[i][1] - 1], colors[edges[i][2] - 1], n);
			result[x][0] = edges[i][0];
			result[x][1] = edges[i][1];
			result[x][2] = edges[i][2];
			x++;
		}
	}
	return x;
}

void output(int** edges, int** result, int* colors, int n) {
	int x = kruskal_algorithm(edges, result, colors, n);
	cout << "Алгоритм Краскала: " << endl;
	for (int i = 0; i < x; i++) {
		cout << "из " << result[i][1] << " в " << result[i][2] << ", вес: " << result[i][0] << endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите количество ребер в графе: ";
	int n = err_n();

	int** edges = new int* [n];
	for (int i = 0; i < n; i++)
		edges[i] = new int[3];

	cout << "Введите все ребра графа (вес ребра, первая вершина, вторая вершина): " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			edges[i][j] = err_e();

	int* colors = new int[n];
	for (int i = 0; i < n; i++) colors[i] = i;

	sorting(edges, n);

	int** result = new int* [n];
	for (int i = 0; i < n; i++)
		result[i] = new int[3];

	output(edges, result, colors, n);
}

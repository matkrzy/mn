#include <iostream>
#include <iomanip>
#include <fstream>

const int N_MAX = 100;

void funkcja_a(
	int &n,
	double A[N_MAX][N_MAX],
	double B[N_MAX]

) {
	std::ifstream plik;

	std::cout << "Prosze podac rozmiar macierzy: ";
	std::cin >> n;

	//std::cout << "Prosze podac nazwe pliku wejsciowego: ";
	plik.open("dane.txt");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			plik >> A[i][j];
		}
		plik >> B[i];
	}
}

void funkcja_b(
	int n,
	double A[N_MAX][N_MAX],
	double L[N_MAX][N_MAX],
	double U[N_MAX][N_MAX]
) {
	//Zerowanie macierzy i wpisanie 1 na przekatnej macierzy L
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				L[i][i] = 1;
			} else {
				L[i][j] = 0;
			}
			U[i][j] = 0;
		}
	}

	//Wzor 20
	for (int j = 0; j < n; j++) {
		U[0][j] = A[0][j];
		if (j > 0) {
			if (U[0][0] == 0.0) {
				std::cout << "Wystapila proba dzielenia przez 0." << std::endl;
				return;
			}
			L[j][0] = A[j][0] / U[0][0];
		}
	}

	//Wzor 21
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			double suma = 0;
			for (int k = 0; k < i; k++) {
				suma += L[i][k] * U[k][j];
			}
			U[i][j] = A[i][j] - suma;

			if (j > i) {
				if (U[i][i] == 0.0) {
					std::cout << "Wystapila proba dzielenia przez 0." << std::endl;
					return;
				}
				suma = 0;
				for (int k = 0; k < i; k++) {
					suma += L[j][k] * U[k][i];
				}
				L[j][i] = (A[j][i] - suma) / U[i][i];
			}
		}
	}
}

void funkcja_c(
	int n,
	double B[N_MAX],
	double L[N_MAX][N_MAX],
	double U[N_MAX][N_MAX],
	double X[N_MAX],
	double Y[N_MAX]
) {
	//Wzor 16
	Y[0] = B[0];
	for (int i = 1; i < n; i++) {
		double suma = 0;
		for (int k = 0; k < i; k++) {
			suma += L[i][k] * Y[k];
		}
		Y[i] = B[i] - suma;
	}

	//Wzor 17
	X[n - 1] = Y[n - 1] / U[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		double suma = 0;
		for (int k = i + 1; k < n; k++) {
			suma += U[i][k] * X[k];
		}
		X[i] = (Y[i] - suma) / U[i][i];
	}
}

void funkcja_d(
	int n,
	double A[N_MAX][N_MAX],
	double B[N_MAX],
	double L[N_MAX][N_MAX],
	double U[N_MAX][N_MAX],
	double X[N_MAX],
	double Y[N_MAX]
) {
	std::cout << "A" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(13) << A[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "B" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << std::setw(13) << B[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "L" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(13) << L[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "U" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(13) << U[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Y" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << std::setw(13) << Y[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "X" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << std::setw(13) << X[i] << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	int n;

	double L[N_MAX][N_MAX];
	double U[N_MAX][N_MAX];
	double A[N_MAX][N_MAX];
	double B[N_MAX];
	double X[N_MAX];
	double Y[N_MAX];

	std::cout.precision(4);
	std::cout << std::scientific;

	funkcja_a(n, A, B);
	funkcja_b(n, A, L, U);
	funkcja_c(n, B, L, U, X, Y);
	funkcja_d(n, A, B, L, U, X, Y);

	system("PAUSE");
	return 0;
}
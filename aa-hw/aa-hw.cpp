#include <iostream>
using namespace std;

bool kontrol(int sudoku[9][9], int n, int p, int q)
{
	for (int i = 0; i < 9; i++)
	{
		if (sudoku[p][i] == n && q != i) {
			return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (sudoku[i][q] == n && p != i) {
			return false;
		}
	}
	int bx = q / 3;
	int by = p / 3;
	for (int i = by * 3; i < by * 3 + 3; i++)
	{
		for (int j = bx * 3; j < bx * 3 + 3; j++)
		{
			if (sudoku[i][j] == n && i != p && j != q)
			{
				return false;
			}
		}
	}
	return true;
}

int bosKontrol(int sudoku[9][9], int* r, int* c)
{
	for (*r = 0; *r < 9; (*r)++)
	{
		for (*c = 0; *c < 9; (*c)++)
		{
			if (sudoku[*r][*c] == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

void sudokuYazdir(int sudoku[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << "  ";
		}
		cout << endl << endl;
	}
}

bool sudokuCoz(int sudoku[9][9])
{
	int satir = 0, sutun = 0;
	int x = -1, y = -1;

	if (!bosKontrol(sudoku, &satir, &sutun)) {
		return 1;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (kontrol(sudoku, i, satir, sutun))
		{
			sudoku[satir][sutun] = i;
			if (sudokuCoz(sudoku))
			{
				return true;
			}
			sudoku[satir][sutun] = 0;
		}
	}
	return false;
}

int main()
{
	int secim = 0, temp = 0;
	int sudoku[9][9] = {
		{ 8, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 3, 6, 0, 0, 0, 0, 0 },
		{ 0, 7, 0, 0, 9, 0, 2, 0, 0 },
		{ 0, 5, 0, 0, 0, 7, 0, 0, 0 },
		{ 0, 0, 0, 0, 4, 5, 7, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 3, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 6, 8 },
		{ 0, 0, 8, 5, 0, 0, 0, 1, 0 },
		{ 0, 9, 0, 0, 0, 0, 4, 0, 0 } };

	/* Örnek sudoku
	{{ 0, 1, 0, 0, 3, 4, 0, 0, 0 },
	{ 0, 0, 0, 0, 7, 0, 0, 2, 0 },
	{ 3, 4, 2, 0, 0, 0, 0, 0, 0 },
	{ 4, 3, 8, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 5, 6, 0 },
	{ 0, 0, 0, 0, 4, 9, 0, 0, 0 },
	{ 8, 0, 0, 7, 0, 0, 0, 0, 9 },
	{ 0, 0, 0, 9, 0, 5, 1, 0, 7 },
	{ 9, 0, 3, 0, 0, 0, 0, 0, 0 }};
	*/

	int userSudoku[9][9] = { 0 };

	cout << "1.Kendi sudokunu cozdur." << endl;
	cout << "2.Onceden girilmis sudokuyu cozdur." << endl;
	cout << "Seciminizi girin:";
	cin >> secim;

	switch (secim)
	{
	case 1:
		cout << "Sudokunun her elemanini tek tek ve en ust satirdan itibaren soldan saga dogru girin." << endl;
		cout << "(Bos hucreler icin 0(sifir) kullanin.)" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> temp;
				userSudoku[i][j] = temp;
			}
		}
		cout << "Girdiginiz Sudoku;" << endl;
		sudokuYazdir(userSudoku);
		cout << endl << "Cozum:" << endl << endl;
		if (sudokuCoz(userSudoku) == true)
		{
			sudokuYazdir(userSudoku);
		}
		else
			cout << "Cozum Bulunamadi!" << endl;
		break;

		break;
	case 2:
		cout << endl << "Cozum:" << endl << endl;
		if (sudokuCoz(sudoku) == true)
		{
			sudokuYazdir(sudoku);
		}
		else
			cout << "Cozum Bulunamadi!" << endl;
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}

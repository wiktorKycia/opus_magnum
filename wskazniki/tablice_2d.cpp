#include<iostream>
#include<cstdlib>

int** create_table_2D(int _size_x, int _size_y, int _range)
{
	// tablica 2D jako jednowymiarowa tablica jednowymiarowych tablic
	int** tab = new int*[_size_y];//alokacja adresów dla wierszy

	//alokacja pamięci na int w kolejnych wierszach
	for (int i = 0; i < _size_y; i++)
		tab[i] = new int[_size_x];

	//wypełnienie tablicy
	for (int i = 0; i < _size_y; i++)
		for (int j = 0; j < _size_x; j++)
			tab[i][j] = rand() % _range;

	return  tab;
}


int main()
{

	int size_x = 10;
	int size_y = 10;
	int range = 100;

	int** tab2D;

	tab2D = create_table_2D(size_x, size_y, range);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << tab2D[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 1;

}
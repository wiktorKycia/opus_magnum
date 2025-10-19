class A
{
	// domyślny poziom prywatny

	int skladowa_1{100}; // deklaracja składowej prywatnej (wstępnie ustawionej)
	double skladowa_2; // deklaracja składowej prywatnej
	int skladowa_9; // deklaracja składowej prywatnej
	double skladowa_10; // deklaracja składowej prywatnej

	int f(int x);//deklaracja funkcji  prywatnej
	int j(int x);//deklaracja funkcji  prywatnej


 public: // zmiana poziomuy na publiczny

	int skladowa_3{200}; // deklaracja składowej publicznej (wartość początkowa to 200)
	double skladowa_4; // deklaracja składowej publicznej
	int skladowa_7; // deklaracja składowej publicznej
	double skladowa_8; // deklaracja składowej publicznej

	int g(int x){
        return 0; //! ta metoda staje się automatycznie inline, bo jest zaimplementowana wewnątrz klasy
    };//deklaracja funkcji  publicznej
	int i(int x);//deklaracja funkcji  publicznej

 protected: // zmiana poziomuy na chroniony

	int skladowa_5; // deklaracja składowej chronionej
	double skladowa_6; // deklaracja składowej chronionej

	int h(int x);//deklaracja funkcji  chronionej
};

int A::h(int x) // implementacje można dawać też w pliku .h
{
    return 0;
}

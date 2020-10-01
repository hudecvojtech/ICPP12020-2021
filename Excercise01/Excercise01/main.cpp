#include <iostream>

struct Trojuhelnik {
	int a;
	int b;
	int c;
};

bool lzeSestrojit(Trojuhelnik t) {
	return t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a;
}

int main(int argc, char** argv) {
	std::cout << "Kolik trojuhelniku se bude nacitat?" << std::endl;
	int pocet = 0;
	std::cin >> pocet;
	Trojuhelnik* trojuhelniky = new Trojuhelnik[pocet];

	for (int i = 0; i < pocet; i++) {
		std::cout << "Zadejte stranu a trojuhelniku " << i + 1 << ": ";
		std::cin >> trojuhelniky[i].a;
		std::cout << "Zadejte stranu b trojuhelniku " << i + 1 << ": ";
		std::cin >> trojuhelniky[i].b;
		std::cout << "Zadejte stranu c trojuhelniku " << i + 1 << ": ";
		std::cin >> trojuhelniky[i].c;

		if (lzeSestrojit(trojuhelniky[i])) {
			int obvod = trojuhelniky[i].a + trojuhelniky[i].b + trojuhelniky[i].c;
			std::cout << "Obvod: " << obvod << std::endl;
		}
		else {
			std::cout << "Nelze sestrojit" << std::endl;
		}
	}

	delete[] trojuhelniky;
	return 0;
}
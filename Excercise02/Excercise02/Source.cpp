#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Receipt.h"
#include "CashRegister.h"

int main(int argc, char** argv) {
	srand(time(NULL));
	CashRegister* cashRegister = new CashRegister();
	Receipt r;
	for (int i = 0; i < 15; i++) {
		double sum = rand() % 900 + 100;
		double vat = (rand() % 20 + 1) / 100.0;
		try {
			r = cashRegister->CreateReceipt(sum, vat);
			std::cout << "Receipt with id " << r.GetId() << " was created. Sum: " << r.GetSum() << " vat: " << r.GetVat() << std::endl;
		}
		catch (const char* msg) {
			std::cout << msg << std::endl;
		}
	}

	std::cout << "Sum of all receipts: " << cashRegister->getSum() << std::endl;
	std::cout << "Sum of all receipts including vat: " << cashRegister->getSumIncludeVat() << std::endl;
}

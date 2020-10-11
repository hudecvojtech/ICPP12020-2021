#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister {
	static int idCounter;
	int numberOfReceipts;
	Receipt* receipts;
public:
	CashRegister();
	~CashRegister();
	Receipt& CreateReceipt(double sum, double vat);
	Receipt& getReceipt(int id);
	double getSum() const;
	double getSumIncludeVat() const;
};

#endif // !CASH_REGISTER_H


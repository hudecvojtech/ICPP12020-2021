#include "CashRegister.h"
#include <exception>

int CashRegister::idCounter = 1000;

CashRegister::CashRegister() {
	receipts = new Receipt[10];
	numberOfReceipts = 0;
}

CashRegister::~CashRegister() {
	delete[] receipts;
}

Receipt& CashRegister::CreateReceipt(double sum, double vat) {
	if (numberOfReceipts == 10)
		throw "CashRegister is full";

	receipts[numberOfReceipts].SetId(idCounter++);
	receipts[numberOfReceipts].SetSum(sum);
	receipts[numberOfReceipts].SetVat(vat);

	return receipts[numberOfReceipts++];
}

Receipt& CashRegister::getReceipt(int id)
{
	for (int i = 0; i < numberOfReceipts; i++) {
		if (receipts[i].GetId() == id) {
			return receipts[i];
		}
	}

	return receipts[0];
}

double CashRegister::getSum() const
{
	double sum = 0;
	for (int i = 0; i < numberOfReceipts; i++) {
		sum += receipts[i].GetSum();
	}

	return sum;
}

double CashRegister::getSumIncludeVat() const
{
	double sumIncludeVat = 0;
	for (int i = 0; i < numberOfReceipts; i++) {
		sumIncludeVat += receipts[i].GetSum() * (1 + receipts[i].GetVat());
	}

	return sumIncludeVat;
}

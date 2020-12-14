#ifndef CONDUIT_H
#define CONDUIT_H
#include "IConduit.h"
#include <fstream>

struct PipeElement;


struct Conduit : public IConduit {
private:
	int _size;
	PipeElement*** matrix;
public:
	Conduit(int size);
	~Conduit();
	void AddElement(int x, int y, PipeElement* element);
	PipeElement* GetElement(int x, int y) const;
	bool IsValid() const;
	int GetSize() const;
};

#endif // !CONDUIT_H
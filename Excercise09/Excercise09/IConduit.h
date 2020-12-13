#ifndef ICONDUIT_H
#define ICONDUIT_H

struct PipeElement;

struct IConduit {
	virtual ~IConduit() { }
	virtual const PipeElement* GetElement(int x, int y) const = 0;
	virtual bool IsValid() const = 0;
};

#endif // !ICONDUIT_H
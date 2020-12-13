#include "PipeElement.h"
#include "PipeEmpty.h"

PipeElement::PipeElement(int x, int y)
{
    _x = x;
    _y = y;
}

bool PipeElement::IsConnectionValid(const Conduit* conduit) const
{
    return false;
}

bool PipeElement::isNorthConnectionValid(const Conduit* conduit) const
{
    if (dynamic_cast<const PipeEmpty*>(conduit->GetElement(_x, _y - 1)) != nullptr) return false;
    return true;
}

bool PipeElement::isSouthConnectionValid(const Conduit* conduit) const
{
    if (dynamic_cast<const PipeEmpty*>(conduit->GetElement(_x, _y + 1)) != nullptr) return false;
    return true;
}

bool PipeElement::isEastConnectionValid(const Conduit* conduit) const
{
    if (dynamic_cast<const PipeEmpty*>(conduit->GetElement(_x + 1, _y)) != nullptr) return false;
    return true;
}

bool PipeElement::isWestConnectionValid(const Conduit* conduit) const
{
    if (dynamic_cast<const PipeEmpty*>(conduit->GetElement(_x - 1, _y)) != nullptr) return false;
    return true;
}

bool PipeElement::isNorthBorderValid(const Conduit* conduit) const
{
    if (_y < 0) return false;
    return true;
}

bool PipeElement::isSouthBorderValid(const Conduit* conduit) const
{
    if (_y > conduit->GetSize()) return false;
    return true;
}

bool PipeElement::isEastBorderValid(const Conduit* conduit) const
{
    if (_x < 0) return false;
    return true;
}

bool PipeElement::isWestBorderValid(const Conduit* conduit) const
{
    if (_x > conduit->GetSize()) return false;
    return true;
}



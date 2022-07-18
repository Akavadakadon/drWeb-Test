#pragma once
#include "dictionary.h"

template<class Key>
class NotFoundException :
    public not_found_exception < Key>
{
private:
    Key key;
public:
    NotFoundException(Key key) :key(key)
    {}
    virtual const Key& get_key() const noexcept
    {
        return key;
    }
};


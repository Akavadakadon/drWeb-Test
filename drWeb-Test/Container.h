#pragma once
#include "dictionary.h"
#include "NotFoundException.h"
#include <map>

template<class Key, class Value>
class Container :
    public dictionary<Key, Value>
{
private:
    std::map<Key, Value> dict;
public:
    virtual const Value& get(const Key& key) const
    {
        if (!is_set(key))
            throw NotFoundException < Key>(key);
        return dict.at(key);
    }
    virtual void set(const Key& key, const Value& value)
    {
        if (!is_set(key))
            throw NotFoundException < Key>(key);
        dict[key] = value;
    }
    virtual bool is_set(const Key& key) const
    {
        if (dict.find(key) == dict.end())
            return false;
    }
};


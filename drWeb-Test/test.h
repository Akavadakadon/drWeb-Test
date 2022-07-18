#pragma once
#include "Container.h"
#include "NotFoundException.h"
#include <string>
#include <cassert>

void Test()
{
    Container<std::string, std::string> testDict;
    std::string key;
    try {
        key = "key1";
        testDict.get(key);
    }
    catch (NotFoundException<std::string> e)
    {
        assert(e.get_key() == key);
        std::cout << "get() tested " << e.get_key() << std::endl;
    }

    try {
        key = "key2";
        std::string val = "val";
        testDict.set(key, val);
    }
    catch (NotFoundException<std::string> e)
    {
        assert(e.get_key() == key);
        std::cout << "set() tested " << e.get_key() << std::endl;
    }

    key = "key3";
    assert(testDict.is_set(key) == false);
    std::cout << "is_set() tested " << key << std::endl;
}




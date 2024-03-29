﻿#pragma once

namespace Utility
{
    struct ShortVec2
    {
        ShortVec2() = default;
        ShortVec2(short _x, short _y) : x(_x), y(_y) {}
        ShortVec2(const ShortVec2& _sv) = default;
        operator Vec2() const {return Vec2(x, y);}
        short x, y;
    };
    
    void SplitString(std::vector<std::string>* _result, std::string* _string, char _separator);
    int FindIndexInString(std::string* _string, char _find, int _startIndex = 0, int _searchDir = 1);

    std::string WToA(const std::wstring& _w);
    std::wstring AToW(const std::string& _a);

    int HexToInt(const std::string& _hex);
    std::string IntToHex(int _int);

    template <typename T>
    bool Contains(const std::vector<T>& _vec, T _find)
    {
        for (auto& iter : _vec)
        {
            if (iter == _find)
                return true;
        }
        return false;
    }

    template <typename T>
    int IndexOf(const std::vector<T>& _vec, T _find)
    {
        for (int i = 0; i < _vec.size(); i++)
        {
            if (_vec[i] == _find)
                return i;
        }
        return -1;
    }

    template <typename T>
    int IndexOf(const T*& _vec, int _arraySize, T _find)
    {
        for (int i = 0; i < _arraySize; i++)
        {
            if (_vec[i] == _find)
                return i;
        }
        return -1;
    }
};

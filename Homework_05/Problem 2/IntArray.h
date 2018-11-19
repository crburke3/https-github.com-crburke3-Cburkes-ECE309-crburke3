//
//  IntArray.h
//  ECE309Tester
//
//  Created by Christian Burke on 10/11/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

//#ifndef Prob__2_hpp
//#define Prob__2_hpp

#include <string.h>
#include <stdio.h>
#include <string>


class IntArray{
public:
    int* array;
    int len = 0;
    
    IntArray(const char* str);
    IntArray(int size = 0, int val = 0);
    int& operator[](int index);
    void printAll();
    IntArray& operator+=(const IntArray &rhs);
    IntArray operator+(const IntArray &rhs) const;
    IntArray operator-(const IntArray &rhs) const;
    IntArray operator*(int x) const;
    IntArray operator/(int x) const;
    IntArray operator<<(int count) const;
    operator int() const;
    operator char*() const;

    
    int get(int index);
    int getLength();
    void set(int index, int val);
};

IntArray::IntArray(int size, int val)
{
    len = size;
    array = new int[size];
    for(int i = 0; i<size; i++)
    {
        array[i] = val;
    }
}

IntArray::IntArray(const char* strang)
{
    len = strlen(strang);
    int* arr = new int[len];
    for(int i=0; i<len; i++)
    {
        int val =int(strang[i]);
        arr[i] = val;
    }
    array = arr;
}


int& IntArray::operator[](int index)
{
    return array[index];
}

void IntArray::printAll()
{
    for(int i = 0; i<len; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\n");
}

IntArray& IntArray::operator+=(const IntArray &rhs)
{
    for(int i = 0; i<len; i++)
    {
        int rhsVal = rhs.array[i];
        array[i] = array[i] + rhsVal;
    }
    return *this;
}

IntArray IntArray::operator+(const IntArray &rhs) const
{
    IntArray newInArr = IntArray(len);
    
    for(int i = 0; i<len; i++)
    {
        int rhsVal = rhs.array[i];
        int lhsVal = array[i];
        if (!(i > rhs.len-1))
        {
            newInArr.array[i] = lhsVal + rhsVal;
        }
        else
        {
            newInArr.array[i] = lhsVal;
        }
    }
    return newInArr;
}

IntArray IntArray::operator-(const IntArray &rhs) const
{
    IntArray newInArr = IntArray(len);
    
    for(int i = 0; i<len; i++)
    {
        int rhsVal = rhs.array[i];
        int lhsVal = array[i];
        if (!(i > rhs.len-1))
        {
            newInArr.array[i] = lhsVal - rhsVal;
        }
        else
        {
            newInArr.array[i] = lhsVal;
        }
    }
    return newInArr;
}

IntArray IntArray::operator*(int x) const
{
    for(int i=0; i<len; i++)
    {
        array[i] = array[i] * x;
    }
    return *this;
}

IntArray IntArray::operator/(int x) const
{
    for(int i=0; i<len; i++)
    {
        int divVal =array[i] / x;
        array[i] = divVal;
    }
    return *this;
}

IntArray IntArray::operator<<(int x) const
{
    
    IntArray result(len);
    int i =0;
    int index = x;
    if (index >= len) index = index%len;
    while (i<len) {
        result.array[index] = array[i];
        i++;
        index++;
        if (index>=len)index-=len;
        
    }
    return result;
}



IntArray::operator int() const
{
    int sum = 0;
    for(int i = 0; i<len; i++)
    {
        sum = sum + array[i];
    }
    return sum/len;
}


IntArray::operator char*() const

{
    int zeroCheck = 0;
    for(int i =0; i<len;i++)
    {
        if((array[i]<0) || (array[i]>= 255))
        {
            array[i] = 32;
        }
        if(array[i] ==0)
        {
            zeroCheck++;
        }
    }
    
    char str[2];
    str[0] = ' ';
    for(int j = 0; j<len; j++)
    {
        char newStr[2];
        char val = char(array[j]);
        newStr[0] = val;
        strcat(str, newStr);
        
    }
    
    int strLen = strlen(str);
    char* finalStr = new char[strLen];
    for(int i=0; i<strLen;i++)
    {
        finalStr[i-1] = str[i];
    }
    
    return finalStr;
}




//TUCK

int IntArray::get(int index) {
    return array[index];
}

int IntArray::getLength()
{
    return len;
}

void IntArray::set(int index, int val) {
    array[index] = val;
}




//#endif /* Prob__2_hpp */

//
//  Homework_10_tester.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 11/19/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include <stdio.h>
#include "IntInf.hpp"

int main()
{
    // I tested the following lines of code by using the debugger to analyze each value, rather than printing.
    
    
    
    IntInf num = IntInf(10);
    IntInf num2 = IntInf(5);
    IntInf negInf = IntInf(false);
    IntInf posInf = IntInf(true);
    
    IntInf test = IntInf();
    bool var = true;
    
    // ------------ = testers -------------
    test = 5;
    test = negInf;
    test = posInf;
    
    // ------------ + testers -------------
    test = (num + num2);
    test = (num + posInf);
    test = (num + negInf);
    
    test = (posInf + num);
    test = (posInf + posInf);
    test = (posInf + negInf);
    
    test = (negInf + num);
    test = (negInf + posInf);
    test = (negInf + negInf);
    
    // ------------ - testers -------------
    test = (num - num2);
    test = (num - posInf);
    test = (num - negInf);
    
    test = (posInf - num);
    test = (posInf - posInf);
    test = (posInf - negInf);
    
    test = (negInf - num);
    test = (negInf - posInf);
    test = (negInf - negInf);
    
    // ------------ * testers -------------
    test = (num * num2);
    test = (num * posInf);
    test = (num * negInf);
    
    test = (posInf * num);
    test = (posInf * posInf);
    test = (posInf * negInf);
    
    test = (negInf * num);
    test = (negInf * posInf);
    test = (negInf * negInf);
    
    // ------------ / testers -------------
    test = (num / num2);
    test = (num / posInf);
    test = (num / negInf);
    
    test = (posInf / num);
    test = (posInf / posInf);
    test = (posInf / negInf);
    
    test = (negInf / num);
    test = (negInf / posInf);
    test = (negInf / negInf);
    
    // ------------ == testers -------------
    var = (num == num);
    var = (num == num2);
    var = (num == negInf);
    var = (num == negInf);
    
    var = (posInf == num);
    var = (posInf == posInf);
    var = (posInf == negInf);
    
    var = (negInf == num);
    var = (negInf == posInf);
    var = (negInf == negInf);
    
    // ------------ > testers -------------
    var = (num > num2);
    var = (num > posInf);
    var = (num > negInf);
    
    var = (posInf > num);
    var = (posInf > posInf);
    var = (posInf > negInf);
    
    var = (negInf > num);
    var = (negInf > posInf);
    var = (negInf > negInf);
    
    // ------------ < testers -------------
    var = (num < num2);
    var = (num < posInf);
    var = (num < negInf);
    
    var = (posInf < num);
    var = (posInf < posInf);
    var = (posInf < negInf);
    
    var = (negInf < num);
    var = (negInf < posInf);
    var = (negInf < negInf);
    
    return 0;
}

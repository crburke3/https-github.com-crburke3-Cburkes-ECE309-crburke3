//
//  IntInf.cpp
//  ECE309Tester
//
//  Created by Christian Burke on 11/19/18.
//  Copyright © 2018 Christian Burke. All rights reserved.
//

#include "IntInf.hpp"

void IntInf::operator= (const int &num)
{
    is_int = true;
    neg_inf = false;
    pos_inf = false;
    
    val = num;
}

IntInf IntInf::operator+ (const IntInf &ref)   //Adding
{
    IntInf ret = IntInf();
    
    if(is_int)      //if this is an int
    {
        if (ref.is_int) //if both are integers
        {
            ret.val = val + ref.val;
            ret.pos_inf = false;
            ret.neg_inf = false;
            ret.is_int = true;
        }
        if(!ref.is_int)     //if we are adding or subtracting infinity from an integer
        {
            ret.is_int = false;
            ret.val = NULL;
            if(ref.pos_inf == true) //if ref is +inf
            {
                ret.pos_inf = true;
                ret.neg_inf = false;
            }
            if(ref.neg_inf == true)
            {
                ret.pos_inf = false;
                ret.neg_inf = true;
            }
        }
    }
    if(!is_int) //if our current inf is infinite
    {
        ret.is_int = false;
        ret.pos_inf = pos_inf;
        ret.neg_inf = neg_inf;
        ret.val = NULL;
    }

    //I have learned that adding -inf to +inf will not do anything. So we only care if we are adding an int to an int or inf to int
    return ret;
}

IntInf IntInf::operator- (const IntInf &ref)   //subtracting
{
    IntInf ret = IntInf();
    
    if(is_int)
    {
        if (ref.is_int) //if both are integers
        {
            ret.val = val - ref.val;
            ret.pos_inf = false;
            ret.neg_inf = false;
            ret.is_int = true;
        }
        if(!ref.is_int)
        {
            ret.is_int = false;
            ret.val = NULL;
            if(ref.pos_inf == true) //if num - (+inf)
            {
                ret.pos_inf = false;
                ret.neg_inf = true;
            }
            if(ref.neg_inf == true) //if num - (-inf)
            {
                ret.pos_inf = true;
                ret.neg_inf = false;
            }
        }
    }
    if(!is_int) //if our current inf is infinite
    {
        ret.is_int = false;
        ret.pos_inf = pos_inf;
        ret.neg_inf = neg_inf;
        ret.val = NULL;
    }
    
    //I have learned that adding -inf to +inf will not do anything. So we only care if we are adding an int to an int or inf to int
    return ret;
}

IntInf IntInf::operator* (const IntInf &ref)   //Multiplying
{
    IntInf ret = IntInf();
    
    if(is_int)//If this is an int
    {
        if(ref.is_int)  //if multiplier is an int : 5 * 5
        {
            ret.is_int = true;
            ret.val = val * ref.val;//set new value
            ret.neg_inf = false;    //fail safes
            ret.pos_inf = false;    //fail safes
            return ret;
        }
        
        if(!ref.is_int) //if multiplier is infinite : 5 * +inf
        {
            ret.is_int = false;
            ret.neg_inf = ref.neg_inf;  //make the return inf = ref inf
            ret.pos_inf = ref.pos_inf;  //make the return inf = ref inf
            ret.val = NULL;
            return ret;
        }
    }
    
    if(!is_int) // if this is infinite
    {
        if(ref.is_int)  //if multiplier is an int : +inf * 5
        {
            ret.is_int = false;
            ret.pos_inf = pos_inf;
            ret.neg_inf = neg_inf;
            ret.val = NULL;
            return ret;
        }
        
        if(!ref.is_int) //if multiplier is infinite : +inf * +inf
        {
            ret.is_int = false;
            ret.val = NULL;
            if(pos_inf) // this is a +inf
            {
                if(ref.neg_inf)//ref is -inf
                {
                    ret.pos_inf = false;
                    ret.neg_inf = true;
                }
                if(ref.pos_inf)
                {
                    ret.pos_inf = true;
                    ret.neg_inf = false;
                }
                return ret;
            }
            if(!pos_inf)    //this is -inf
            {
                if(ref.neg_inf) //ref is -inf
                {
                    ret.pos_inf = true;
                    ret.neg_inf = false;        //return a +inf
                }
                if(ref.pos_inf)//if is +inf
                {
                    ret.pos_inf = false;
                    ret.neg_inf = true;     // return -inf
                }
            }
            return ret;
        }
    }
    return ret;
}

IntInf IntInf::operator/ (const IntInf &ref)   //dividing
{
    IntInf fin = IntInf();
    
    if(is_int)  //if this is an int
    {
        if(ref.is_int)  // 5/5
        {
            if(ref.val == 0)
            {
                fin.is_int = false;
                fin.val = NULL;
                fin.neg_inf = false;
                fin.pos_inf = false;
                printf("UNDEFINED");
                return fin;
            }
            fin.is_int = true;
            fin.val = val/ref.val;
            fin.pos_inf = false;
            fin.neg_inf = false;
            return fin;
            
        }
        
        if(!ref.is_int) // 5/infinite = 0
        {
            fin.is_int = true;
            fin.val = 0;
            fin.pos_inf = false;
            fin.neg_inf = false;
            return fin;
        }
    }
    
    if(!is_int) //if this is infinite
    {
        fin.is_int = false;
        fin.val = NULL;
        
        if(ref.is_int)  //  inf/5
        {
            fin.pos_inf = pos_inf;
            fin.neg_inf = neg_inf;
            return fin;
        }
        
        if(!ref.is_int) // inf/inf
        {
            if(pos_inf && ref.neg_inf) // +inf/ -inf = -inf
            {
                fin.pos_inf = false;
                fin.neg_inf = true;
                return fin;
            }
            if(pos_inf && ref.pos_inf) // +inf/ +inf = +inf
            {
                fin.pos_inf = true;
                fin.neg_inf = false;
                return fin;
            }
            if(neg_inf && ref.neg_inf)  // -inf/-inf = +inf
            {
                fin.pos_inf = true;
                fin.neg_inf = false;
                return fin;
            }
            if(neg_inf && ref.pos_inf)  // -inf/+inf = -inf
            {
                fin.pos_inf = false;
                fin.neg_inf = true;
                return fin;
            }
        }
    }
    return fin;
}

bool IntInf::operator== (const IntInf &ref)   //==
{
    if(is_int && ref.is_int)    //  int == int
    {
        if(val == ref.val)  // 5 == 5
        {
            return true;
        }
    }
    return false;
}

bool IntInf::operator> (const IntInf &ref)   //>
{
    if(is_int)  //if this is an int
    {
        if(ref.is_int)  // ref is an int
        {
            return val > ref.val;   //int>int
        }
        
        if(!ref.is_int) // int > infinite
        {
            if(ref.pos_inf) // 5 > +infinite
            {
                return false;
            }
            if(ref.neg_inf) // 5 > -infinite
            {
                return true;
            }
        }
    }
    
    if(!is_int) //if this is Infinite
    {
        if(ref.is_int)
        {
            if(pos_inf) // +infinity is always greater a number
            {
                return true;
            }
        }
        if(!ref.is_int) // Infinite>infinte
        {
            if(pos_inf && ref.neg_inf)  //+infinite > -infinte == true
            {
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

bool IntInf::operator< (const IntInf &ref)   //>
{
    if(is_int)  //if this is an int
    {
        if(ref.is_int)  // ref is an int
        {
            return val < ref.val;   //int>int
        }
        
        if(!ref.is_int) // int < infinite
        {
            if(ref.pos_inf) // 5 < +infinite = true
            {
                return true;
            }
            if(ref.neg_inf) // 5 < -infinite = false
            {
                return false;
            }
        }
    }
    
    if(!is_int) //if this is Infinite
    {
        if(ref.is_int) // if ref is an int
        {
            if(neg_inf) // if this is negative,
            {
                return true;
            }
        }
        
        if(!ref.is_int) // Infinite<infinte
        {
            if(neg_inf && ref.pos_inf)  // -infinite < +infinte == true
            {
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}

/*****
 * GP_MAX5841.h
 *
 * Created on: 11-16-2016
 *     Author: Robert F. Chapman
 * 
 */

#ifndef MAX5841_H_
#define MAX5841_H_

#ifdef __cplusplus

// External Libraries
#include <Arduino.h>

/* Code Goes Here */

class GP_MAX5841
{
    public:
        GP_MAX5841(uint8_t ss);
    
        void setWiper(unsigned int value);
        void readWiper();
        void writeWiper();
private:
        unsigned int _SS;

};


#endif
#endif


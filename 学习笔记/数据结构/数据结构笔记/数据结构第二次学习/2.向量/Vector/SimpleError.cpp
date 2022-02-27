//
// Created by 华邵钶 on 2022/2/27.
//

#include "SimpleError.h"
#include <iostream>
void error_message(const char * message) {
    std::cout << std::endl << message;
    exit(1);
}
#pragma once
#include <sstream>

#define THROW(__msg__)                              \
{                                                   \
    std::ostringstream os;                          \
    os << __FUNCTION__ << ": " << __msg__;          \
    throw std::runtime_error(os.str());             \
}

#define THROW_IF(__cond__, __msg__) if (__cond__)   \
{                                                   \
    std::ostringstream os;                          \
    os << __FUNCTION__ << ": " << __msg__;          \
    throw std::runtime_error(os.str());             \
}
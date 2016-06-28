#ifndef INCL_DCM_BASE_FIX_SIZE_ARRAY_H
#define INCL_DCM_BASE_FIX_SIZE_ARRAY_H

#include <cub/cub.h>
#include <stddef.h>
#include <string.h>

CUB_NS_BEGIN

template <typename T, size_t MAXSIZE>
struct FixSizeArray
{
    FixSizeArray(size_t size = MAXSIZE)
        : actualSize(size < MAXSIZE? size : MAXSIZE)
    {
    }

    void reset()
    {
         memset(object, 0, sizeof(object));
    }

    const size_t capacity() const
    {
        return actualSize;
    }

    const T& operator[](size_t index) const
    {
        return object[index];
    }

    T& operator[](size_t index)
    {
        return object[index];
    }

private:
    size_t actualSize;
    T object[MAXSIZE];
};

CUB_NS_END

#endif


#ifndef H5712E60C_DEF5_4A3B_93C0_C074CD80C63B
#define H5712E60C_DEF5_4A3B_93C0_C074CD80C63B

#include <cub/cub.h>
#include <cub/base/BaseTypes.h>

CUB_NS_BEGIN

typedef U32 Status;

enum : Status
{
    CUB_RESERVED_FAILURE = 0x80000000
};

inline bool isSuccessStatus(Status status)
{
    return (status & CUB_RESERVED_FAILURE) == 0;
}

inline bool isFailedStatus(Status status)
{
    return !isSuccessStatus(status);
}

inline constexpr Status successStatus(const U32 status)
{
    return status;
}

inline constexpr Status failedStatus(const U32 status)
{
    return status | CUB_RESERVED_FAILURE;
}

CUB_NS_END

const CUB_NS::U16 CUB_INVALID_U16 = 0xFFFF;
const CUB_NS::U32 CUB_INVALID_U32 = 0xFFFFFFFF;

/////////////////////////////////////////////////////////////////

enum : cub::Status
{
    CUB_SUCCESS = cub::successStatus(0),

    CUB_FATAL_BUG = cub::failedStatus(0x7FFFFFFE),
    CUB_FAILURE   = cub::failedStatus(0x7FFFFFFF)
};

#define __CUB_FAILED(result)   isFailedStatus(result)
#define __CUB_SUCCESS(result)  (result == CUB_SUCCESS)

#define CUB_IS_SUCC_STATUS(status) isSuccessStatus(status)


#endif

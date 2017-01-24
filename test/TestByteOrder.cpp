#include <cut/cut.hpp>
#include <cub/network/ByteOrder.h>

USING_CUM_NS
USING_CUB_NS

FIXTURE(ByteOrder)
{
   TEST("network order of S8 should be equal to the original one")
   {
      S8 v = -2;

      ASSERT_THAT(hton(v), eq(v));
   }

   TEST("network order of U8 should be equal to the original one")
   {
      U8 v = 2;

      ASSERT_THAT(hton(v), eq(v));
   }

   TEST("network order of S16 should be equal to network order")
   {
      S16 v = -274;

      ASSERT_THAT(ntohs(hton(v)), eq(v));
   }

   TEST("network order of U16 should be equal to network order")
   {
      U16 v = 274;

      ASSERT_THAT(ntohs(hton(v)), eq(v));
   }

   TEST("network order of S32 should be equal to network order")
   {
      S32 v = -274932234;

      ASSERT_THAT(ntohl(hton(v)), eq(v));
   }

   TEST("network order of U32 should be equal to network order")
   {
      U32 v = 274343432;

      ASSERT_THAT(ntohl(hton(v)), eq(v));
   }

   TEST("network order of S64 should be equal to network order")
   {
      S64 v = -2749343342232234;

      ASSERT_THAT(ntohll(hton(v)), eq(v));
   }

   TEST("network order of U64 should be equal to network order")
   {
      U64 v = 2743434434323432;

      ASSERT_THAT(ntohll(hton(v)), eq(v));
   }

};

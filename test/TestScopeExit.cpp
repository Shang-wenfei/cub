#include <cut/cut.hpp>
#include <cub/mem/ScopeExit.h>

USING_CUM_NS

FIXTURE(ScopeExitTest)
{
    TEST("should_execute_the_code_when_exit_scope")
    {
        bool scopeExited = false;

        {
            SCOPE_EXIT([&scopeExited](){ scopeExited = true; });
        }

        ASSERT_THAT(scopeExited, be_true());
    }
};

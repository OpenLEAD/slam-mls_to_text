#include <boost/test/unit_test.hpp>
#include <mls_to_text/Dummy.hpp>

using namespace mls_to_text;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    mls_to_text::DummyClass dummy;
    dummy.welcome();
}

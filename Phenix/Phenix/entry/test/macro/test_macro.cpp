#include "PrecompiledHeader.hpp"
#include "kv/entry/IncludeAll.hpp"
#include "kv/predef/IncludeAll.hpp"

#include "fmt/format.h"

#define TestVersionDecMacro(macro, input, expected) cout << ((macro((input)) == (expected)) ? termcolor::green : termcolor::red); \
    cout << fmt::format("{0:<46}: expected = {1:>10}, actual = {2:>10}\n", fmt::format("{0}({1})", #macro, (input)), (expected), macro((input))) << termcolor::reset;
#define TestVersionHexMacro(macro, input, expected) cout << ((macro((input)) == (expected)) ? termcolor::green : termcolor::red); \
    cout << fmt::format("{0:<46}: expected = {1:>10}, actual = {2:>10}\n", fmt::format("{0}(0x{1:x})", #macro, (input)), (expected), macro((input))) << termcolor::reset;

#define __ModuleMacro(module, member) KV_ ## module ## _ ## member
#define PrintModuleInfo(module, member) \
    cout << termcolor::cyan << fmt::format("{0:<24}: {1}\n", fmt::format("{0} {1}", #module, #member), __ModuleMacro(module, member)) << termcolor::reset;

KV_QuickAddEntry
{
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VPPP      , 12345678  , 50000678 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VPPP      , 1234      , 10000234 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VRP       , 123       , 10200003 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VRP000    , 123456    , 10200003 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VRPP      , 1234      , 10200034 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VRR       , 123       , 12300000 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VRR000    , 123400    , 12300000 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VRRPP     , 12340     , 12300040 );
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VV00      , 1234      , 120000000);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VVRR      , 1234      , 123400000);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VVRR00PP00, 1234567890, 123400078);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VVRR0PP00 , 123456789 , 123400067);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VVRR0PPPP , 123456789 , 123406789);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_VVRRPP    , 123456    , 123400056);

    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVRP     , 0x123     , 10200003 );
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVRPP    , 0x1234    , 10200052 );
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVRRPP000, 0x12345678, 13500069 );
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVVRP    , 0x1234    , 180300004);
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVVRR    , 0x1234    , 185200000);
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVVRRP   , 0x12345   , 185200005);
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVVRRPP  , 0x123456  , 185200086);
    TestVersionHexMacro(KV_MAKE_VERSION_FROM_0xVVRRPPPP, 0x12345678, 185222136);

    TestVersionDecMacro(KV_MAKE_VERSION_FROM_YYYY    , 2017    , 470000000);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_YYYYMM  , 201701  , 470100000);
    TestVersionDecMacro(KV_MAKE_VERSION_FROM_YYYYMMDD, 20170108, 470100008);

    cout << endl;
    PrintModuleInfo(ARCH, NAME);
    PrintModuleInfo(ARCH, VERSION);

    cout << endl;
    PrintModuleInfo(COMPILER, NAME);
    PrintModuleInfo(COMPILER, VERSION);
#ifdef KV_COMPILER_NAME_BACK
    PrintModuleInfo(COMPILER, NAME_BACK);
    PrintModuleInfo(COMPILER, VERSION_BACK);
#endif

    cout << endl;
    PrintModuleInfo(OS, NAME);
    PrintModuleInfo(OS, VERSION);

    cout << endl;
    PrintModuleInfo(SIMD, NAME);
    PrintModuleInfo(SIMD, VERSION);

    return 0;
};

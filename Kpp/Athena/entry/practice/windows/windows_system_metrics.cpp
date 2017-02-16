#include "PrecompiledHeader.hpp"

#include "begin"

#define NUMLINES ((int) (sizeof sysmetrics / sizeof sysmetrics [0]))

static struct SysMetData
{
    int     iIndex;
    TCHAR * szLabel;
    TCHAR * szDesc;
} sysmetrics[] =
{
    SM_CXSCREEN         , TEXT("SM_CXSCREEN"         ), TEXT("Screen width in pixels"         ),
    SM_CYSCREEN         , TEXT("SM_CYSCREEN"         ), TEXT("Screen height in pixels"        ),
    SM_CXVSCROLL        , TEXT("SM_CXVSCROLL"        ), TEXT("Vertical scroll width"          ),
    SM_CYHSCROLL        , TEXT("SM_CYHSCROLL"        ), TEXT("Horizontal scroll height"       ),
    SM_CYCAPTION        , TEXT("SM_CYCAPTION"        ), TEXT("Caption bar height"             ),
    SM_CXBORDER         , TEXT("SM_CXBORDER"         ), TEXT("Window border width"            ),
    SM_CYBORDER         , TEXT("SM_CYBORDER"         ), TEXT("Window border height"           ),
    SM_CXFIXEDFRAME     , TEXT("SM_CXFIXEDFRAME"     ), TEXT("Dialog window frame width"      ),
    SM_CYFIXEDFRAME     , TEXT("SM_CYFIXEDFRAME"     ), TEXT("Dialog window frame height"     ),
    SM_CYVTHUMB         , TEXT("SM_CYVTHUMB"         ), TEXT("Vertical scroll thumb height"   ),
    SM_CXHTHUMB         , TEXT("SM_CXHTHUMB"         ), TEXT("Horizontal scroll thumb width"  ),
    SM_CXICON           , TEXT("SM_CXICON"           ), TEXT("Icon width"                     ),
    SM_CYICON           , TEXT("SM_CYICON"           ), TEXT("Icon height"                    ),
    SM_CXCURSOR         , TEXT("SM_CXCURSOR"         ), TEXT("Cursor width"                   ),
    SM_CYCURSOR         , TEXT("SM_CYCURSOR"         ), TEXT("Cursor height"                  ),
    SM_CYMENU           , TEXT("SM_CYMENU"           ), TEXT("Menu bar height"                ),
    SM_CXFULLSCREEN     , TEXT("SM_CXFULLSCREEN"     ), TEXT("Full screen client area width"  ),
    SM_CYFULLSCREEN     , TEXT("SM_CYFULLSCREEN"     ), TEXT("Full screen client area height" ),
    SM_CYKANJIWINDOW    , TEXT("SM_CYKANJIWINDOW"    ), TEXT("Kanji window height"            ),
    SM_MOUSEPRESENT     , TEXT("SM_MOUSEPRESENT"     ), TEXT("Mouse present flag"             ),
    SM_CYVSCROLL        , TEXT("SM_CYVSCROLL"        ), TEXT("Vertical scroll arrow height"   ),
    SM_CXHSCROLL        , TEXT("SM_CXHSCROLL"        ), TEXT("Horizontal scroll arrow width"  ),
    SM_DEBUG            , TEXT("SM_DEBUG"            ), TEXT("Debug version flag"             ),
    SM_SWAPBUTTON       , TEXT("SM_SWAPBUTTON"       ), TEXT("Mouse buttons swapped flag"     ),
    SM_CXMIN            , TEXT("SM_CXMIN"            ), TEXT("Minimum window width"           ),
    SM_CYMIN            , TEXT("SM_CYMIN"            ), TEXT("Minimum window height"          ),
    SM_CXSIZE           , TEXT("SM_CXSIZE"           ), TEXT("Min/Max/Close button width"     ),
    SM_CYSIZE           , TEXT("SM_CYSIZE"           ), TEXT("Min/Max/Close button height"    ),
    SM_CXSIZEFRAME      , TEXT("SM_CXSIZEFRAME"      ), TEXT("Window sizing frame width"      ),
    SM_CYSIZEFRAME      , TEXT("SM_CYSIZEFRAME"      ), TEXT("Window sizing frame height"     ),
    SM_CXMINTRACK       , TEXT("SM_CXMINTRACK"       ), TEXT("Minimum window tracking width"  ),
    SM_CYMINTRACK       , TEXT("SM_CYMINTRACK"       ), TEXT("Minimum window tracking height" ),
    SM_CXDOUBLECLK      , TEXT("SM_CXDOUBLECLK"      ), TEXT("Double click x tolerance"       ),
    SM_CYDOUBLECLK      , TEXT("SM_CYDOUBLECLK"      ), TEXT("Double click y tolerance"       ),
    SM_CXICONSPACING    , TEXT("SM_CXICONSPACING"    ), TEXT("Horizontal icon spacing"        ),
    SM_CYICONSPACING    , TEXT("SM_CYICONSPACING"    ), TEXT("Vertical icon spacing"          ),
    SM_MENUDROPALIGNMENT, TEXT("SM_MENUDROPALIGNMENT"), TEXT("Left or right menu drop"        ),
    SM_PENWINDOWS       , TEXT("SM_PENWINDOWS"       ), TEXT("Pen extensions installed"       ),
    SM_DBCSENABLED      , TEXT("SM_DBCSENABLED"      ), TEXT("Double-Byte Char Set enabled"   ),
    SM_CMOUSEBUTTONS    , TEXT("SM_CMOUSEBUTTONS"    ), TEXT("Number of mouse buttons"        ),
    SM_SECURE           , TEXT("SM_SECURE"           ), TEXT("Security present flag"          ),
    SM_CXEDGE           , TEXT("SM_CXEDGE"           ), TEXT("3-D border width"               ),
    SM_CYEDGE           , TEXT("SM_CYEDGE"           ), TEXT("3-D border height"              ),
    SM_CXMINSPACING     , TEXT("SM_CXMINSPACING"     ), TEXT("Minimized window spacing width" ),
    SM_CYMINSPACING     , TEXT("SM_CYMINSPACING"     ), TEXT("Minimized window spacing height"),
    SM_CXSMICON         , TEXT("SM_CXSMICON"         ), TEXT("Small icon width"               ),
    SM_CYSMICON         , TEXT("SM_CYSMICON"         ), TEXT("Small icon height"              ),
    SM_CYSMCAPTION      , TEXT("SM_CYSMCAPTION"      ), TEXT("Small caption height"           ),
    SM_CXSMSIZE         , TEXT("SM_CXSMSIZE"         ), TEXT("Small caption button width"     ),
    SM_CYSMSIZE         , TEXT("SM_CYSMSIZE"         ), TEXT("Small caption button height"    ),
    SM_CXMENUSIZE       , TEXT("SM_CXMENUSIZE"       ), TEXT("Menu bar button width"          ),
    SM_CYMENUSIZE       , TEXT("SM_CYMENUSIZE"       ), TEXT("Menu bar button height"         ),
    SM_ARRANGE          , TEXT("SM_ARRANGE"          ), TEXT("How minimized windows arranged" ),
    SM_CXMINIMIZED      , TEXT("SM_CXMINIMIZED"      ), TEXT("Minimized window width"         ),
    SM_CYMINIMIZED      , TEXT("SM_CYMINIMIZED"      ), TEXT("Minimized window height"        ),
    SM_CXMAXTRACK       , TEXT("SM_CXMAXTRACK"       ), TEXT("Maximum dragable width"         ),
    SM_CYMAXTRACK       , TEXT("SM_CYMAXTRACK"       ), TEXT("Maximum dragable height"        ),
    SM_CXMAXIMIZED      , TEXT("SM_CXMAXIMIZED"      ), TEXT("Width of maximized window"      ),
    SM_CYMAXIMIZED      , TEXT("SM_CYMAXIMIZED"      ), TEXT("Height of maximized window"     ),
    SM_NETWORK          , TEXT("SM_NETWORK"          ), TEXT("Network present flag"           ),
    SM_CLEANBOOT        , TEXT("SM_CLEANBOOT"        ), TEXT("How system was booted"          ),
    SM_CXDRAG           , TEXT("SM_CXDRAG"           ), TEXT("Avoid drag x tolerance"         ),
    SM_CYDRAG           , TEXT("SM_CYDRAG"           ), TEXT("Avoid drag y tolerance"         ),
    SM_SHOWSOUNDS       , TEXT("SM_SHOWSOUNDS"       ), TEXT("Present sounds visually"        ),
    SM_CXMENUCHECK      , TEXT("SM_CXMENUCHECK"      ), TEXT("Menu check-mark width"          ),
    SM_CYMENUCHECK      , TEXT("SM_CYMENUCHECK"      ), TEXT("Menu check-mark height"         ),
    SM_SLOWMACHINE      , TEXT("SM_SLOWMACHINE"      ), TEXT("Slow processor flag"            ),
    SM_MIDEASTENABLED   , TEXT("SM_MIDEASTENABLED"   ), TEXT("Hebrew and Arabic enabled flag" ),
    SM_MOUSEWHEELPRESENT, TEXT("SM_MOUSEWHEELPRESENT"), TEXT("Mouse wheel present flag"       ),
    SM_XVIRTUALSCREEN   , TEXT("SM_XVIRTUALSCREEN"   ), TEXT("Virtual screen x origin"        ),
    SM_YVIRTUALSCREEN   , TEXT("SM_YVIRTUALSCREEN"   ), TEXT("Virtual screen y origin"        ),
    SM_CXVIRTUALSCREEN  , TEXT("SM_CXVIRTUALSCREEN"  ), TEXT("Virtual screen width"           ),
    SM_CYVIRTUALSCREEN  , TEXT("SM_CYVIRTUALSCREEN"  ), TEXT("Virtual screen height"          ),
    SM_CMONITORS        , TEXT("SM_CMONITORS"        ), TEXT("Number of monitors"             ),
    SM_SAMEDISPLAYFORMAT, TEXT("SM_SAMEDISPLAYFORMAT"), TEXT("Same color format flag"         ),
};

class SystemMetricsWindow : public gui::Window
{
private:

    int cxChar, cxCaps, cyChar;

protected:

    virtual bool OnCreate() override
    {
        autox hwnd = GetWindowHandle();
        autox hdc  = GetDC(hwnd);
        autox tm   = TEXTMETRIC();
        GetTextMetrics(hdc, &tm);
        cxChar = tm.tmAveCharWidth;
        cxCaps = ((tm.tmPitchAndFamily & 1) ? 3 : 2) * cxChar / 2;
        cyChar = tm.tmHeight + tm.tmExternalLeading;
        ReleaseDC(hwnd, hdc);
        return true;
    }

    virtual LRESULT CALLBACK OnEvent(UINT message, WPARAM wparam, LPARAM lparam) override
    {
        autox hwnd = GetWindowHandle();
        autox hdc  = HDC();
        autox ps   = PAINTSTRUCT();

        TCHAR szBuffer[10];

        switch (message)
        {
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            for (int i = 0; i < NUMLINES; i++)
            {
                autox label = sysmetrics[i].szLabel;
                autox desc  = sysmetrics[i].szDesc;

                TextOut(hdc, 0, cyChar * i, label, lstrlen(label));
                TextOut(hdc, 22 * cxCaps, cyChar * i, desc, lstrlen(desc));
                SetTextAlign(hdc, TA_RIGHT | TA_TOP);
                TextOut(hdc, 22 * cxCaps + 40 * cxChar, cyChar * i, szBuffer, wsprintf(szBuffer, TEXT("%5d"), GetSystemMetrics(sysmetrics[i].iIndex)));
                SetTextAlign(hdc, TA_LEFT | TA_TOP);
            }
            EndPaint(hwnd, &ps);
            return 0;
        }

        return Window::OnEvent(message, wparam, lparam);
    }

};

#include "kv/predef/Char.hpp"

KV_QuickAddEntry
{
    autox app = make_shared<SystemMetricsWindow>();
    if (app->Initialize())
    {
        app->Run();
    }

    return 0;
};

#include "end"
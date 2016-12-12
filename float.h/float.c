#include "float.h"

#define DFRAC (49+_DOFF)
#define DMAXE ((1U<<(15-_DOFF))-1)
#define FFRAC (17+_FOFF)
#define FMAXE ((1U<<(15-_FOFF))-1)
#define LFRAC (49+_LOFF)
#define LMAXE 0x7fff
#define LOG2 0.30103

#if _D0 != 0
#define DINIT(w0, wx) wx, wx, wx, w0
#define FINIT(w0, wx) wx, w0
#define LINIT(w0, w1, wx) wx, wx, wx, w1, w0
#else
#define DINIT(w0, wx) w0, wx, wx, wx
#define FINIT(w0, wx) w0, wx
#define LINIT(w0, w1, wx) w0, w1, wx, wx, wx
#endif

_Dvals _Dbl = {
    (int)((DFRAC-1)*LOG2),
    (int)DFRAC,
    (int)((DMAXE-_DBIAS-1)*LOG2),
    (int)(DMAXE-_DBIAS-1),
    (int)(-_DBIAS*LOG2),
    (int)(1-_DBIAS),
    {DINIT((_DBIAS-DFRAC+2)<<_DOFF, 0)},
    {DINIT((DMAXE<<_DOFF)-1, ~0)},
    {DINIT(1<<_DOFF, 0)},
};

_Dvals _Flt = {
    (int)((FFRAC-1)*LOG2),
    (int)FFRAC,
    (int)((FMAXE-_FBIAS-1)*LOG2),
    (int)(FMAXE-_FBIAS-1),
    (int)(-_FBIAS*LOG2),
    (int)(1-_FBIAS),
    {FINIT((_FBIAS-FFRAC+2)<<_FOFF, 0)},
    {FINIT((FMAXE<<_FOFF)-1, ~0)},
    {FINIT(1<<_FOFF, 0)},
};

#if _DLONG
_Dvals _Ldbl = {
    (int)((LFRAC-1)*LOG2),
    (int)LFRAC,
    (int)((LMAXE-_LBIAS-1)*LOG2),
    (int)(LMAXE-_LBIAS-1),
    (int)(-_LBIAS*LOG2),
    (int)(1-_LBIAS),
    {LINIT(_LBIAS-LFRAC+2, 0x8000, 0)},
    {LINIT(LMAXE-1, ~0, ~0)},
    {LINIT(1, 0x8000, 0)},
};
#else
_Dvals _Labl = {
    (int)((DFRAC-1)*LOG2),
    (int)DFRAC,
    (int)((DMAXE-_DBIAS-1)*LOG2),
    (int)(DMAXE-_DBIAS-1),
    (int)(-_DBIAS*LOG2),
    (int)(1-_DBIAS),
    {DINIT((_DBIAS-LFRAC+2)<<_DOFF, 0)},
    {DINIT((DMAXE<<_DOFF)-1, ~0)},
    {DINIT(1<<_DOFF, 0)},
};
#endif

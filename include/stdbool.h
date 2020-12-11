#ifndef _STDBOOL_H_
#define _STDBOOL_H_

#ifndef __cpluscplus

#define bool _Bool
#define true 1
#define false 0

#else

#define _Bool bool
#define bool bool
#define false false
#define true true

#endif

#define __bool_true_false_are_defined

#endif

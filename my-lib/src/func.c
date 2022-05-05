#include <stdio.h>
#include "extern-c-def.h"
#include "new-line-def.h"

#include "func.c.h"

void c_internal()
{
    printf("%s" MY_NEW_LINE, __FUNCTION__ );
   
}


void c_api()
{
    c_internal();
    printf("%s" MY_NEW_LINE, __FUNCTION__ );
}
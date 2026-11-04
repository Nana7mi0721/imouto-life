
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 2003 Release */

void __cdecl ___tzset(void)

{
  if (DAT_00a1fefc == 0) {
    __lock(6);
    if (DAT_00a1fefc == 0) {
      __tzset_lk();
      DAT_00a1fefc = DAT_00a1fefc + 1;
    }
    FUN_00506f94();
  }
  return;
}


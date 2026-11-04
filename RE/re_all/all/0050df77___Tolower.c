
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __Tolower
   
   Library: Visual Studio 2003 Release */

int __cdecl __Tolower(int param_1,_Ctypevec *param_2)

{
  int iVar1;
  uint uVar2;
  LONG *pLVar3;
  
  if (param_2 == (_Ctypevec *)0x0) {
    iVar1 = ____lc_handle_func();
    uVar2 = *(uint *)(iVar1 + 8);
  }
  else {
    uVar2 = param_2->_Page;
  }
  if (uVar2 == 0) {
    if ((0x40 < param_1) && (param_1 < 0x5b)) {
      param_1 = param_1 + 0x20;
    }
  }
  else {
    pLVar3 = (LONG *)FUN_004fd92e();
    InterlockedIncrement(pLVar3);
    iVar1 = FUN_004fd928();
    if (iVar1 != 0) {
      pLVar3 = (LONG *)FUN_004fd92e();
      InterlockedDecrement(pLVar3);
      __lock(0xc);
    }
    param_1 = __Tolower_lk(param_1,param_2);
    FUN_0050e006();
  }
  return param_1;
}


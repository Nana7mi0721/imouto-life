
undefined4 __fastcall FUN_005646a0(undefined4 param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = 0;
  if (*param_2 != 0) {
    iVar2 = 1;
    do {
      if ((param_2[iVar1] & 0xfc00U) == 0xd800) {
        if (iVar1 == unaff_ESI) {
          return 1;
        }
        if (iVar2 == unaff_ESI) {
          return 2;
        }
        iVar1 = iVar1 + 2;
        iVar2 = iVar2 + 2;
      }
      else {
        if (iVar1 == unaff_ESI) {
          return 0;
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 1;
      }
    } while (param_2[iVar1] != 0);
  }
  return 0xffffffff;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00563b10(int param_1)

{
  int iVar1;
  
  DAT_00aa7004 = param_1;
  if ((param_1 == 0) && (DAT_00aa7008 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  if (iVar1 != DAT_00aa700c) {
    if (DAT_00aba1bc != (code *)0x0) {
      (*DAT_00aba1bc)(DAT_00a20bec,iVar1);
    }
    DAT_00aa700c = iVar1;
    if (iVar1 == 0) {
      FUN_0056e1d0(DAT_00aa6ffc);
      DAT_00aa6ffc = iVar1;
      DAT_00aa7000 = iVar1;
      FUN_0056d380(&DAT_00aa5ff8,0,0x400);
      _DAT_00aa5ff0 = 0;
    }
  }
  return 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0042f5b0(char param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007ace57;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00a1b150 & 1) == 0) {
    DAT_00a1b150 = DAT_00a1b150 | 1;
    local_8 = 0;
    ExceptionList = &local_10;
    _DAT_00a1b14c = FUN_00550060(0);
  }
  if ((DAT_00a1b150 & 2) == 0) {
    DAT_00a1b150 = DAT_00a1b150 | 2;
    local_8 = 1;
    DAT_00a1b148 = FUN_00550060(0);
  }
  local_8 = 0xffffffff;
  if (param_1 != '\0') {
    DAT_00a1b144 = DAT_00a1b144 + 1;
    iVar1 = FUN_00550060(0);
    if (499 < iVar1 - _DAT_00a1b14c) {
      (&DAT_00a1b138)[DAT_00a1b140] = DAT_00a1b144;
      DAT_00a1b140 = DAT_00a1b140 + 1 & 0x80000001;
      if ((int)DAT_00a1b140 < 0) {
        DAT_00a1b140 = (DAT_00a1b140 - 1 | 0xfffffffe) + 1;
      }
      DAT_00a1b144 = 0;
      _DAT_00a1b14c = FUN_00550060(0);
    }
  }
  iVar1 = FUN_00550060(0);
  if (999 < iVar1 - DAT_00a1b148) {
    DAT_00a1b148 = DAT_00a1b148 + 1000;
    DAT_00a18a28 = DAT_00a18a28 + 1;
  }
  iVar1 = FUN_00550060(0);
  _DAT_00a18a30 = iVar1 - DAT_00a1b148;
  DAT_00a18a3c = DAT_00a1b138 + _DAT_00a1b13c;
  ExceptionList = local_10;
  return DAT_00a1b138 + _DAT_00a1b13c;
}


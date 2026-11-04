
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00516980(int param_1)

{
  int *piVar1;
  int iVar2;
  tagPOINT local_8;
  
  if (DAT_00a37ef8 == 0) {
    FUN_00567fe0();
  }
  if (param_1 < 0) {
    GetCursorPos(&local_8);
    iVar2 = 0;
    if (0 < DAT_00a37ef4) {
      piVar1 = (int *)(DAT_00a37ef8 + 4);
      do {
        if ((((piVar1[-1] <= local_8.x) && (local_8.x < piVar1[1])) && (*piVar1 <= local_8.y)) &&
           (local_8.y < piVar1[2])) break;
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 0x4c;
      } while (iVar2 < DAT_00a37ef4);
    }
    if (iVar2 != DAT_00a37ef4) {
      param_1 = iVar2;
    }
    if (param_1 < 0) {
      return 0xffffffff;
    }
  }
  if (param_1 < DAT_00a37ef4) {
    _DAT_00a37ef0 = param_1;
    DAT_00a37eec = 1;
    return 0;
  }
  return 0xffffffff;
}


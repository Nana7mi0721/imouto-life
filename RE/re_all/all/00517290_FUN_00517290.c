
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00517290(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  param_2 = param_2 - _DAT_00a37eb0;
  param_1 = param_1 - _DAT_00a37eac;
  if (DAT_00a37e80 != 0) {
    if (DAT_00a37e80 == 1) {
      if (param_3 != (int *)0x0) {
        *param_3 = param_1;
      }
      if (param_4 == (int *)0x0) {
        return 0;
      }
      *param_4 = param_2;
      return 0;
    }
    if (DAT_00a37e80 != 2) {
      return 0;
    }
  }
  iVar1 = FUN_00517170();
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = ((param_1 - DAT_00a37e9c) * DAT_00a37e60) / (DAT_00a37ea4 - DAT_00a37e9c);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = ((param_2 - DAT_00a37ea0) * DAT_00a37e64) / (DAT_00a37ea8 - DAT_00a37ea0);
  }
  return 0;
}


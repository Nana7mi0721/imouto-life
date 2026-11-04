
undefined4 FUN_0055fa80(int param_1,int *param_2,int *param_3,char param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_2[0x482] != 1) {
    if (param_3 != (int *)0x0) {
      *param_3 = (int)(param_2 + 0x31);
    }
    return 0;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = (int)(param_2 + 0x31);
  }
  uVar1 = param_2[0x484];
  if (uVar1 == 0xffffffff) {
    iVar2 = param_2[0x486];
  }
  else {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)uVar1 < 0) {
      return 0xffffffff;
    }
    if ((uVar1 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(uVar1 & 0xffff)) {
      return 0xffffffff;
    }
    param_2 = *(int **)(DAT_00cc4db4 + (uVar1 & 0xffff) * 4);
    if (param_2 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*param_2 * 0x10000 != (uVar1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (param_2[4] != 0) {
      return 0xffffffff;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = (int)(param_2 + 0x31);
    }
    iVar2 = param_2[0x486];
  }
  if (iVar2 == -1) {
    param_2[0x486] = param_1;
    return 0;
  }
  if (param_1 != iVar2) {
    if (param_4 == '\0') {
      return 0xffffffff;
    }
    if (param_1 != iVar2) {
      FUN_0055e7e0(iVar2);
    }
  }
  param_2[0x486] = param_1;
  return 0;
}


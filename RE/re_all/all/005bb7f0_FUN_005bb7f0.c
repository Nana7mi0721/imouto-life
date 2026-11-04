
undefined4 FUN_005bb7f0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (0xe < param_1 + param_2) {
    return 0xffffffff;
  }
  if (DAT_00ef7324 == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      piVar2 = &DAT_00f136b0 + param_1;
      do {
        if (*piVar2 != *(int *)(param_3 + uVar1 * 4)) break;
        uVar1 = uVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar1 < param_2);
    }
    if (uVar1 == param_2) {
      return 0;
    }
  }
  FUN_005d2b30(param_1,param_2,param_3);
  uVar1 = 0;
  if (param_2 != 0) {
    puVar3 = &DAT_00f136b0 + param_1;
    do {
      *puVar3 = *(undefined4 *)(param_3 + uVar1 * 4);
      uVar1 = uVar1 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar1 < param_2);
  }
  return 0;
}


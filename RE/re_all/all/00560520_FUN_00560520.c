
undefined4
FUN_00560520(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,int param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  iVar1 = FUN_0057e0e0();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  if (param_8 == 0) {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_5 < 0) {
      return 0xffffffff;
    }
    if ((param_5 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_5 & 0xffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_00cc4db4 + (param_5 & 0xffff) * 4);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 * 0x10000 != (param_5 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar4[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_5 < 0) {
      return 0xffffffff;
    }
    if ((param_5 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_5 & 0xffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_00cc4db4 + (param_5 & 0xffff) * 4);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 * 0x10000 != (param_5 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  if (param_6 == 3) {
    param_6 = 2;
  }
  iVar1 = FUN_0052d000(param_2,param_3);
  if (iVar1 == 0) {
    FUN_0056bca0(&DAT_007d6788);
    return 0xffffffff;
  }
  local_4 = iVar1;
  puVar2 = (undefined4 *)FUN_0052c7a0();
  local_1c = *puVar2;
  local_18 = puVar2[1];
  local_14 = puVar2[2];
  local_10 = puVar2[3];
  local_c = puVar2[4];
  local_8 = puVar2[5];
  iVar3 = FUN_0055fb70(param_1,&local_1c,param_4,param_5,param_6,&local_20,param_7,param_8);
  if (iVar3 == -1) {
    FUN_0056bca0(&DAT_007d6740);
    return 0xffffffff;
  }
  if (local_20 == 1) {
    FUN_0052d050(iVar1);
  }
  *(undefined1 *)(piVar4[0x92d] + 0x24af + (int)piVar4) = 1;
  return 0;
}


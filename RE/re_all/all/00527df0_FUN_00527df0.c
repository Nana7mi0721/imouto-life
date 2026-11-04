
undefined4 FUN_00527df0(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_450;
  undefined4 local_44c;
  int local_448;
  int local_444;
  undefined1 local_440 [1088];
  
  if (param_6 == 0) {
    if (DAT_00cc47d0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_1 < 0) {
      return 0xffffffff;
    }
    if ((param_1 & 0x7c000000) != DAT_00cc47f8) {
      return 0xffffffff;
    }
    if (DAT_00cc4800 <= (int)(param_1 & 0xffff)) {
      return 0xffffffff;
    }
    piVar3 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar3 * 0x10000 != (param_1 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar3[4] != 0) {
      return 0xffffffff;
    }
  }
  else if ((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8))
          || (((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
               (piVar3 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar3 == (int *)0x0)) ||
              (*piVar3 * 0x10000 != (param_1 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0xff < param_2) {
    param_2 = 0xff;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xff < param_3) {
    param_3 = 0xff;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (0xff < param_4) {
    param_4 = 0xff;
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (0xff < param_5) {
    param_5 = 0xff;
  }
  if (*(char *)(piVar3[0x13] + 8) == '\0') {
    local_450 = 0;
    local_44c = 0;
    local_448 = piVar3[0x18];
    local_444 = piVar3[0x19];
    uVar2 = FUN_00543f70(param_2,param_3,param_4);
    FUN_00761390(piVar3 + 0x22,&local_450,uVar2);
    return 0;
  }
  iVar1 = FUN_00568a00(piVar3,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 == 2) {
    iVar1 = FUN_00546c90(piVar3[0x18],piVar3[0x19],local_440);
    if (iVar1 == 0) {
      FUN_005492e0(local_440,param_2,param_3,param_4,param_5);
      FUN_00525f80(0,0,0,0,local_440,0,0,0,param_1);
      FUN_005421c0(local_440);
      return 0;
    }
  }
  else if (-1 < iVar1) {
    return 0;
  }
  return 0xffffffff;
}


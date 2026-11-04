
undefined4 FUN_005965e0(int param_1,undefined4 param_2,byte param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4[3] == 1) && ((param_3 & 4) != 0)) {
    iVar1 = FUN_0056d130(&DAT_007d9f18,param_1 + 0x11c);
    if (((iVar1 == 0) || (iVar1 = FUN_0056d130(&DAT_007d9f10,param_1 + 0x11c), iVar1 == 0)) &&
       (*(short *)(param_1 + 0x5c) != 0x40)) goto LAB_0059663d;
  }
  if (param_4[3] != 0) {
    return 1;
  }
  if (*(short *)(param_1 + 0x5c) == 0x40) {
    return 1;
  }
LAB_0059663d:
  iVar1 = 0;
  if (0 < param_4[1]) {
    iVar3 = 0;
    do {
      iVar2 = FUN_0056d130(param_1 + 0x5c,*param_4 + iVar3);
      if (iVar2 == 0) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x80;
    } while (iVar1 < param_4[1]);
  }
  FUN_0056cf70(param_4[1] * 0x80 + *param_4,0x80,param_1 + 0x5c);
  param_4[1] = param_4[1] + 1;
  if ((param_4[2] == 0) || (param_4[2] != param_4[1])) {
    return 1;
  }
  return 0;
}


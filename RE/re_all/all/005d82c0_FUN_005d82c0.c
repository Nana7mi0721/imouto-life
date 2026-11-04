
undefined4
FUN_005d82c0(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,int param_11,int param_12,int param_13,
            int param_14,int param_15,int param_16,int param_17)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_0056d380(param_1,0,0x2320);
  puVar1 = param_1 + 0x1d;
  FUN_0056da30(puVar1);
  FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x4cf);
  if (param_3 == 0) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = param_3 + 0xfU & 0xfffffff0;
  }
  param_1[8] = uVar2;
  param_1[1] = param_5;
  param_1[7] = param_2;
  *param_1 = param_4;
  param_1[4] = param_8;
  param_1[2] = param_6;
  param_1[3] = param_7;
  param_1[5] = param_9;
  param_1[6] = param_10;
  param_1[0xb] = param_13;
  if (param_13 != 0) {
    if ((((param_14 < 1) || (param_15 == 0)) || (param_16 < 1)) || (param_17 == 0))
    goto LAB_005d8456;
    param_1[0x10] = param_16;
    param_1[0xc] = param_14;
    param_1[0xe] = param_15;
    param_1[0x12] = param_17;
    FUN_0056d380(param_15,0,param_14 * 0x48);
    FUN_0056d380(param_17,0,param_16 * 0x4c);
    param_1[0xf] = param_15;
    if (1 < param_14) {
      iVar4 = param_15 + 0x48;
      *(int *)(param_15 + 0x3c) = iVar4;
      if (1 < param_14 + -1) {
        param_14 = param_14 + -2;
        iVar3 = iVar4;
        do {
          param_14 = param_14 + -1;
          *(int *)(iVar3 + 0x38) = iVar3 + -0x48;
          iVar4 = iVar3 + 0x48;
          *(int *)(iVar3 + 0x3c) = iVar4;
          iVar3 = iVar4;
        } while (param_14 != 0);
      }
      *(int *)(iVar4 + 0x38) = iVar4 + -0x48;
    }
    param_1[0x13] = param_17;
    if (1 < param_16) {
      iVar4 = param_17 + 0x4c;
      *(int *)(param_17 + 0x24) = iVar4;
      if (1 < param_16 + -1) {
        param_16 = param_16 + -2;
        iVar3 = iVar4;
        do {
          param_16 = param_16 + -1;
          *(int *)(iVar3 + 0x20) = iVar3 + -0x4c;
          iVar4 = iVar3 + 0x4c;
          *(int *)(iVar3 + 0x24) = iVar4;
          iVar3 = iVar4;
        } while (param_16 != 0);
      }
      *(int *)(iVar4 + 0x20) = iVar4 + -0x4c;
    }
  }
  if (((param_11 == 0) || (param_12 == 0)) ||
     (iVar4 = FUN_005d72e0(param_1,param_11,param_12), -1 < iVar4)) {
    FUN_0056dac0(puVar1);
    return 0;
  }
LAB_005d8456:
  FUN_0056dac0(puVar1);
  return 0xffffffff;
}


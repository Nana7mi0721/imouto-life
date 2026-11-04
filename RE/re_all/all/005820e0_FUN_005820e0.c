
undefined4
FUN_005820e0(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_10 [4];
  
  if (*param_1 == 0x12345678) {
    return 0xffffffff;
  }
  if (param_1[5] == 0) {
    iVar2 = FUN_0056e050(0x50,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemImg.cpp",0x12a);
    param_1[5] = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
  }
  puVar1 = (undefined4 *)param_1[5];
  if (param_7 == 1) {
    param_8 = 0;
  }
  if ((param_6 == 2) || (param_6 == 3)) {
    param_7 = 0;
    param_8 = 0;
  }
  puVar1[1] = param_2;
  *puVar1 = 1;
  puVar1[2] = param_3;
  puVar1[6] = 1;
  puVar1[7] = param_5;
  puVar1[8] = param_6;
  puVar1[9] = param_7;
  puVar1[0xb] = param_8;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  if (param_7 == 1) {
    iVar2 = FUN_0056e050(0x800,"..\\..\\..\\..\\Source\\Library\\Main\\DxMemImg.cpp",0x149);
    puVar1[0xf] = iVar2;
    puVar1[0x10] = iVar2 + 0x400;
  }
  else {
    puVar1[0xf] = 0;
    puVar1[0x10] = 0;
  }
  local_10[0] = 2;
  local_10[1] = 4;
  local_10[2] = 1;
  local_10[3] = 2;
  iVar2 = local_10[param_6];
  if (param_7 == 1) {
    iVar2 = 1;
  }
  if ((param_8 == 1) && (param_6 == 0)) {
    iVar2 = 4;
  }
  if (param_4 == -1) {
    iVar5 = iVar2 * param_2;
  }
  else {
    iVar5 = param_4;
  }
  iVar6 = 0;
  iVar3 = 1;
  if (1 < iVar5) {
    do {
      iVar3 = iVar3 * 2;
      iVar6 = iVar6 + 1;
    } while (iVar3 < iVar5);
  }
  if (param_4 == -1) {
    puVar1[3] = iVar2 * param_2 + 0xfU & 0xfffffff0;
  }
  else {
    puVar1[3] = param_4;
  }
  if (puVar1[3] != iVar3) {
    iVar6 = -1;
  }
  puVar1[4] = iVar6;
  uVar4 = FUN_00581c90(puVar1[8],puVar1[0xb],puVar1[9]);
  puVar1[5] = uVar4;
  if (param_10 == 0) {
    iVar2 = FUN_0056e030(puVar1[2] * puVar1[3],"..\\..\\..\\..\\Source\\Library\\Main\\DxMemImg.cpp"
                         ,0x19f);
    puVar1[0x11] = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    puVar1[0xe] = 0;
  }
  else {
    puVar1[0x11] = param_10;
    puVar1[0xe] = 1;
  }
  if (((puVar1[0xb] != 0) && (puVar1[0x12] == 0)) && (param_9 != 0)) {
    iVar2 = FUN_0056e030(puVar1[2] * puVar1[3],"..\\..\\..\\..\\Source\\Library\\Main\\DxMemImg.cpp"
                         ,0x1ad);
    puVar1[0x12] = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
  }
  if (((puVar1[8] != 2) && (puVar1[0x13] == 0)) && (param_9 != 0)) {
    iVar2 = FUN_0056e030((puVar1[1] + 5) * puVar1[2],
                         "..\\..\\..\\..\\Source\\Library\\Main\\DxMemImg.cpp",0x1b5);
    puVar1[0x13] = iVar2;
    if (iVar2 == 0) {
      return 0xffffffff;
    }
  }
  *param_1 = 0x12345678;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[3] = puVar1[0x11];
  param_1[4] = puVar1[0x12];
  return 0;
}


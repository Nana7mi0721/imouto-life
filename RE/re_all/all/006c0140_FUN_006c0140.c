
int FUN_006c0140(int *param_1,int param_2,int *param_3,undefined4 *param_4,uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined1 auStack_10 [16];
  
  uVar1 = param_5;
  piVar6 = param_1;
  for (iVar4 = 0x8d0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = 0;
    piVar6 = piVar6 + 1;
  }
  param_1[0xe] = -1;
  param_1[0xf] = -1;
  param_1[4] = param_2;
  *param_1 = *param_3;
  param_1[1] = param_3[1];
  param_1[2] = param_3[2];
  param_1[3] = param_3[3];
  if (*param_1 == 0) {
    return -0x80;
  }
  piVar6 = param_1 + 0x10;
  FUN_006a86a0(piVar6);
  if (param_5 != 0) {
    puVar2 = (undefined4 *)FUN_006a8700(piVar6,param_5);
    for (uVar5 = param_5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar2 = *param_4;
      param_4 = param_4 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar5 = param_5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_4;
      param_4 = (undefined4 *)((int)param_4 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    FUN_006a87a0(piVar6,param_5);
  }
  if (((code *)param_3[1] == (code *)0x0) ||
     (iVar4 = (*(code *)param_3[1])(param_2,0,0,1), iVar4 == -1)) {
    param_5 = 0;
  }
  else {
    param_5 = 1;
    if ((code *)param_1[2] == (code *)0x0) {
      return -0x83;
    }
    uVar7 = (*(code *)param_1[2])(param_1[4]);
    if (((uint)uVar7 != uVar1) || ((int)((ulonglong)uVar7 >> 0x20) != 0)) {
      return -0x83;
    }
  }
  param_1[5] = param_5;
  pvVar3 = _malloc(0x160);
  param_1[7] = (int)pvVar3;
  FUN_006a83f0(param_1 + 0x22,0xffffffff);
  iVar4 = FUN_006c0350(param_1,param_1[7] + 0x2c,param_1[7] + 0x14c,param_1 + 10,param_1 + 8,
                       param_1 + 9,0);
  if (-1 < iVar4) {
    while( true ) {
      puVar2 = (undefined4 *)param_1[7];
      param_1[6] = 1;
      *puVar2 = 0;
      puVar2[1] = 0;
      iVar4 = param_1[7];
      *(int *)(iVar4 + 8) = param_1[0xc];
      *(int *)(iVar4 + 0xc) = param_1[0xd];
      iVar4 = param_1[7];
      *(undefined4 *)(iVar4 + 0x18) = 0xffffffff;
      *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
      *(int *)(param_1[7] + 0x28) = param_1[0x76];
      iVar4 = FUN_006c08d0(param_1,param_1[7],auStack_10);
      if ((param_5 != 0) || (iVar4 < 1)) break;
      FUN_006c4970(param_1[7] + 0x14c);
      param_1[0x18] = param_1[0x18] + 1;
      param_1[6] = 0;
      iVar4 = FUN_006c0350(param_1,param_1[7] + 0x2c,param_1[7] + 0x14c,param_1 + 10,param_1 + 8,
                           param_1 + 9,auStack_10);
      if (iVar4 < 0) {
        return iVar4;
      }
    }
    if (-1 < iVar4) {
      param_1[0x17] = 1;
    }
  }
  return iVar4;
}


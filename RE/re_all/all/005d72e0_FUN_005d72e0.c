
undefined4 FUN_005d72e0(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined1 local_20 [32];
  
  piVar4 = param_1;
  piVar1 = param_1 + 0x1d;
  bVar3 = false;
  FUN_0056da60(piVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x55f);
  if (param_2 == 0) {
    if (*param_1 == 0) goto LAB_005d766a;
    if (param_3 < 0x100000) {
      param_3 = 0x100000;
    }
    uVar8 = param_3 + 0x1f & 0xfffffff0;
    if ((param_1[0xb] == 0) && (uVar8 < 0xe0)) {
      FUN_0056bca0(&DAT_00800058,uVar8,0xe0);
      FUN_0056dac0(piVar1);
      return 0xffffffff;
    }
    FUN_0056d380(local_20,0,0x20);
    iVar5 = (*(code *)param_1[3])(param_1[2],local_20,uVar8);
    if (iVar5 < 0) {
      FUN_0056bca0(&DAT_00800034);
      FUN_0056dac0(piVar1);
      return 0xffffffff;
    }
    param_3 = (*(code *)param_1[5])(param_1[2],local_20);
    param_2 = (*(code *)param_1[4])(param_1[2],local_20);
    piVar6 = (int *)(param_2 + 0xfU & 0xfffffff0);
    bVar3 = true;
    param_1 = (int *)((param_2 + param_3 & 0xfffffff0) - (int)piVar6);
LAB_005d73fa:
    if (piVar4[0xb] == 0) {
      piVar7 = piVar6;
      goto LAB_005d746e;
    }
  }
  else {
    if (param_3 == 0) goto LAB_005d766a;
    piVar6 = (int *)(param_2 + 0xfU & 0xfffffff0);
    uVar8 = (param_3 + param_2 & 0xfffffff0) - (int)piVar6;
    piVar7 = param_1 + 0xb;
    param_1 = (int *)uVar8;
    if (*piVar7 == 0) {
      if (uVar8 < 0xe0) {
        FUN_0056bca0(0x7fffe0,uVar8,0xe0);
        FUN_0056dac0(piVar1);
        return 0xffffffff;
      }
      goto LAB_005d73fa;
    }
  }
  piVar7 = (int *)piVar4[0x13];
  if (piVar7 == (int *)0x0) {
LAB_005d766a:
    FUN_0056dac0(piVar1);
    return 0xffffffff;
  }
  FUN_005d6b10();
LAB_005d746e:
  FUN_0056d380(piVar7,0,0x4c);
  if (bVar3) {
    piVar7[10] = piVar7[10] | 1;
    FUN_0056d420(piVar7 + 0xb,local_20,0x20);
  }
  *piVar7 = param_2;
  piVar7[1] = param_3;
  piVar7[2] = (int)piVar6;
  piVar7[3] = (int)param_1;
  if (piVar4[0xb] == 0) {
    piVar6 = piVar7 + 0x13;
  }
  uVar8 = (int)piVar6 + 0xfU & 0xfffffff0;
  piVar7[4] = uVar8;
  piVar7[5] = (param_2 - uVar8) + param_3 & 0xfffffff0;
  piVar7[9] = piVar4[0x14];
  piVar4[0x14] = (int)piVar7;
  if (piVar7[9] != 0) {
    *(int **)(piVar7[9] + 0x20) = piVar7;
  }
  if (piVar4[0xb] == 0) {
    puVar9 = (undefined4 *)piVar7[4];
  }
  else {
    puVar9 = (undefined4 *)piVar4[0xf];
    if (puVar9 == (undefined4 *)0x0) {
      FUN_0056dac0(piVar1);
      return 0xffffffff;
    }
    FUN_005d6ad0();
  }
  *puVar9 = 0x4d454d44;
  *(undefined1 *)((int)puVar9 + 0x16) = 0;
  iVar5 = FUN_005773c0(0x7ffd,&DAT_007fffa0);
  if (iVar5 < 0x11) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar5 + -0x11;
  }
  FUN_00576e80(0x7ffd,puVar9 + 1,&DAT_007fffa0 + iVar5);
  *(byte *)((int)puVar9 + 0x16) = *(byte *)((int)puVar9 + 0x16) & 0xfc;
  *(undefined2 *)((int)puVar9 + 0x1e) = 0;
  puVar9[0x10] = piVar4;
  *(undefined1 *)((int)puVar9 + 0x19) = *(undefined1 *)((int)piVar4 + 0x26);
  *(short *)((int)puVar9 + 0x1a) = (short)piVar4[9];
  piVar4[9] = piVar4[9] + 1;
  if (0xffffff < (uint)piVar4[9]) {
    piVar4[9] = 0;
  }
  *(short *)(puVar9 + 7) = (short)piVar4[10];
  if (piVar4[0xb] != 0) {
    puVar9[9] = piVar7[4];
  }
  puVar9[8] = piVar7[5];
  puVar9[0x11] = piVar7;
  piVar7[7] = (int)puVar9;
  if (piVar4[0xb] == 0) {
    puVar9[0x12] = 0xaaaaaaaa;
    puVar9[0x13] = 0xaaaaaaaa;
    puVar9[0x14] = 0xaaaaaaaa;
    puVar9[0x15] = 0xaaaaaaaa;
    puVar2 = (undefined4 *)((int)puVar9 + puVar9[8] + -0x10);
    *puVar2 = 0xaaaaaaaa;
    puVar2[1] = 0xaaaaaaaa;
    puVar2[2] = 0xaaaaaaaa;
    puVar2[3] = 0xaaaaaaaa;
  }
  puVar9[0xd] = piVar4[0x17];
  puVar9[0xc] = 0;
  piVar4[0x17] = (int)puVar9;
  if (puVar9[0xd] == 0) {
    piVar4[0x18] = (int)puVar9;
  }
  else {
    *(undefined4 **)(puVar9[0xd] + 0x30) = puVar9;
  }
  piVar4[0x15] = piVar4[0x15] + 1;
  piVar4[0x16] = piVar4[0x16] + puVar9[8];
  if (piVar4[7] == 0) {
    puVar9[0xe] = 0;
    puVar9[0xf] = piVar4[0x8c6];
    piVar4[0x8c6] = (int)puVar9;
    if (puVar9[0xf] == 0) {
      piVar4[0x8c7] = (int)puVar9;
      FUN_0056dac0(piVar1);
      return 0;
    }
    *(undefined4 **)(puVar9[0xf] + 0x38) = puVar9;
    FUN_0056dac0(piVar1);
    return 0;
  }
  if (piVar4[7] == 1) {
    FUN_005d6c20();
  }
  FUN_0056dac0(piVar1);
  return 0;
}


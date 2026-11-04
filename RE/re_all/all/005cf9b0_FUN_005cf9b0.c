
undefined4
FUN_005cf9b0(int param_1,int param_2,undefined4 param_3,int param_4,uint param_5,int param_6,
            undefined4 param_7,undefined4 param_8,int param_9)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  param_5 = -(uint)(param_6 != 0) & 0x880 | param_5;
  uVar4 = param_5 | 0x5000;
  if (param_4 == 0) {
    if (DAT_00ef7314 == 0) goto LAB_005cfa5c;
    uVar7 = 0;
    uVar6 = 0;
  }
  else {
    uVar4 = param_5 | 0xd000;
    if (*(char *)(*(int *)(param_4 + 0x4c) + 10) != '\0') {
      uVar4 = param_5 | 0x1d000;
    }
    if (*(char *)(*(int *)(param_4 + 0x4c) + 0x12) != '\0') {
      uVar4 = uVar4 | 0x20000;
    }
    puVar1 = (undefined4 *)(param_4 + 0x100 + param_9 * 0x78);
    if (DAT_00ef7314 == *(int *)(*(int *)*puVar1 + 4)) goto LAB_005cfa5c;
    iVar5 = *(int *)*puVar1;
    uVar7 = *(undefined4 *)(iVar5 + 8);
    uVar6 = *(undefined4 *)(iVar5 + 4);
  }
  FUN_005bc5b0(uVar6,uVar7);
LAB_005cfa5c:
  if (((DAT_00a3d360 != 0) || (DAT_00ef72cc != 0)) || (DAT_00ef72c8 != uVar4)) {
    FUN_005bcf50();
  }
  if ((DAT_00a37dcc == 0) && (0 < param_2)) {
    puVar3 = (undefined1 *)(param_1 + 0x12);
    iVar5 = param_2;
    do {
      uVar2 = puVar3[-2];
      puVar3[-2] = *puVar3;
      *puVar3 = uVar2;
      puVar3 = puVar3 + 0x1c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  FUN_005cba60(1,param_3,param_1,param_2,1);
  if ((DAT_00a37dcc == 0) && (0 < param_2)) {
    puVar3 = (undefined1 *)(param_1 + 0x12);
    do {
      uVar2 = puVar3[-2];
      puVar3[-2] = *puVar3;
      *puVar3 = uVar2;
      puVar3 = puVar3 + 0x1c;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}


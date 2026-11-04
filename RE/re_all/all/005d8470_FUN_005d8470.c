
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d8470(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_20 [32];
  
  FUN_0056da60(param_1 + 0x74,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x647);
  if (*(int *)(param_1 + 0x2c) == 0) {
    piVar4 = (int *)(param_2 + 0xfU & 0xfffffff0);
  }
  else {
    for (piVar4 = *(int **)(param_1 + 0x50); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[9]) {
      if (*piVar4 == param_2) goto LAB_005d84d8;
    }
    FUN_0056bca0(&DAT_00801718,param_2,param_2 >> 0x1f);
    _DAT_00000000 = 0xffffffff;
  }
LAB_005d84d8:
  if (piVar4[6] != 0) {
    FUN_0056bca0(&DAT_00801668,piVar4[6]);
    _DAT_00000000 = 0xffffffff;
  }
  iVar1 = piVar4[7];
  if ((*(byte *)(iVar1 + 0x16) & 4) != 0) {
    FUN_0056bca0(&DAT_00801600);
    iVar3 = iVar1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      iVar3 = *(int *)(iVar1 + 0x28);
    }
    FUN_005d7680(iVar3,*(int *)(param_1 + 0x2c));
    _DAT_00000000 = 0xffffffff;
  }
  piVar2 = *(int **)(iVar1 + 0x44);
  if (piVar2 != piVar4) {
    FUN_0056bca0(&DAT_00801518,piVar2,(int)piVar2 >> 0x1f,piVar4,(int)piVar4 >> 0x1f);
    iVar3 = iVar1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      iVar3 = *(int *)(iVar1 + 0x28);
    }
    FUN_005d7680(iVar3,*(int *)(param_1 + 0x2c));
    _DAT_00000000 = 0xffffffff;
  }
  if ((*(int *)(iVar1 + 0x34) != 0) && (*(int **)(*(int *)(iVar1 + 0x34) + 0x44) == piVar4)) {
    FUN_0056bca0(&DAT_008014b0);
    iVar3 = iVar1;
    if (*(int *)(param_1 + 0x2c) == 0) {
      iVar3 = *(int *)(iVar1 + 0x28);
    }
    FUN_005d7680(iVar3,*(int *)(param_1 + 0x2c));
    _DAT_00000000 = 0xffffffff;
  }
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) - *(int *)(iVar1 + 0x20);
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
  if (*(int *)(iVar1 + 0x30) == 0) {
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar1 + 0x34);
  }
  else {
    *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x34) = *(undefined4 *)(iVar1 + 0x34);
  }
  if (*(int *)(iVar1 + 0x34) == 0) {
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(iVar1 + 0x30);
  }
  else {
    *(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x30) = *(undefined4 *)(iVar1 + 0x30);
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (*(int *)(iVar1 + 0x38) == 0) {
      *(undefined4 *)(param_1 + 0x2318) = *(undefined4 *)(iVar1 + 0x3c);
    }
    else {
      *(undefined4 *)(*(int *)(iVar1 + 0x38) + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
    }
    if (*(int *)(iVar1 + 0x3c) == 0) {
      *(undefined4 *)(param_1 + 0x231c) = *(undefined4 *)(iVar1 + 0x38);
      *(undefined4 *)(iVar1 + 0x38) = 0;
      *(undefined4 *)(iVar1 + 0x3c) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(iVar1 + 0x3c) + 0x38) = *(undefined4 *)(iVar1 + 0x38);
      *(undefined4 *)(iVar1 + 0x38) = 0;
      *(undefined4 *)(iVar1 + 0x3c) = 0;
    }
  }
  else if (*(int *)(param_1 + 0x1c) == 1) {
    FUN_005d6ce0();
  }
  if (piVar4[8] == 0) {
    *(int *)(param_1 + 0x50) = piVar4[9];
  }
  else {
    *(int *)(piVar4[8] + 0x24) = piVar4[9];
  }
  if (piVar4[9] != 0) {
    *(int *)(piVar4[9] + 0x20) = piVar4[8];
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1;
    piVar4[9] = *(int *)(param_1 + 0x4c);
    piVar4[8] = 0;
    *(int **)(param_1 + 0x4c) = piVar4;
    if (piVar4[9] != 0) {
      *(int **)(piVar4[9] + 0x20) = piVar4;
    }
  }
  if ((*(byte *)(piVar4 + 10) & 1) != 0) {
    FUN_0056d420(local_20,piVar4 + 0xb,0x20);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 8),local_20);
  }
  FUN_0056dac0(param_1 + 0x74);
  return 0;
}


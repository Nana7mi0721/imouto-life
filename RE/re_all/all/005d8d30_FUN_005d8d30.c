
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005d8d30(int *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  char *pcVar10;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar8 = param_1;
  if (param_2 == 0) {
    piVar8 = (int *)((int)param_1 - param_1[-1]);
  }
  if (*piVar8 != 0x4d454d44) {
    FUN_0056bca0(&DAT_00801b90);
    _DAT_00000000 = 0xffffffff;
  }
  iVar2 = piVar8[0x10];
  iVar1 = iVar2 + 0x74;
  FUN_0056da60(iVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHeap.cpp",0x81b);
  if (param_3 == 0) {
    FUN_0056dac0(iVar1);
    return (int *)0x0;
  }
  if (param_4 == 0) {
    param_4 = *(uint *)(iVar2 + 0x20);
  }
  else if (param_4 < 0x10) {
    param_4 = 0x10;
  }
  uVar4 = ((param_3 + -1 + param_4) / param_4) * param_4;
  if (piVar8[0xb] == param_3) {
    *piVar8 = 0x4d454d44;
    *(byte *)((int)piVar8 + 0x16) = *(byte *)((int)piVar8 + 0x16) & 0xdf | 4;
    if (param_5 == 0) {
      pcVar10 = "NoName";
    }
    else {
      iVar5 = FUN_005773c0(0x7ffd,param_5);
      if (iVar5 < 0x11) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar5 + -0x11;
      }
      pcVar10 = (char *)(iVar5 + param_5);
    }
    FUN_00576e80(0x7ffd,piVar8 + 1,pcVar10);
    if (param_6 < 0) {
      param_6 = 0;
    }
    *(short *)((int)piVar8 + 0x1e) = (short)param_6;
    *(byte *)((int)piVar8 + 0x16) =
         (byte)((uint)param_6 >> 0x10) | *(byte *)((int)piVar8 + 0x16) & 0xfc;
    piVar8[0x10] = iVar2;
    *(undefined1 *)((int)piVar8 + 0x19) = *(undefined1 *)(iVar2 + 0x26);
    *(undefined2 *)((int)piVar8 + 0x1a) = *(undefined2 *)(iVar2 + 0x24);
    *(int *)(iVar2 + 0x24) = *(int *)(iVar2 + 0x24) + 1;
    if (0xffffff < *(uint *)(iVar2 + 0x24)) {
      *(undefined4 *)(iVar2 + 0x24) = 0;
    }
    *(undefined2 *)(piVar8 + 7) = *(undefined2 *)(iVar2 + 0x28);
    FUN_0056dac0(iVar1);
    return param_1;
  }
  if (*(int *)(iVar2 + 0x2c) == 0) {
    iVar5 = FUN_005d6a70();
    if (iVar5 < 0) {
      FUN_0056bca0(&DAT_00801b08);
      FUN_005d7680(param_1,param_2);
      _DAT_00000000 = 0xffffffff;
    }
  }
  if ((*(byte *)((int)piVar8 + 0x16) & 4) == 0) {
    FUN_0056bca0(&DAT_00801aa8);
    FUN_005d7680(param_1,param_2);
    _DAT_00000000 = 0xffffffff;
  }
  iVar5 = piVar8[10];
  iVar9 = piVar8[8];
  if (*(int *)(iVar2 + 0x2c) == 0) {
    uVar6 = (iVar9 - iVar5) + -0x10 + (int)piVar8;
  }
  else {
    uVar6 = (piVar8[9] - iVar5) + iVar9;
  }
  if ((uVar6 / param_4) * param_4 < uVar4) {
    iVar3 = piVar8[0xd];
    if (((iVar3 != 0) && ((*(byte *)((int)piVar8 + 0x16) & 8) != 0)) &&
       ((*(byte *)(iVar3 + 0x16) & 4) == 0)) {
      if (*(int *)(iVar2 + 0x2c) == 0) {
        uVar6 = (*(int *)(iVar3 + 0x20) - iVar5) + iVar9 + -0x10 + (int)piVar8;
      }
      else {
        uVar6 = ((*(int *)(iVar3 + 0x20) + piVar8[9]) - iVar5) + iVar9;
      }
      if (uVar4 <= (uVar6 / param_4) * param_4) goto LAB_005d8fda;
    }
    piVar7 = (int *)FUN_005d86c0(iVar2,param_3,param_4,0,param_5,param_6,0);
    if (piVar7 == (int *)0x0) {
      FUN_0056dac0(iVar1);
      return (int *)0x0;
    }
    if (*(int *)(iVar2 + 0x2c) == 0) {
      iVar9 = piVar8[10];
      iVar5 = (piVar8[8] - iVar5) + -0x10 + (int)piVar8;
      piVar8 = piVar7;
    }
    else {
      iVar9 = piVar8[10];
      iVar5 = (piVar8[9] - iVar5) + piVar8[8];
      piVar8 = (int *)piVar7[9];
    }
    FUN_0056d420(piVar8,iVar9,iVar5);
    FUN_005d8c60(param_1,*(undefined4 *)(iVar2 + 0x2c));
    param_1 = piVar7;
  }
  else {
LAB_005d8fda:
    FUN_005d8a70(1);
    FUN_005d6d90(piVar8,iVar5,param_3,uVar4,0,param_5,param_6,0);
  }
  FUN_0056dac0(iVar1);
  return param_1;
}



undefined4 FUN_0057e820(int param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (DAT_00aa4fa0 == 0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 200) + 0x4c))
                      (*(int **)(param_1 + 200),param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
  }
  else if (*(int *)(*(int *)(param_1 + 0x4c) + 4) != 0) {
    if (*(short *)(param_1 + 0x3e) == 8) {
      iVar3 = **(int **)(param_1 + 0x4c);
      iVar1 = (*(int **)(param_1 + 0x4c))[1];
      uVar2 = 0;
      if (param_3 != 0) {
        do {
          *(ushort *)(iVar1 + (param_2 - iVar3) * 2 + uVar2 * 2) =
               (ushort)*(byte *)(uVar2 + param_2) * 0x101;
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_3);
      }
      iVar3 = **(int **)(param_1 + 0x4c);
      iVar1 = (*(int **)(param_1 + 0x4c))[1];
      uVar2 = 0;
      if (param_5 != 0) {
        do {
          *(ushort *)(iVar1 + (param_4 - iVar3) * 2 + uVar2 * 2) =
               (ushort)*(byte *)(uVar2 + param_4) * 0x101;
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_5);
        return 0;
      }
    }
    else if (*(short *)(param_1 + 0x3e) == 0x10) {
      iVar3 = **(int **)(param_1 + 0x4c);
      iVar1 = (*(int **)(param_1 + 0x4c))[1];
      uVar2 = 0;
      if (param_3 >> 1 != 0) {
        do {
          *(uint *)(iVar1 + (param_2 - iVar3 >> 1) * 4 + uVar2 * 4) =
               (uint)*(ushort *)(param_2 + uVar2 * 2) * 0x10001;
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_3 >> 1);
      }
      iVar3 = **(int **)(param_1 + 0x4c);
      iVar1 = (*(int **)(param_1 + 0x4c))[1];
      uVar2 = 0;
      if (param_5 >> 1 != 0) {
        do {
          *(uint *)(iVar1 + (param_4 - iVar3 >> 1) * 4 + uVar2 * 4) =
               (uint)*(ushort *)(param_4 + uVar2 * 2) * 0x10001;
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_5 >> 1);
      }
    }
  }
  return 0;
}


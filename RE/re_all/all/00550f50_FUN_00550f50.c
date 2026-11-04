
int FUN_00550f50(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if (param_3 == 0) {
      return iVar4;
    }
    uVar3 = *(uint *)(param_1 + 0x1c);
    if (uVar3 == 0) {
      uVar3 = param_3;
      if (*(uint *)(param_1 + 0x20) < param_3) {
        uVar3 = *(uint *)(param_1 + 0x20);
      }
      iVar1 = FUN_00596f70(param_2,*(int *)(param_1 + 8) + *(int *)(param_1 + 0x18),uVar3);
      if (iVar1 == 0) {
        return iVar4;
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) - iVar1;
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar1;
    }
    else {
      uVar2 = param_3;
      if (uVar3 < param_3) {
        uVar2 = uVar3;
      }
      iVar1 = FUN_00596f70(param_2,*(int *)(param_1 + 4) + *(int *)(param_1 + 0x14),uVar2);
      if (iVar1 == 0) {
        return iVar4;
      }
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - iVar1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar1;
    }
    param_3 = param_3 - iVar1;
    iVar4 = iVar4 + iVar1;
  } while( true );
}


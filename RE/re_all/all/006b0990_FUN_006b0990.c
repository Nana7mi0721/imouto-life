
undefined4 FUN_006b0990(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_4;
  
  if (*(int *)(param_1 + 8) < 1) {
    return 0xffffffff;
  }
  local_4 = *(int *)(param_1 + 0x28);
  iVar2 = FUN_00797700(param_2,*(undefined4 *)(param_1 + 0x24));
  if (iVar2 < 0) {
    iVar2 = *(int *)(param_1 + 8);
    uVar6 = 0;
  }
  else {
    uVar4 = *(uint *)(*(int *)(param_1 + 0x20) + iVar2 * 4);
    if ((uVar4 & 0x80000000) == 0) {
      FUN_007977d0(param_2,(int)*(char *)(*(int *)(param_1 + 0x1c) + -1 + uVar4));
      uVar6 = uVar4 - 1;
      goto LAB_006b09fb;
    }
    uVar6 = (int)uVar4 >> 0xf & 0x7fff;
    iVar2 = *(int *)(param_1 + 8) - (uVar4 & 0x7fff);
  }
  iVar3 = FUN_00797700(param_2,local_4);
  if (iVar3 < 0) {
    do {
      if (local_4 < 2) {
        if (iVar3 < 0) {
          return 0xffffffff;
        }
        break;
      }
      local_4 = local_4 + -1;
      iVar3 = FUN_00797700(param_2,local_4);
    } while (iVar3 < 0);
  }
  uVar4 = FUN_006b05c0(iVar3);
  iVar3 = iVar2 - uVar6;
  if (1 < iVar3) {
    do {
      uVar5 = iVar3 >> 1;
      uVar1 = (uint)(uVar4 < *(uint *)(*(int *)(param_1 + 0x14) + (uVar5 + uVar6) * 4));
      iVar2 = iVar2 - (-uVar1 & uVar5);
      uVar6 = uVar6 + (uVar1 - 1 & uVar5);
      iVar3 = iVar2 - uVar6;
    } while (1 < iVar3);
  }
  iVar2 = (int)*(char *)(*(int *)(param_1 + 0x1c) + uVar6);
  if (local_4 < iVar2) {
    FUN_007977d0(param_2,local_4);
    return 0xffffffff;
  }
  FUN_007977d0(param_2,iVar2);
LAB_006b09fb:
  if ((int)uVar6 < 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar6 * 4);
}


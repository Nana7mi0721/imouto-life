
undefined4 FUN_006be1e0(undefined4 param_1,byte *param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar2 = FUN_006bf0c0(param_1,8);
  *param_2 = bVar2;
  bVar2 = FUN_006bf0c0(param_1,8);
  param_2[1] = bVar2;
  bVar2 = FUN_006bf0c0(param_1,8);
  param_2[2] = bVar2;
  if ((3 < *param_2) || ((*param_2 == 3 && (2 < param_2[1])))) {
    return 0xffffffea;
  }
  iVar3 = FUN_006bf0c0(param_1,0x10);
  *(int *)(param_2 + 4) = iVar3 << 4;
  iVar3 = FUN_006bf0c0(param_1,0x10);
  *(int *)(param_2 + 8) = iVar3 << 4;
  uVar4 = FUN_006bf0c0(param_1,0x18);
  *(undefined4 *)(param_2 + 0xc) = uVar4;
  uVar4 = FUN_006bf0c0(param_1,0x18);
  *(undefined4 *)(param_2 + 0x10) = uVar4;
  uVar4 = FUN_006bf0c0(param_1,8);
  *(undefined4 *)(param_2 + 0x14) = uVar4;
  uVar4 = FUN_006bf0c0(param_1,8);
  *(undefined4 *)(param_2 + 0x18) = uVar4;
  uVar4 = FUN_006bf0c0(param_1,0x20);
  *(undefined4 *)(param_2 + 0x1c) = uVar4;
  iVar3 = FUN_006bf0c0(param_1,0x20);
  *(int *)(param_2 + 0x20) = iVar3;
  if (((*(uint *)(param_2 + 4) != 0) && (uVar1 = *(uint *)(param_2 + 8), uVar1 != 0)) &&
     ((uint)(*(int *)(param_2 + 0xc) + *(int *)(param_2 + 0x14)) <= *(uint *)(param_2 + 4))) {
    if ((((uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)) <= uVar1) &&
        (*(int *)(param_2 + 0x1c) != 0)) && (iVar3 != 0)) {
      *(uint *)(param_2 + 0x18) = (uVar1 - *(int *)(param_2 + 0x10)) - *(int *)(param_2 + 0x18);
      uVar4 = FUN_006bf0c0(param_1,0x18);
      *(undefined4 *)(param_2 + 0x24) = uVar4;
      uVar4 = FUN_006bf0c0(param_1,0x18);
      *(undefined4 *)(param_2 + 0x28) = uVar4;
      uVar4 = FUN_006bf0c0(param_1,8);
      *(undefined4 *)(param_2 + 0x2c) = uVar4;
      uVar4 = FUN_006bf0c0(param_1,0x18);
      *(undefined4 *)(param_2 + 0x34) = uVar4;
      uVar4 = FUN_006bf0c0(param_1,6);
      *(undefined4 *)(param_2 + 0x38) = uVar4;
      uVar4 = FUN_006bf0c0(param_1,5);
      *(undefined4 *)(param_2 + 0x3c) = uVar4;
      iVar3 = FUN_006bf0c0(param_1,2);
      *(int *)(param_2 + 0x30) = iVar3;
      if (iVar3 != 1) {
        iVar3 = FUN_006bf0c0(param_1,3);
        if (iVar3 == 0) {
          iVar3 = FUN_006bf140(param_1);
          if (-1 < iVar3) {
            return 0;
          }
        }
      }
    }
  }
  return 0xffffffec;
}


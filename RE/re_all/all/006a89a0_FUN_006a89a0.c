
undefined4 FUN_006a89a0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  size_t _Size;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  uint local_2c;
  undefined4 *local_28;
  int local_24;
  
  iVar12 = 0;
  iVar1 = *param_2;
  local_28 = (undefined4 *)param_2[2];
  local_2c = param_2[3];
  iVar3 = FUN_006a8240(param_2);
  iVar4 = FUN_006a8250(param_2);
  local_24 = FUN_006a8260(param_2);
  iVar5 = FUN_006a8270(param_2);
  uVar14 = FUN_006a8280(param_2);
  iVar6 = FUN_006a8360(param_2);
  iVar7 = FUN_006a8390(param_2);
  uVar10 = (uint)*(byte *)(iVar1 + 0x1a);
  iVar8 = FUN_006a8470(param_1);
  if (iVar8 != 0) {
    return 0xffffffff;
  }
  iVar8 = param_1[3];
  iVar2 = param_1[9];
  if (iVar8 != 0) {
    _Size = param_1[2] - iVar8;
    param_1[2] = _Size;
    if (_Size != 0) {
      _memmove((void *)*param_1,(void *)(*param_1 + iVar8),_Size);
    }
    param_1[3] = 0;
  }
  if (iVar2 != 0) {
    if (param_1[7] != iVar2) {
      _memmove((void *)param_1[4],(void *)(param_1[4] + iVar2 * 4),
               (iVar2 * 0x3fffffff + param_1[7]) * 4);
      _memmove((void *)param_1[5],(void *)(param_1[5] + iVar2 * 8),
               (iVar2 * 0x1fffffff + param_1[7]) * 8);
    }
    param_1[7] = param_1[7] - iVar2;
    param_1[8] = param_1[8] - iVar2;
    param_1[9] = 0;
  }
  if (iVar6 != param_1[0x54]) {
    return 0xffffffff;
  }
  if (0 < iVar3) {
    return 0xffffffff;
  }
  iVar3 = FUN_006a8600(param_1,uVar10 + 1);
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (iVar7 != param_1[0x55]) {
    iVar3 = param_1[8];
    if (iVar3 < param_1[7]) {
      iVar6 = param_1[7] - iVar3;
      puVar9 = (uint *)(param_1[4] + iVar3 * 4);
      do {
        uVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        param_1[2] = param_1[2] - (uVar11 & 0xff);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    param_1[7] = iVar3;
    if (param_1[0x55] != -1) {
      *(undefined4 *)(param_1[4] + iVar3 * 4) = 0x400;
      param_1[7] = param_1[7] + 1;
      param_1[8] = param_1[8] + 1;
    }
  }
  if ((iVar4 != 0) &&
     (((param_1[7] < 1 || (*(int *)(param_1[4] + -4 + param_1[7] * 4) == 0x400)) &&
      (local_24 = 0, uVar10 != 0)))) {
    do {
      uVar11 = (uint)*(byte *)(iVar1 + 0x1b + iVar12);
      local_28 = (undefined4 *)((int)local_28 + uVar11);
      local_2c = local_2c - uVar11;
      if (uVar11 < 0xff) {
        iVar12 = iVar12 + 1;
        break;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < (int)uVar10);
  }
  if (local_2c != 0) {
    iVar3 = FUN_006a8590(param_1,local_2c);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    puVar13 = (undefined4 *)(*param_1 + param_1[2]);
    for (uVar11 = local_2c >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *puVar13 = *local_28;
      local_28 = local_28 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar11 = local_2c & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)local_28;
      local_28 = (undefined4 *)((int)local_28 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    param_1[2] = param_1[2] + local_2c;
  }
  iVar3 = -1;
  if (iVar12 < (int)uVar10) {
    do {
      uVar11 = (uint)*(byte *)(iVar1 + 0x1b + iVar12);
      *(uint *)(param_1[4] + param_1[7] * 4) = uVar11;
      iVar4 = param_1[7];
      iVar6 = param_1[5];
      *(undefined4 *)(iVar6 + iVar4 * 8) = 0xffffffff;
      *(undefined4 *)(iVar6 + 4 + iVar4 * 8) = 0xffffffff;
      if (local_24 != 0) {
        local_24 = 0;
        puVar9 = (uint *)(param_1[4] + param_1[7] * 4);
        *puVar9 = *puVar9 | 0x100;
      }
      if (uVar11 < 0xff) {
        iVar3 = param_1[7];
      }
      iVar4 = param_1[7];
      iVar12 = iVar12 + 1;
      param_1[7] = iVar4 + 1;
      if (uVar11 < 0xff) {
        param_1[8] = iVar4 + 1;
      }
    } while (iVar12 < (int)uVar10);
    if (iVar3 != -1) {
      iVar1 = param_1[5];
      *(int *)(iVar1 + iVar3 * 8) = (int)uVar14;
      *(int *)(iVar1 + 4 + iVar3 * 8) = (int)((ulonglong)uVar14 >> 0x20);
    }
  }
  if (iVar5 != 0) {
    iVar1 = param_1[7];
    param_1[0x52] = 1;
    if (0 < iVar1) {
      *(uint *)(param_1[4] + -4 + iVar1 * 4) = *(uint *)(param_1[4] + -4 + iVar1 * 4) | 0x200;
    }
  }
  param_1[0x55] = iVar7 + 1;
  return 0;
}



int FUN_006c46e0(uint *param_1,int *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  bool bVar11;
  uint local_120 [4];
  undefined4 local_110;
  uint local_10c;
  uint local_108;
  uint local_104;
  
  if (param_3 < 8) {
    return -0x84;
  }
  iVar4 = 2;
  bVar11 = true;
  piVar7 = param_2;
  piVar9 = (int *)s_OpusHead_00a0f39c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar11 = *piVar7 == *piVar9;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
  } while (bVar11);
  if (!bVar11) {
    return -0x84;
  }
  if (param_3 < 9) {
    return -0x85;
  }
  bVar1 = *(byte *)(param_2 + 2);
  local_120[0] = (uint)bVar1;
  if (0xf < bVar1) {
    return -0x86;
  }
  if (param_3 < 0x13) {
    return -0x85;
  }
  bVar2 = *(byte *)((int)param_2 + 9);
  uVar6 = (uint)bVar2;
  local_120[1] = uVar6;
  local_120[2] = FUN_006c4910((int)param_2 + 10);
  local_120[3] = FUN_006c4940(param_2 + 3);
  local_110 = FUN_006c4920(param_2 + 4);
  local_10c = (uint)*(byte *)((int)param_2 + 0x12);
  if (local_10c == 0) {
    if (bVar2 == 0) {
      return -0x85;
    }
    if (uVar6 != 2 && 1 < bVar2) {
      return -0x85;
    }
    if ((bVar1 < 2) && (0x13 < param_3)) {
      return -0x85;
    }
    local_108 = 1;
    local_104 = uVar6 - 1;
    if (param_1 == (uint *)0x0) {
      return 0;
    }
    *(undefined1 *)(param_1 + 8) = 0;
    *(undefined1 *)((int)param_1 + 0x21) = 1;
  }
  else {
    if (local_10c != 1) {
      return (-(uint)(local_10c != 0xff) & 0xfffffffd) - 0x82;
    }
    if (uVar6 == 0) {
      return -0x85;
    }
    if (uVar6 != 8 && 7 < bVar2) {
      return -0x85;
    }
    if (param_3 < uVar6 + 0x15) {
      return -0x85;
    }
    if ((bVar1 < 2) && (uVar6 + 0x15 < param_3)) {
      return -0x85;
    }
    local_108 = (uint)*(byte *)((int)param_2 + 0x13);
    if (*(byte *)((int)param_2 + 0x13) == 0) {
      return -0x85;
    }
    local_104 = (uint)*(byte *)(param_2 + 5);
    if (local_108 < local_104) {
      return -0x85;
    }
    if (uVar6 != 0) {
      pbVar3 = (byte *)((int)param_2 + 0x15);
      do {
        if ((local_104 + local_108 <= (uint)*pbVar3) && (*pbVar3 != 0xff)) {
          return -0x85;
        }
        pbVar3 = pbVar3 + 1;
      } while ((int)(pbVar3 + (-0x15 - (int)param_2)) < (int)uVar6);
    }
    if (param_1 == (uint *)0x0) {
      return 0;
    }
    puVar8 = (uint *)((int)param_2 + 0x15);
    puVar10 = param_1 + 8;
    for (uVar5 = (uint)(bVar2 >> 2); uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(char *)puVar10 = (char)*puVar8;
      puVar8 = (uint *)((int)puVar8 + 1);
      puVar10 = (uint *)((int)puVar10 + 1);
    }
  }
  puVar8 = local_120;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *puVar8;
    puVar8 = puVar8 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}


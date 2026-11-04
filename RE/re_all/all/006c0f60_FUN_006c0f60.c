
undefined4 FUN_006c0f60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  bool bVar11;
  uint local_8;
  int local_4;
  
  if (3 < *(int *)(param_1 + 0x5c)) {
    return 0;
  }
  if (*(int *)(param_1 + 0x5c) < 3) {
    return 0xffffff7f;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    local_4 = 0;
  }
  else {
    local_4 = *(int *)(param_1 + 0x60);
  }
  iVar4 = *(int *)(param_1 + 0x1c);
  local_4 = local_4 * 0x160;
  iVar1 = *(int *)(iVar4 + 0x44 + local_4);
  iVar2 = *(int *)(iVar4 + 0x48 + local_4);
  uVar6 = *(uint *)(iVar4 + 0x30 + local_4);
  iVar4 = iVar4 + 0x2c + local_4;
  iVar3 = *(int *)(param_1 + 0x21d8);
  local_8 = uVar6;
  if ((((iVar3 != 0) && (*(int *)(param_1 + 0x21e4) == iVar1)) &&
      (*(int *)(param_1 + 0x21e8) == iVar2)) && (*(uint *)(param_1 + 0x21ec) == uVar6)) {
    bVar11 = true;
    uVar5 = uVar6;
    pcVar8 = (char *)(param_1 + 0x21f0);
    pcVar9 = (char *)(iVar4 + 0x20);
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      bVar11 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (bVar11) {
      FUN_00797f60(iVar3,0xfbc);
      goto LAB_006c1073;
    }
  }
  FUN_006507e0(iVar3);
  puVar7 = (undefined4 *)(iVar4 + 0x20);
  iVar4 = FUN_00797ad0(48000,uVar6,iVar1,iVar2,puVar7,&local_8);
  *(int *)(param_1 + 0x21d8) = iVar4;
  if (iVar4 == 0) {
    return 0xffffff7f;
  }
  *(int *)(param_1 + 0x21e4) = iVar1;
  *(uint *)(param_1 + 0x21ec) = uVar6;
  *(int *)(param_1 + 0x21e8) = iVar2;
  puVar10 = (undefined4 *)(param_1 + 0x21f0);
  for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar10 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar10 = puVar10 + 1;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
LAB_006c1073:
  *(undefined4 *)(param_1 + 0x5c) = 4;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x2338) = 0;
  *(undefined4 *)(param_1 + 0x232c) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x28 + local_4);
  FUN_006c10c0(param_1);
  return 0;
}


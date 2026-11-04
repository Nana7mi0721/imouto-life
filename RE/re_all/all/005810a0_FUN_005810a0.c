
undefined4 FUN_005810a0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_8;
  int local_4;
  
  iVar2 = 0;
  local_8 = 0;
  piVar3 = &DAT_00d4a2e4;
  do {
    iVar6 = 0x1ff;
    iVar1 = local_8;
    piVar5 = piVar3;
    do {
      *piVar5 = iVar1 / 0xff;
      piVar5 = piVar5 + 1;
      iVar1 = iVar1 + iVar2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    local_8 = local_8 + -0xff;
    piVar3 = piVar3 + 0x200;
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0xdca2e4);
  iVar2 = 0;
  piVar3 = &DAT_00d0a2e0;
  do {
    iVar1 = 0;
    iVar6 = 0x100;
    do {
      *piVar3 = iVar1 / 0xff;
      piVar3 = piVar3 + 1;
      iVar1 = iVar1 + iVar2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0xd4a2e0);
  puVar7 = &DAT_00cca2e0;
  uVar4 = 0x3f;
  local_8 = 0;
  do {
    local_4 = 0x40;
    iVar2 = 0;
    do {
      iVar6 = 0;
      iVar1 = iVar2;
      do {
        puVar7[iVar6] = (char)(iVar1 / 0x3f);
        iVar6 = iVar6 + 1;
        iVar1 = iVar1 + uVar4;
      } while (iVar6 < 0x40);
      iVar2 = iVar2 + local_8;
      puVar7 = puVar7 + 0x40;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    local_8 = local_8 + 1;
    uVar4 = uVar4 - 1;
  } while (uVar4 < 0x80000000);
  return 0;
}


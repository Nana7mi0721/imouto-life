
undefined8 FUN_006c2570(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  bool bVar7;
  uint local_8;
  int local_4;
  
  iVar4 = *(int *)(param_1 + 0x18);
  if (((*(int *)(param_1 + 0x5c) < 2) || (*(int *)(param_1 + 0x14) == 0)) || (iVar4 <= param_2)) {
    return 0xffffffffffffff7d;
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if (-1 < param_2) {
    param_2 = param_2 * 0x160;
    iVar4 = param_2 + iVar1;
    FUN_006c0c50(&local_8,*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x1c),
                 *(undefined4 *)(param_2 + 0x20 + iVar1),*(undefined4 *)(param_2 + 0x24 + iVar1));
    return CONCAT44(local_4 - (uint)(local_8 < *(uint *)(iVar4 + 0x34)),
                    local_8 - *(uint *)(iVar4 + 0x34));
  }
  uVar6 = 0;
  iVar3 = 0;
  if (0 < iVar4) {
    puVar5 = (undefined4 *)(iVar1 + 0x18);
    do {
      FUN_006c0c50(&local_8,*puVar5,puVar5[1],puVar5[2],puVar5[3]);
      uVar2 = local_8 - puVar5[7];
      bVar7 = CARRY4(uVar6,uVar2);
      uVar6 = uVar6 + uVar2;
      iVar3 = iVar3 + (local_4 - (uint)(local_8 < (uint)puVar5[7])) + (uint)bVar7;
      puVar5 = puVar5 + 0x58;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return CONCAT44(iVar3,uVar6);
}


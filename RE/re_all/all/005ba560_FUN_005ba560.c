
undefined4 FUN_005ba560(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100 [8];
  undefined4 local_e0 [8];
  undefined4 local_c0 [8];
  undefined4 local_a0 [8];
  undefined4 local_80 [8];
  undefined4 local_60 [8];
  undefined4 local_40 [8];
  undefined4 local_20 [8];
  
  if ((DAT_00f132e4 == 0) && (DAT_00ef7324 == 0)) {
    return 0;
  }
  DAT_00f132e4 = 0;
  if (DAT_00f133f0 != 0) {
    if (DAT_00f133f4 != 0) {
      FUN_005d1fe0(DAT_00f133f0);
    }
    DAT_00f133f0 = 0;
  }
  DAT_00f133f4 = 0;
  if (DAT_00f132e0 == -1) {
    iVar2 = FUN_005d2940(&DAT_00f132e8,&local_10c);
    if (iVar2 != 0) {
      FUN_0056bca0(&PTR_PTR_007fd628);
      return 0xffffffff;
    }
    DAT_00f133f4 = 1;
  }
  else {
    puVar1 = &DAT_00f133f8 + DAT_00f132e0;
    if ((&DAT_00f133f8)[DAT_00f132e0] == 0) {
      local_108 = 0;
      local_104 = 0;
      puVar4 = (undefined4 *)(&DAT_0085fc24 + DAT_00f132e0 * 0x28);
      puVar3 = puVar4;
      puVar5 = local_100;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar4;
      puVar5 = local_e0;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar4;
      puVar5 = local_c0;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar4;
      puVar5 = local_a0;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar4;
      puVar5 = local_80;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar4;
      puVar5 = local_60;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = puVar4;
      puVar5 = local_40;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = local_20;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar2 = FUN_005d2940(&local_108,&local_10c);
      if (iVar2 != 0) {
        FUN_0056bca0(&PTR_PTR_007fd5e0);
        return 0xffffffff;
      }
      *puVar1 = local_10c;
    }
    local_10c = *puVar1;
  }
  DAT_00f133f0 = local_10c;
  FUN_005d2d30(local_10c,&DAT_00f328e8,0xffffffff);
  return 0;
}


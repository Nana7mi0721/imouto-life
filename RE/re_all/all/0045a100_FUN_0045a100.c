
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045a100(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int local_18;
  int local_14;
  int local_10;
  
  DAT_00a149d4 = 1;
  puVar1 = (uint *)FUN_004ce990(1);
  uVar4 = *puVar1 >> 0x1c;
  if (uVar4 == 0) {
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 1) != 0) {
      DAT_00a148bc = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 2) != 0) {
      DAT_00a148bd = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 4) != 0) {
      DAT_00a148be = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x10) != 0) {
      DAT_00a148c0 = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x20) != 0) {
      DAT_00a148c1 = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x40) != 0) {
      DAT_00a148c2 = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x80) != 0) {
      DAT_00a148bf = 1;
    }
  }
  else if (uVar4 == 1) {
    puVar3 = (undefined4 *)FUN_004ce990(2);
    iVar2 = FUN_00487080(*puVar3);
    if (iVar2 + -100 < 0x100) {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      local_10 = FUN_00487080(*puVar3);
      local_10 = local_10 + -100;
    }
    else {
      local_10 = 0xff;
    }
    if (local_10 < 0) {
      local_14 = 0;
    }
    else {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      iVar2 = FUN_00487080(*puVar3);
      if (iVar2 + -100 < 0x100) {
        puVar3 = (undefined4 *)FUN_004ce990(2);
        local_18 = FUN_00487080(*puVar3);
        local_18 = local_18 + -100;
      }
      else {
        local_18 = 0xff;
      }
      local_14 = local_18;
    }
    (&DAT_00a148c3)[local_14] = 1;
  }
  else if (uVar4 == 2) {
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 1) != 0) {
      DAT_00a149c3 = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 2) != 0) {
      DAT_00a149c5 = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 4) != 0) {
      DAT_00a149c4 = 1;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 8) != 0) {
      puVar3 = (undefined4 *)FUN_004ce990(2);
      _DAT_00a149c8 = FUN_00487080(*puVar3);
      puVar3 = (undefined4 *)FUN_004ce990(3);
      _DAT_00a149cc = FUN_00487080(*puVar3);
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x10) != 0) {
      DAT_00a149c6 = 1;
      puVar3 = (undefined4 *)FUN_004ce990(2);
      _DAT_00a149d0 = FUN_00487080(*puVar3);
    }
  }
  return;
}



uint FUN_0045d2f0(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined1 auStack_98 [20];
  undefined4 uStack_84;
  undefined1 *puStack_80;
  undefined1 auStack_7c [20];
  undefined4 uStack_68;
  undefined *puStack_64;
  undefined1 auStack_60 [16];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  char *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ade83;
  local_10 = ExceptionList;
  uStack_48 = 1;
  uStack_4c = 0x45d31e;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_004ce990();
  uStack_48 = *puVar1;
  uStack_4c = 0x45d329;
  local_14 = FUN_00487080();
  uStack_48 = 1;
  uStack_4c = 0x45d33c;
  puVar2 = (uint *)FUN_004ce990();
  if (*puVar2 < 0x80000000) {
    uStack_48 = local_14;
    uStack_4c = 0x45d477;
    iVar5 = FUN_0046f600();
    if (-1 < iVar5) {
      uStack_48 = 2;
      uStack_4c = 0x45d48b;
      puVar1 = (undefined4 *)FUN_004ce990();
      uStack_48 = *puVar1;
      uStack_4c = local_14;
      uStack_50 = 0x45d49c;
      uStack_4c = FUN_0046f600();
      uStack_50 = 0x45d4a7;
      FUN_004d2a00();
      uStack_4c = 0x45d4ae;
      FUN_004a58e0();
    }
    iVar5 = *(int *)(local_28 + 8);
    *(uint *)(local_28 + 8) = iVar5 + 1U;
    uVar3 = iVar5 + 1U & 0xffffff00;
  }
  else if (*(int *)(local_28 + 0x14) < 0) {
    if (-1 < *(int *)(local_28 + 0x18)) {
      local_18 = auStack_60;
      puStack_64 = &DAT_007cf41c;
      uStack_68 = 0x45d371;
      local_30 = basic_string<>();
      local_8 = 0;
      local_1c = auStack_7c;
      puStack_80 = auStack_7c;
      uStack_84 = 0x45d38f;
      local_2c = local_30;
      local_38 = FUN_00438b60();
      local_8 = CONCAT31(local_8._1_3_,1);
      local_24 = auStack_98;
      local_34 = local_38;
      local_3c = basic_string<>(&DAT_007cf420);
      local_40 = FUN_00401c50();
      local_20 = auStack_98;
      local_44 = basic_string<>(local_40);
      local_8 = 0xffffffff;
      local_28 = (char *)FUN_0042bed0();
    }
    uVar3 = (uint)local_28 & 0xffffff00;
  }
  else if (*(int *)(local_28 + 0x10) == DAT_00a17eb8) {
    local_14 = *(undefined4 *)(local_28 + 0x14);
    uStack_48 = 2;
    uStack_4c = 0x45d41f;
    puVar1 = (undefined4 *)FUN_004ce990();
    uStack_48 = *puVar1;
    uStack_4c = local_14;
    uStack_50 = 0x45d430;
    uStack_4c = FUN_0046f600();
    uStack_50 = 0x45d43b;
    FUN_004d2a00();
    uStack_4c = 0x45d442;
    FUN_004a58e0();
    uStack_48 = 0x45d44a;
    pcVar4 = (char *)FUN_00452450();
    if ((*local_28 != '\0') && (pcVar4 = local_28, *(int *)(local_28 + 4) == 0)) {
      uStack_48 = 0x45d465;
      pcVar4 = (char *)FUN_0044ed30();
    }
    uVar3 = (uint)pcVar4 & 0xffffff00;
  }
  else {
    uStack_48 = 0x45d3ff;
    uVar3 = FUN_00452450();
    uVar3 = uVar3 & 0xffffff00;
  }
  ExceptionList = local_10;
  return uVar3;
}


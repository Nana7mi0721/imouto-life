
void __fastcall FUN_004ca990(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int local_48;
  int local_40;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  local_10 = (int)*DAT_00a1671c / DAT_0084b264 + 2;
  local_8 = FUN_0047a4b0();
  local_8 = local_8 * ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74));
  iVar1 = FUN_0047a4b0();
  if (iVar1 <= (int)*DAT_00a1671c / DAT_0084b264) {
    local_8 = local_8 + (DAT_0084b264 / *(int *)(param_1 + 0x74)) * 2;
  }
  for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
    FUN_004cd4c0();
    FUN_004cd310(local_8 + 1);
    FUN_004ce950();
    FUN_004ce970(local_8 + 1);
  }
  *(int *)(param_1 + 0x38) = local_8;
  local_18 = 0;
  while (iVar1 = FUN_004d29a0(), local_18 < iVar1) {
    iVar1 = FUN_004d2a00(local_18);
    if ((*(char *)(iVar1 + 0x53) != '\0') &&
       (iVar1 = FUN_004d2a00(local_18), *(char *)(iVar1 + 0xaf) == '\0')) {
      uVar3 = 1;
      FUN_004d2a00(local_18);
      iVar1 = FUN_004bf870(uVar3);
      local_c = (iVar1 / *(int *)(param_1 + 0x70)) % local_8;
      if ((-2 < local_c) &&
         (iVar1 = FUN_004d2a00(local_18),
         local_c <=
         (*(int *)(iVar1 + 0xdc) / (int)*DAT_00a16674 + local_10) *
         ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74)))) {
        piVar2 = &local_18;
        FUN_004cde80(local_c + 1);
        FUN_004ce160(piVar2);
        piVar2 = (int *)FUN_004ce990(local_c + 1);
        *piVar2 = *piVar2 + 1;
      }
    }
    local_18 = local_18 + 1;
  }
  local_1c = 0;
  while (iVar1 = FUN_004d29a0(), local_1c < iVar1) {
    iVar1 = FUN_004d2a00(local_1c);
    if ((*(char *)(iVar1 + 0x53) == '\0') &&
       (iVar1 = FUN_004d2a00(local_1c), *(char *)(iVar1 + 0xaf) == '\0')) {
      uVar3 = 1;
      FUN_004d2a00(local_1c);
      iVar1 = FUN_004bf870(uVar3);
      local_c = (iVar1 / *(int *)(param_1 + 0x70)) % local_8;
      if ((-2 < local_c) &&
         (iVar1 = FUN_004d2a00(local_1c),
         local_c <=
         (*(int *)(iVar1 + 0xdc) / (int)*DAT_00a16674 + local_10) *
         ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74)))) {
        piVar2 = &local_1c;
        FUN_004cde80(local_c + 1);
        FUN_004ce160(piVar2);
        piVar2 = (int *)FUN_004ce990(local_c + 1);
        *piVar2 = *piVar2 + 1;
      }
    }
    local_1c = local_1c + 1;
  }
  local_20 = (uint)(DAT_00a1448b == '\0');
  local_24 = DAT_0084b21c;
  if (DAT_00a144e7 != '\0') {
    local_20 = 2;
  }
  while (local_24 = local_24 + -1, -1 < local_24) {
    uVar3 = 1;
    FUN_004d2620(local_24);
    iVar1 = FUN_004bf870(uVar3);
    if (iVar1 / *(int *)(param_1 + 0x70) < 1) {
      local_40 = 0;
    }
    else {
      uVar3 = 1;
      FUN_004d2620(local_24);
      local_40 = FUN_004bf870(uVar3);
      local_40 = local_40 / *(int *)(param_1 + 0x70);
    }
    local_c = local_40 % local_8;
    if ((-2 < local_c) &&
       (iVar1 = FUN_004d2620(local_24),
       local_c <=
       (*(int *)(iVar1 + 0xdc) / (int)*DAT_00a16674 + local_10) *
       ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74)))) {
      local_2c = -0xb - local_24;
      piVar2 = &local_2c;
      FUN_004cde80(local_c + 1);
      FUN_004ce160(piVar2);
      piVar2 = (int *)FUN_004ce990(local_c + 1);
      *piVar2 = *piVar2 + 1;
    }
  }
  iVar1 = FUN_004bf870(1);
  if (iVar1 / *(int *)(param_1 + 0x70) < 1) {
    local_48 = 0;
  }
  else {
    local_48 = FUN_004bf870(1);
    local_48 = local_48 / *(int *)(param_1 + 0x70);
  }
  local_c = local_48;
  if (-1 < local_48) {
    local_c = local_48 % local_8;
    local_30 = 0xfffffff6;
    puVar4 = &local_30;
    FUN_004cde80(local_c + 1);
    FUN_004ce160(puVar4);
    piVar2 = (int *)FUN_004ce990(local_c + 1);
    *piVar2 = *piVar2 + 1;
  }
  local_28 = 0;
  while (iVar1 = FUN_004d29a0(), local_28 < iVar1) {
    iVar1 = FUN_004d2a00(local_28);
    if (*(char *)(iVar1 + 0xaf) != '\0') {
      uVar3 = 1;
      FUN_004d2a00(local_28);
      iVar1 = FUN_004bf870(uVar3);
      local_c = (iVar1 / *(int *)(param_1 + 0x70)) % local_8;
      if ((-2 < local_c) &&
         (iVar1 = FUN_004d2a00(local_28),
         local_c <=
         (*(int *)(iVar1 + 0xdc) / (int)*DAT_00a16674 + local_10) *
         ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74)))) {
        piVar2 = &local_28;
        FUN_004cde80(local_c + 1);
        FUN_004ce160(piVar2);
        piVar2 = (int *)FUN_004ce990(local_c + 1);
        *piVar2 = *piVar2 + 1;
      }
    }
    local_28 = local_28 + 1;
  }
  return;
}


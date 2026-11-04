
uint __fastcall FUN_0044bc00(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_10;
  int local_8;
  
  local_10 = *(int *)(param_1 + 0x28) - DAT_00a14460;
  local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
  if (DAT_00a180f4 != '\0') {
    iVar1 = FUN_004febf1(local_10);
    iVar5 = *(int *)(param_1 + 0x28) - DAT_00a14460;
    iVar2 = FUN_0047a490();
    iVar2 = FUN_004febf1(iVar5 + iVar2 * -2);
    if (iVar2 < iVar1) {
      local_10 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar1 = FUN_0047a490();
      local_10 = local_10 + iVar1 * -2;
    }
    iVar1 = FUN_004febf1(local_10);
    iVar5 = *(int *)(param_1 + 0x28) - DAT_00a14460;
    iVar2 = FUN_0047a490();
    iVar2 = FUN_004febf1(iVar5 + iVar2 * 2);
    if (iVar2 < iVar1) {
      local_10 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar1 = FUN_0047a490();
      local_10 = local_10 + iVar1 * 2;
    }
  }
  if (DAT_00a180f5 != '\0') {
    iVar1 = FUN_004febf1(local_8);
    iVar5 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
    iVar2 = FUN_0047a4b0();
    iVar2 = FUN_004febf1(iVar5 + iVar2 * -2);
    if (iVar2 < iVar1) {
      local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar1 = FUN_0047a4b0();
      local_8 = local_8 + iVar1 * -2;
    }
    iVar1 = FUN_004febf1(local_8);
    iVar5 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
    iVar2 = FUN_0047a4b0();
    iVar2 = FUN_004febf1(iVar5 + iVar2 * 2);
    if (iVar2 < iVar1) {
      local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar1 = FUN_0047a4b0();
      local_8 = local_8 + iVar1 * 2;
    }
  }
  if (local_10 < 1) {
    local_20 = -local_10;
  }
  else {
    local_20 = local_10;
  }
  if (local_8 < 1) {
    local_24 = -local_8;
  }
  else {
    local_24 = local_8;
  }
  if (local_20 + local_24 < 0x14) {
    uVar4 = FUN_004174a0(0,0);
    uVar3 = uVar4 / 6;
    uVar4 = uVar4 % 6;
    if (uVar4 < 4) {
      uVar3 = FUN_0044e420();
    }
    else if (uVar4 == 4) {
      uVar3 = FUN_0044e2e0();
    }
    else if (uVar4 == 5) {
      uVar3 = FUN_00486b30();
    }
  }
  else {
    uVar3 = FUN_0044e2e0();
  }
  return uVar3;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00485530(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double local_24;
  int local_18;
  double local_14;
  int local_8;
  
  local_18 = *(int *)(param_1 + 0x28) - DAT_00a14460;
  local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
  if (DAT_00a180f4 != '\0') {
    iVar2 = FUN_004febf1(*(int *)(param_1 + 0x28) - DAT_00a14460);
    iVar5 = *(int *)(param_1 + 0x28) - DAT_00a14460;
    iVar3 = FUN_0047a490();
    iVar3 = FUN_004febf1(iVar5 + iVar3 * -2);
    if (iVar3 < iVar2) {
      local_18 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar2 = FUN_0047a490();
      local_18 = local_18 + iVar2 * -2;
    }
    iVar2 = FUN_004febf1(*(int *)(param_1 + 0x28) - DAT_00a14460);
    iVar5 = *(int *)(param_1 + 0x28) - DAT_00a14460;
    iVar3 = FUN_0047a490();
    iVar3 = FUN_004febf1(iVar5 + iVar3 * 2);
    if (iVar3 < iVar2) {
      local_18 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar2 = FUN_0047a490();
      local_18 = local_18 + iVar2 * 2;
    }
  }
  if (DAT_00a180f5 != '\0') {
    iVar2 = FUN_004febf1(*(int *)(param_1 + 0x2c) - DAT_00a14464);
    iVar5 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
    iVar3 = FUN_0047a4b0();
    iVar3 = FUN_004febf1(iVar5 + iVar3 * -2);
    if (iVar3 < iVar2) {
      local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar2 = FUN_0047a4b0();
      local_8 = local_8 + iVar2 * -2;
    }
    iVar2 = FUN_004febf1(*(int *)(param_1 + 0x2c) - DAT_00a14464);
    iVar5 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
    iVar3 = FUN_0047a4b0();
    iVar3 = FUN_004febf1(iVar5 + iVar3 * 2);
    if (iVar3 < iVar2) {
      local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar2 = FUN_0047a4b0();
      local_8 = local_8 + iVar2 * 2;
    }
  }
  if ((local_18 != 0) || (local_8 != 0)) {
    iVar2 = FUN_004febf1(local_18);
    local_24 = (double)iVar2;
    iVar2 = FUN_004febf1(local_8);
    local_14 = (double)iVar2;
    if ((*DAT_00a1667c == '\b') && (0xdb < *DAT_00a16714)) {
      *(undefined1 *)(param_1 + 0xbb) = 1;
      if ((local_24 == _DAT_007d0a60) || (local_14 == _DAT_007d0a60)) {
        if ((local_24 == _DAT_007d0a60) || (local_14 != _DAT_007d0a60)) {
          if ((local_24 == _DAT_007d0a60) && (local_14 != _DAT_007d0a60)) {
            if (local_8 < 1) {
              FUN_00478b90(1);
            }
            else {
              FUN_00443aa0(1);
            }
          }
        }
        else if (local_18 < 1) {
          FUN_00478a70(1);
        }
        else {
          FUN_00478b00(1);
        }
      }
      else {
        iVar2 = FUN_004febf1(local_18);
        iVar3 = FUN_004febf1(local_8);
        if (iVar3 <= iVar2 * 3) {
          iVar2 = FUN_004febf1(local_18);
          iVar3 = FUN_004febf1(local_8);
          if (iVar2 <= iVar3 * 3) {
            if (local_18 < 1) {
              if (local_8 < 1) {
                FUN_004791a0(1);
                return;
              }
              FUN_00478c20(1);
              return;
            }
            if (local_8 < 1) {
              FUN_00479460(1);
              return;
            }
            FUN_00478ee0(1);
            return;
          }
        }
        if (local_24 <= local_14) {
          if (local_8 < 1) {
            FUN_00478b90(1);
          }
          else {
            FUN_00443aa0(1);
          }
        }
        else if (local_18 < 1) {
          FUN_00478a70(1);
        }
        else {
          FUN_00478b00(1);
        }
      }
    }
    else {
      if (local_24 == local_14) {
        uVar4 = FUN_004174a0(0,0);
        if (uVar4 % 2 == 0) {
          local_24 = local_24 + _DAT_00802e18;
        }
        else {
          local_14 = local_14 + _DAT_00802e18;
        }
      }
      if (local_24 <= local_14) {
        if (local_8 < 1) {
          FUN_00478b90(1);
        }
        else {
          FUN_00443aa0(1);
        }
        cVar1 = FUN_004780e0();
        if ((cVar1 == '\0') && (local_18 != 0)) {
          if (local_18 < 1) {
            FUN_00478a70(1);
          }
          else {
            FUN_00478b00(1);
          }
        }
      }
      else {
        if (local_18 < 1) {
          FUN_00478a70(1);
        }
        else {
          FUN_00478b00(1);
        }
        cVar1 = FUN_004780e0();
        if ((cVar1 == '\0') && (local_8 != 0)) {
          if (local_8 < 1) {
            FUN_00478b90(1);
          }
          else {
            FUN_00443aa0(1);
          }
        }
      }
    }
  }
  return;
}


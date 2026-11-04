
void __fastcall FUN_00486670(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = *(int *)(param_1 + 0x28) - DAT_00a14460;
  local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
  if ((local_10 != 0) || (local_8 != 0)) {
    if (DAT_00a180f4 != '\0') {
      iVar2 = FUN_004febf1(local_10);
      iVar5 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar3 = FUN_0047a490();
      iVar3 = FUN_004febf1(iVar5 + iVar3 * -2);
      if (iVar3 < iVar2) {
        local_10 = *(int *)(param_1 + 0x28) - DAT_00a14460;
        iVar2 = FUN_0047a490();
        local_10 = local_10 + iVar2 * -2;
      }
      iVar2 = FUN_004febf1(local_10);
      iVar5 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar3 = FUN_0047a490();
      iVar3 = FUN_004febf1(iVar5 + iVar3 * 2);
      if (iVar3 < iVar2) {
        local_10 = *(int *)(param_1 + 0x28) - DAT_00a14460;
        iVar2 = FUN_0047a490();
        local_10 = local_10 + iVar2 * 2;
      }
    }
    if (DAT_00a180f5 != '\0') {
      iVar2 = FUN_004febf1(local_8);
      iVar5 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar3 = FUN_0047a4b0();
      iVar3 = FUN_004febf1(iVar5 + iVar3 * -2);
      if (iVar3 < iVar2) {
        local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
        iVar2 = FUN_0047a4b0();
        local_8 = local_8 + iVar2 * -2;
      }
      iVar2 = FUN_004febf1(local_8);
      iVar5 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar3 = FUN_0047a4b0();
      iVar3 = FUN_004febf1(iVar5 + iVar3 * 2);
      if (iVar3 < iVar2) {
        local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
        iVar2 = FUN_0047a4b0();
        local_8 = local_8 + iVar2 * 2;
      }
    }
    local_14 = FUN_004febf1(local_10);
    local_c = FUN_004febf1(local_8);
    if (*DAT_00a1667c == '\b') {
      *(undefined1 *)(param_1 + 0xbb) = 1;
      if ((local_14 == 0) || (local_c == 0)) {
        if ((local_14 == 0) || (local_c != 0)) {
          if ((local_14 == 0) && (local_c != 0)) {
            if (local_8 < 1) {
              FUN_00443aa0(1);
            }
            else {
              FUN_00478b90(1);
            }
          }
        }
        else if (local_10 < 1) {
          FUN_00478b00(1);
        }
        else {
          FUN_00478a70(1);
        }
      }
      else if (local_10 < 1) {
        if (local_8 < 1) {
          FUN_00478ee0(1);
        }
        else {
          FUN_00479460(1);
        }
      }
      else if (local_8 < 1) {
        FUN_00478c20(1);
      }
      else {
        FUN_004791a0(1);
      }
    }
    else if (*DAT_00a1667c == '\x04') {
      if (local_14 == local_c) {
        uVar4 = FUN_004174a0(0,0);
        if (uVar4 % 2 == 0) {
          local_14 = local_14 + 1;
        }
        else {
          local_c = local_c + 1;
        }
      }
      if (local_c < local_14) {
        if (local_10 < 1) {
          FUN_00478b00(1);
        }
        else {
          FUN_00478a70(1);
        }
        cVar1 = FUN_004780e0();
        if ((cVar1 == '\0') && (local_8 != 0)) {
          if (local_8 < 1) {
            FUN_00443aa0(1);
          }
          else {
            FUN_00478b90(1);
          }
        }
      }
      else {
        if (local_8 < 1) {
          FUN_00443aa0(1);
        }
        else {
          FUN_00478b90(1);
        }
        cVar1 = FUN_004780e0();
        if ((cVar1 == '\0') && (local_10 != 0)) {
          if (local_10 < 1) {
            FUN_00478b00(1);
          }
          else {
            FUN_00478a70(1);
          }
        }
      }
    }
  }
  return;
}


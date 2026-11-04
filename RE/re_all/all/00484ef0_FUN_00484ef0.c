
void __thiscall FUN_00484ef0(int param_1,char param_2,int param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_2 == '\0') {
    local_10 = *(int *)(param_1 + 0x28) + param_3 * -2;
    local_8 = *(int *)(param_1 + 0x2c) + param_4 * -2;
    if (DAT_00a180f4 != '\0') {
      iVar4 = FUN_004febf1(local_10);
      iVar3 = *(int *)(param_1 + 0x28);
      iVar5 = FUN_0047a490();
      iVar3 = FUN_004febf1(iVar3 + param_3 * -2 + iVar5 * -2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x28);
        iVar4 = FUN_0047a490();
        local_10 = iVar3 + param_3 * -2 + iVar4 * -2;
      }
      iVar4 = FUN_004febf1(local_10);
      iVar3 = *(int *)(param_1 + 0x28);
      iVar5 = FUN_0047a490();
      iVar3 = FUN_004febf1(iVar3 + param_3 * -2 + iVar5 * 2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x28);
        iVar4 = FUN_0047a490();
        local_10 = iVar3 + param_3 * -2 + iVar4 * 2;
      }
    }
    if (DAT_00a180f5 != '\0') {
      iVar4 = FUN_004febf1(local_8);
      iVar3 = *(int *)(param_1 + 0x2c);
      iVar5 = FUN_0047a4b0();
      iVar3 = FUN_004febf1(iVar3 + param_4 * -2 + iVar5 * -2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x2c);
        iVar4 = FUN_0047a4b0();
        local_8 = iVar3 + param_4 * -2 + iVar4 * -2;
      }
      iVar4 = FUN_004febf1(local_8);
      iVar3 = *(int *)(param_1 + 0x2c);
      iVar5 = FUN_0047a4b0();
      iVar3 = FUN_004febf1(iVar3 + param_4 * -2 + iVar5 * 2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x2c);
        iVar4 = FUN_0047a4b0();
        local_8 = iVar3 + param_4 * -2 + iVar4 * 2;
      }
    }
  }
  else {
    cVar1 = FUN_004d29e0();
    if (cVar1 != '\0') {
      return;
    }
    if (param_3 < 0) {
      if ((param_3 < -2) && (iVar3 = FUN_004d25e0(), -3 - iVar3 < param_3)) {
        iVar3 = FUN_004d2620(-3 - param_3);
        local_1c = *(int *)(iVar3 + 0x28);
        iVar3 = FUN_004d2620(-3 - param_3);
        local_14 = *(int *)(iVar3 + 0x2c);
      }
      if (param_3 == -2) {
        local_1c = DAT_00a14460;
        local_14 = DAT_00a14464;
      }
      if (param_3 == -1) {
        return;
      }
    }
    else {
      uVar2 = FUN_0046f600(param_3);
      iVar3 = FUN_004d2a00(uVar2);
      local_1c = *(int *)(iVar3 + 0x28);
      uVar2 = FUN_0046f600(param_3);
      iVar3 = FUN_004d2a00(uVar2);
      local_14 = *(int *)(iVar3 + 0x2c);
    }
    local_10 = *(int *)(param_1 + 0x28) - local_1c;
    local_8 = *(int *)(param_1 + 0x2c) - local_14;
    if (DAT_00a180f4 != '\0') {
      iVar4 = FUN_004febf1(local_10);
      iVar3 = *(int *)(param_1 + 0x28);
      iVar5 = FUN_0047a490();
      iVar3 = FUN_004febf1((iVar3 - local_1c) + iVar5 * -2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x28);
        iVar4 = FUN_0047a490();
        local_10 = (iVar3 - local_1c) + iVar4 * -2;
      }
      iVar4 = FUN_004febf1(local_10);
      iVar3 = *(int *)(param_1 + 0x28);
      iVar5 = FUN_0047a490();
      iVar3 = FUN_004febf1((iVar3 - local_1c) + iVar5 * 2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x28);
        iVar4 = FUN_0047a490();
        local_10 = (iVar3 - local_1c) + iVar4 * 2;
      }
    }
    if (DAT_00a180f5 != '\0') {
      iVar4 = FUN_004febf1(local_8);
      iVar3 = *(int *)(param_1 + 0x2c);
      iVar5 = FUN_0047a4b0();
      iVar3 = FUN_004febf1((iVar3 - local_14) + iVar5 * -2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x2c);
        iVar4 = FUN_0047a4b0();
        local_8 = (iVar3 - local_14) + iVar4 * -2;
      }
      iVar4 = FUN_004febf1(local_8);
      iVar3 = *(int *)(param_1 + 0x2c);
      iVar5 = FUN_0047a4b0();
      iVar3 = FUN_004febf1((iVar3 - local_14) + iVar5 * 2);
      if (iVar3 < iVar4) {
        iVar3 = *(int *)(param_1 + 0x2c);
        iVar4 = FUN_0047a4b0();
        local_8 = (iVar3 - local_14) + iVar4 * 2;
      }
    }
  }
  if ((local_10 != 0) || (local_8 != 0)) {
    local_18 = FUN_004febf1(local_10);
    local_c = FUN_004febf1(local_8);
    if (*DAT_00a1667c == '\b') {
      *(undefined1 *)(param_1 + 0xbb) = 1;
      if ((local_18 == 0) || (local_c == 0)) {
        if ((local_18 == 0) || (local_c != 0)) {
          if ((local_18 == 0) && (local_c != 0)) {
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
      if (local_18 == local_c) {
        uVar6 = FUN_004174a0(0,0);
        if (uVar6 % 2 == 0) {
          local_18 = local_18 + 1;
        }
        else {
          local_c = local_c + 1;
        }
      }
      if (local_c < local_18) {
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


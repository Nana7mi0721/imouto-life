
void __fastcall FUN_00443e40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  local_c = *(int *)(param_1 + 0x28) - DAT_00a14460;
  local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
  if ((local_c != 0) || (local_8 != 0)) {
    if (DAT_00a180f4 != '\0') {
      iVar1 = FUN_004febf1(*(int *)(param_1 + 0x28) - DAT_00a14460);
      iVar3 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar2 = FUN_0047a490();
      iVar2 = FUN_004febf1(iVar3 + iVar2 * -2);
      if (iVar2 < iVar1) {
        local_c = *(int *)(param_1 + 0x28) - DAT_00a14460;
        iVar1 = FUN_0047a490();
        local_c = local_c + iVar1 * -2;
      }
      iVar1 = FUN_004febf1(*(int *)(param_1 + 0x28) - DAT_00a14460);
      iVar3 = *(int *)(param_1 + 0x28) - DAT_00a14460;
      iVar2 = FUN_0047a490();
      iVar2 = FUN_004febf1(iVar3 + iVar2 * 2);
      if (iVar2 < iVar1) {
        local_c = *(int *)(param_1 + 0x28) - DAT_00a14460;
        iVar1 = FUN_0047a490();
        local_c = local_c + iVar1 * 2;
      }
    }
    if (DAT_00a180f5 != '\0') {
      iVar1 = FUN_004febf1(*(int *)(param_1 + 0x2c) - DAT_00a14464);
      iVar3 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar2 = FUN_0047a4b0();
      iVar2 = FUN_004febf1(iVar3 + iVar2 * -2);
      if (iVar2 < iVar1) {
        local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
        iVar1 = FUN_0047a4b0();
        local_8 = local_8 + iVar1 * -2;
      }
      iVar1 = FUN_004febf1(*(int *)(param_1 + 0x2c) - DAT_00a14464);
      iVar3 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
      iVar2 = FUN_0047a4b0();
      iVar2 = FUN_004febf1(iVar3 + iVar2 * 2);
      if (iVar2 < iVar1) {
        local_8 = *(int *)(param_1 + 0x2c) - DAT_00a14464;
        iVar1 = FUN_0047a4b0();
        local_8 = local_8 + iVar1 * 2;
      }
    }
    if ((*DAT_00a1667c == '\b') && (0xdb < *DAT_00a16714)) {
      if ((local_c != 0) || (local_8 != 0)) {
        iVar1 = FUN_004febf1(local_c);
        if ((0 < iVar1) && (iVar1 = FUN_004febf1(local_8), 0 < iVar1)) {
          iVar1 = FUN_004febf1(local_c);
          iVar2 = FUN_004febf1(local_8);
          if (iVar2 <= iVar1 * 3) {
            iVar1 = FUN_004febf1(local_c);
            iVar2 = FUN_004febf1(local_8);
            if (iVar1 <= iVar2 * 3) {
              if (local_c < 1) {
                if (local_8 < 1) {
                  FUN_004785d0();
                  return;
                }
                FUN_00478520();
                return;
              }
              if (local_8 < 1) {
                FUN_00478680();
                return;
              }
              FUN_00478730();
              return;
            }
          }
        }
        iVar1 = FUN_004febf1(local_c);
        iVar2 = FUN_004febf1(local_8);
        if (iVar2 < iVar1) {
          if (local_c < 1) {
            FUN_004785a0();
          }
          else {
            FUN_00478650();
          }
        }
        else if (local_8 < 1) {
          FUN_00478700();
        }
        else {
          FUN_004784f0();
        }
      }
    }
    else {
      iVar1 = FUN_004febf1(local_c);
      iVar2 = FUN_004febf1(local_8);
      if (iVar2 < iVar1) {
        if (local_c < 1) {
          FUN_004785a0();
        }
        else {
          FUN_00478650();
        }
      }
      else if (local_8 < 1) {
        FUN_00478700();
      }
      else {
        FUN_004784f0();
      }
    }
  }
  return;
}


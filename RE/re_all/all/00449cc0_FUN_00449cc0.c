
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00449cc0(int param_1)

{
  int iVar1;
  undefined1 auStack_58 [28];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;
  
  local_8 = 0;
  uStack_28 = 0;
  uStack_2c = 1;
  iStack_30 = *(undefined4 *)(param_1 + 0x1658);
  uStack_34 = 0;
  uStack_38 = 0x449cea;
  local_14 = param_1;
  local_8 = FUN_0046f7f0();
  if (local_8 == -3) {
    uStack_28 = 0;
    uStack_2c = 0x449cff;
    iVar1 = FUN_00477980();
    if (iVar1 < 6) goto LAB_00449d71;
    uStack_28 = 0;
    uStack_2c = 100;
    iStack_30 = 100;
    uStack_34 = 0;
    uStack_38 = 5;
    uStack_3c = 0;
    local_c = auStack_58;
    local_18 = FUN_0046ff30(auStack_58,0,*(undefined4 *)(local_14 + 0x1658),5,0);
    iStack_30 = FUN_0047cf40();
    local_1c = iStack_30;
    local_8 = iStack_30;
    if (iStack_30 != -10) {
      uStack_28 = 0;
      uStack_2c = 5;
      uStack_34 = 0;
      uStack_38 = 0x449d63;
      FUN_0047a5d0();
    }
    DAT_00a14344 = DAT_00a14358;
  }
  else {
LAB_00449d71:
    if (-2 < local_8) {
      uStack_28 = 0;
      uStack_2c = 5;
      iStack_30 = local_8;
      uStack_34 = 0;
      uStack_38 = 0x449d8b;
      FUN_0047a5d0();
    }
  }
  _DAT_00a18d3c = 1;
  DAT_00a18d34 = 0;
  _DAT_00a18d5c = DAT_00a18d48;
  DAT_00a18d48 = (DAT_00a18b88 * DAT_00a14344) / 100;
  DAT_00a18bcc = DAT_00a14344;
  uStack_28 = 0;
  uStack_2c = 2;
  iStack_30 = *(undefined4 *)(local_14 + 0x1658);
  uStack_34 = 0;
  uStack_38 = 0x449de8;
  local_8 = FUN_0046f7f0();
  if (local_8 == -3) {
    uStack_28 = 0;
    uStack_2c = 0x449e01;
    iVar1 = FUN_00477980();
    if (6 < iVar1) {
      uStack_28 = 0;
      uStack_2c = 100;
      iStack_30 = 100;
      uStack_34 = 0;
      uStack_38 = 5;
      uStack_3c = 1;
      local_10 = auStack_58;
      local_20 = FUN_0046ff30(auStack_58,0,*(undefined4 *)(local_14 + 0x1658),6,0);
      iStack_30 = FUN_0047cf40();
      if ((DAT_00a18a38 != -3) || (iStack_30 != -10)) {
        uStack_28 = 0;
        uStack_2c = 5;
        uStack_34 = 1;
        uStack_38 = 0x449e6e;
        local_24 = iStack_30;
        local_8 = iStack_30;
        FUN_0047a5d0();
      }
      DAT_00a14348 = DAT_00a14358;
      goto LAB_00449e96;
    }
  }
  if (-2 < local_8) {
    uStack_28 = 0;
    uStack_2c = 5;
    iStack_30 = local_8;
    uStack_34 = 1;
    uStack_38 = 0x449e96;
    FUN_0047a5d0();
  }
LAB_00449e96:
  _DAT_00a18d40 = 1;
  DAT_00a18d38 = 0;
  _DAT_00a18d64 = DAT_00a18d50;
  DAT_00a18d50 = (DAT_00a18b8c * DAT_00a14348) / 100;
  DAT_00a18bd8 = DAT_00a14348;
  return;
}


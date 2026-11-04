
undefined4 __fastcall FUN_00466c10(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_10;
  int local_8;
  
  puVar1 = (uint *)FUN_004ce990(1);
  if ((*puVar1 & 0xf) == 0) {
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x200) == 0) {
      local_1c = 1;
    }
    else {
      local_1c = DAT_0084b264;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0x200) == 0) {
      local_20 = 1;
    }
    else {
      local_20 = DAT_0084b264;
    }
    puVar1 = (uint *)FUN_004ce990(1);
    iVar2 = (int)(*puVar1 & 0xf0) >> 4;
    puVar3 = (undefined4 *)FUN_004ce990(3);
    iVar4 = FUN_00487080(*puVar3);
    iVar4 = (iVar4 * DAT_0084b264 * 2) / local_1c << 1;
    puVar3 = (undefined4 *)FUN_004ce990(2);
    iVar5 = FUN_00487080(*puVar3);
    FUN_0044ad40((iVar5 * DAT_0084b264 * 2) / local_20 << 1,iVar4,iVar2);
    puVar1 = (uint *)FUN_004ce990(1);
    *(char *)(param_1 + 0x8a4) = '\x01' - ((*puVar1 & 0x100) != 0x100);
  }
  else {
    puVar1 = (uint *)FUN_004ce990(1);
    if ((*puVar1 & 0xf) == 1) {
      iVar2 = FUN_0047a490();
      local_30 = iVar2 * DAT_0084b264 * 2 * 2 + DAT_0084b264 * -0x50;
      iVar2 = FUN_0047a4b0();
      local_40 = iVar2 * DAT_0084b264 * 2 * 2 + DAT_0084b264 * -0x3c;
      if (DAT_00a180f4 == '\0') {
        if (DAT_0084b264 * 2 * DAT_00a14460 + (*DAT_00a16718 - DAT_0084b264) * -2 < local_30) {
          local_28 = DAT_0084b264 * 2 * DAT_00a14460 + (*DAT_00a16718 - DAT_0084b264) * -2;
        }
        else {
          local_28 = local_30;
        }
        if (local_28 < 0) {
          local_2c = 0;
        }
        else {
          if (DAT_0084b264 * 2 * DAT_00a14460 + (*DAT_00a16718 - DAT_0084b264) * -2 < local_30) {
            local_30 = DAT_0084b264 * 2 * DAT_00a14460 + (*DAT_00a16718 - DAT_0084b264) * -2;
          }
          local_2c = local_30;
        }
        local_10 = local_2c;
      }
      else {
        local_10 = DAT_0084b264 * 2 * DAT_00a14460 + (*DAT_00a16718 - DAT_0084b264) * -2;
      }
      if (DAT_00a180f5 == '\0') {
        if (DAT_0084b264 * 2 * DAT_00a14464 + (*DAT_00a1671c - DAT_0084b264) * -2 < local_40) {
          local_38 = DAT_0084b264 * 2 * DAT_00a14464 + (*DAT_00a1671c - DAT_0084b264) * -2;
        }
        else {
          local_38 = local_40;
        }
        if (local_38 < 0) {
          local_3c = 0;
        }
        else {
          if (DAT_0084b264 * 2 * DAT_00a14464 + (*DAT_00a1671c - DAT_0084b264) * -2 < local_40) {
            local_40 = DAT_0084b264 * 2 * DAT_00a14464 + (*DAT_00a1671c - DAT_0084b264) * -2;
          }
          local_3c = local_40;
        }
        local_8 = local_3c;
      }
      else {
        local_8 = DAT_0084b264 * 2 * DAT_00a14464 + (*DAT_00a1671c - DAT_0084b264) * -2;
      }
      puVar1 = (uint *)FUN_004ce990(1);
      FUN_0044ad40(local_10 - DAT_00a17ebc,local_8 - DAT_00a17ec0,(int)(*puVar1 & 0xf0) >> 4);
      puVar1 = (uint *)FUN_004ce990(1);
      *(char *)(param_1 + 0x8a4) = '\x01' - ((*puVar1 & 0x100) != 0x100);
    }
    else {
      puVar1 = (uint *)FUN_004ce990(1);
      if ((*puVar1 & 0xf) == 2) {
        DAT_00a18ae8 = 1;
      }
      else {
        puVar1 = (uint *)FUN_004ce990(1);
        if ((*puVar1 & 0xf) == 3) {
          DAT_00a18ae8 = 0;
        }
      }
    }
  }
  return 1;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043e5f0(int *param_1,undefined4 param_2,uint param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  uint local_78;
  uint local_74;
  uint local_6c;
  uint local_68;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar3 = *param_1;
  switch(param_2) {
  case 0:
    *(uint *)(iVar3 + 0x8cc) = param_3;
    break;
  case 1:
    if (param_3 == 0xffffffff) {
      local_1c = DAT_0084b264 / 2;
    }
    else {
      local_1c = param_3;
    }
    *(uint *)(iVar3 + 0x8d0) = local_1c;
    break;
  case 2:
    if (param_3 == 0xffffffff) {
      local_20 = FUN_004fe844();
    }
    else {
      local_20 = param_3;
    }
    *(uint *)(iVar3 + 0x8d4) = local_20;
    break;
  case 3:
    if (param_3 == 0xffffffff) {
      local_24 = DAT_0084b264 * 10;
    }
    else {
      local_24 = param_3;
    }
    *(uint *)(iVar3 + 0x8d8) = local_24;
    break;
  case 4:
    if (param_3 == 0xffffffff) {
      local_28 = (uint)(0xaa / (longlong)DAT_0084b248);
    }
    else {
      local_28 = param_3;
    }
    *(uint *)(iVar3 + 0x8dc) = local_28;
    break;
  case 5:
    *(undefined2 *)(iVar3 + 0x94e) = (undefined2)param_3;
    break;
  case 6:
    *(undefined2 *)(iVar3 + 0x950) = (undefined2)param_3;
    break;
  case 7:
    *(uint *)(iVar3 + 0x8ec) = param_3;
    break;
  case 8:
    *(uint *)(iVar3 + 0x918) = param_3;
    break;
  case 9:
    *(uint *)(iVar3 + 0x960) = param_3;
    break;
  case 10:
    *(uint *)(iVar3 + 0x968) = param_3;
    break;
  case 0xb:
    *(uint *)(iVar3 + 0x964) = param_3;
    break;
  case 0xe:
    *(undefined1 *)(iVar3 + 0x96c) = (undefined1)param_3;
    break;
  case 0xf:
    if ((int)param_3 < 1) {
      local_2c = 1;
    }
    else {
      local_2c = param_3;
    }
    *(uint *)(iVar3 + 0x940) = local_2c;
    break;
  case 0x10:
    if ((int)param_3 < 1) {
      local_30 = 1;
    }
    else {
      local_30 = param_3;
    }
    *(uint *)(iVar3 + 0x944) = local_30;
    break;
  case 0x11:
    *(uint *)(iVar3 + 0x8e0) = param_3;
    break;
  case 0x12:
    *(uint *)(iVar3 + 0x8e4) = param_3;
    break;
  case 0x13:
    *(uint *)(iVar3 + 0x8e8) = param_3;
    break;
  case 0x14:
    break;
  case 0x15:
    DAT_00a18aec = param_3;
    break;
  case 0x16:
    if ((int)param_3 < 4) {
      local_34 = param_3;
    }
    else {
      local_34 = 3;
    }
    if ((int)local_34 < 0) {
      local_38 = 0;
    }
    else {
      if ((int)param_3 < 4) {
        local_3c = param_3;
      }
      else {
        local_3c = 3;
      }
      local_38 = local_3c;
    }
    DAT_00a18b20 = local_38;
    break;
  case 0x17:
    DAT_00a18c80 = ((int)param_3 < 0) - 1 & param_3;
    break;
  case 0x19:
    *(uint *)(iVar3 + 0x948) = param_3;
    break;
  case 0x1c:
    *(uint *)(iVar3 + 0x9d4) = param_3;
    break;
  case 0x1d:
    *(uint *)(iVar3 + 0x8b0) = param_3;
    break;
  case 0x1e:
    *(uint *)(iVar3 + 0x8b8) = param_3;
    break;
  case 0x21:
    *(uint *)(iVar3 + 0x914) = param_3;
    FUN_0042f720(*(undefined4 *)(iVar3 + 0x914));
    break;
  case 0x24:
    *(undefined2 *)(iVar3 + 0x93c) = (undefined2)param_3;
    break;
  case 0x25:
    *(undefined2 *)(iVar3 + 0x954) = (undefined2)param_3;
    break;
  case 0x28:
    *(undefined2 *)(iVar3 + 0x95c) = (undefined2)param_3;
    break;
  case 0x29:
    *(undefined2 *)(iVar3 + 0x95e) = (undefined2)param_3;
    break;
  case 0x2a:
    if ((int)param_3 < 4) {
      local_40 = param_3;
    }
    else {
      local_40 = 3;
    }
    if ((int)local_40 < 0) {
      local_44 = 0;
    }
    else {
      if ((int)param_3 < 4) {
        local_48 = param_3;
      }
      else {
        local_48 = 3;
      }
      local_44 = local_48;
    }
    *(uint *)(iVar3 + 0xb00) = local_44;
    break;
  case 0x30:
    if (param_3 == 0xffffffff) {
      FUN_00475d30();
    }
    break;
  case 0x31:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      *(uint *)(iVar3 + 0xafc) = param_3;
    }
    break;
  case 0x32:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      *(uint *)(iVar3 + 0xb04) = param_3;
    }
    break;
  case 0x34:
    FUN_0042e900(param_3,0,1,iVar3);
    break;
  case 0x35:
    FUN_0042e900(param_3,1,1,iVar3);
    break;
  case 0x36:
    FUN_0042e900(param_3,2,1,iVar3);
    break;
  case 0x37:
    FUN_0042e900(param_3,0,0,iVar3);
    break;
  case 0x38:
    FUN_0042e900(param_3,1,0,iVar3);
    break;
  case 0x39:
    FUN_0042e900(param_3,2,0,iVar3);
    break;
  case 0x3b:
    *(uint *)(iVar3 + 0x9b4) = param_3;
    break;
  case 0x3c:
    *(uint *)(iVar3 + 0x9b8) = param_3;
    break;
  case 0x3d:
    *(uint *)(iVar3 + 0x928) = param_3;
    break;
  case 0x3e:
    *(uint *)(iVar3 + 0x92c) = param_3;
    break;
  case 0x3f:
    *(uint *)(iVar3 + 0x930) = param_3;
    break;
  case 0x40:
    *(uint *)(iVar3 + 0x934) = param_3;
    break;
  case 0x41:
    *(uint *)(iVar3 + 0x938) = param_3;
    break;
  case 0x42:
    *(uint *)(iVar3 + 0x91c) = param_3;
    break;
  case 0x43:
    *(uint *)(iVar3 + 0x920) = param_3;
    break;
  case 0x44:
    *(uint *)(iVar3 + 0x924) = param_3;
    break;
  case 0x45:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      DAT_00a14360 = param_3;
      FUN_00475460(0xffffffff);
      DAT_00a140bc = 0xfffffff6;
    }
    break;
  case 0x46:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      FUN_00475460(param_3);
      DAT_00a140bc = 0xfffffff6;
    }
    break;
  case 0x47:
    thunk_FUN_0050f410(param_3 * DAT_0084b248,DAT_00a14624 * DAT_0084b248);
    DAT_00a14620 = param_3;
    _DAT_00a14690 = param_3;
    break;
  case 0x48:
    thunk_FUN_0050f410(DAT_00a14620 * DAT_0084b248,param_3 * DAT_0084b248);
    DAT_00a14624 = param_3;
    _DAT_00a14694 = param_3;
    break;
  case 0x49:
    *(uint *)(iVar3 + 0x978) = param_3;
    break;
  case 0x4a:
    *(bool *)(iVar3 + 0xaf8) = param_3 != 0;
    if ((DAT_00a1469c < 0) || (iVar3 = FUN_0050e880(), iVar3 == 0)) {
      FUN_0050f160(1);
    }
    else {
      FUN_0050f160(DAT_00a18c70);
    }
    break;
  case 0x4b:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      DAT_00a14320 = param_3;
      return;
    }
  case 0x53:
    if ((*DAT_00a16628 < 15000) || (0x3c8b < *DAT_00a16628)) {
switchD_0043e61c_caseD_57:
      puVar1 = (uint *)FUN_004ce990(0);
      *puVar1 = param_3;
    }
    else {
      DAT_00a14324 = param_3;
    }
    break;
  case 0x57:
    goto switchD_0043e61c_caseD_57;
  case 0x58:
    puVar1 = (uint *)FUN_004ce990(1);
    *puVar1 = param_3;
    break;
  case 0x59:
    puVar1 = (uint *)FUN_004ce990(2);
    *puVar1 = param_3;
    break;
  case 0x5a:
    puVar1 = (uint *)FUN_004ce990(3);
    *puVar1 = param_3;
    break;
  case 0x5b:
    puVar1 = (uint *)FUN_004ce990(4);
    *puVar1 = param_3;
    break;
  case 0x5f:
    if (DAT_00a18d34 < 0) {
      DAT_00a18d34 = 3;
      _DAT_00a18d3c = 3;
    }
    _DAT_00a18d6c = DAT_00a18d48;
    _DAT_00a18d5c = DAT_00a18d48;
    DAT_00a18d48 = (int)(param_3 * DAT_00a18b88) / 100;
    DAT_00a18bcc = param_3;
    DAT_00a14344 = param_3;
    break;
  case 0x60:
    DAT_00a18d54 = param_3;
    if (DAT_00a18de4 == '\0') {
      piVar2 = (int *)FUN_004cc020(&DAT_00a18d28);
      FUN_0055d100((int)(param_3 * *piVar2) / 100,DAT_00a18d28);
    }
    else {
      _DAT_00a18e00 = 0xffffffff;
      fVar4 = (float)(int)param_3 * (float)_DAT_008044f8;
      FUN_00401000(fVar4);
      FUN_004014e0(fVar4);
    }
    break;
  case 0x61:
    if (DAT_00a18d38 < 0) {
      DAT_00a18d38 = 3;
      _DAT_00a18d40 = 3;
    }
    _DAT_00a18d70 = DAT_00a18d50;
    _DAT_00a18d64 = DAT_00a18d50;
    DAT_00a18d50 = (int)(param_3 * DAT_00a18b8c) / 100;
    DAT_00a18bd8 = param_3;
    DAT_00a14348 = param_3;
    break;
  case 0x62:
    DAT_00a18d58 = param_3;
    piVar2 = (int *)FUN_004cc020(&DAT_00a18d30);
    FUN_0055d100((int)(param_3 * *piVar2) / 100,DAT_00a18d30);
    break;
  case 100:
    if (iVar3 == DAT_00a16440) {
      if (DAT_00a18d34 < 0) {
        _DAT_00a18d3c = 1;
        DAT_00a18d34 = 0;
      }
      _DAT_00a18d5c = DAT_00a18d48;
      DAT_00a18d48 = (int)(param_3 * DAT_00a14344) / 100;
    }
    *(uint *)(iVar3 + 0xa10) = ((int)param_3 < 0) - 1 & param_3;
    break;
  case 0x65:
    if (iVar3 == DAT_00a16440) {
      if (DAT_00a18d38 < 0) {
        _DAT_00a18d40 = 1;
        DAT_00a18d38 = 0;
      }
      _DAT_00a18d64 = DAT_00a18d50;
      DAT_00a18d50 = (int)(param_3 * DAT_00a14348) / 100;
    }
    *(uint *)(iVar3 + 0xa14) = ((int)param_3 < 0) - 1 & param_3;
    break;
  case 0x66:
    *(uint *)(iVar3 + 0xa18) = param_3;
    break;
  case 0x68:
    if (iVar3 == DAT_00a16440) {
      if (DAT_00a180f4 == '\0') {
        iVar3 = FUN_0047a490();
        if ((int)(((int)param_3 < 1) - 1 & param_3) < (iVar3 + -0x14) * DAT_0084b264) {
          local_5c = ((int)param_3 < 1) - 1 & param_3;
        }
        else {
          iVar3 = FUN_0047a490();
          local_5c = (iVar3 + -0x14) * DAT_0084b264;
        }
        DAT_00a17ebc = local_5c << 2;
      }
      else {
        if (DAT_0084b264 * -10 + 1 < (int)param_3) {
          local_50 = param_3;
        }
        else {
          local_50 = DAT_0084b264 * -10 + 1;
        }
        iVar3 = FUN_0047a490();
        if ((int)local_50 < (iVar3 + -10) * DAT_0084b264) {
          if (DAT_0084b264 * -10 + 1 < (int)param_3) {
            local_54 = param_3;
          }
          else {
            local_54 = DAT_0084b264 * -10 + 1;
          }
          local_58 = local_54;
        }
        else {
          iVar3 = FUN_0047a490();
          local_58 = (iVar3 + -10) * DAT_0084b264;
        }
        DAT_00a17ebc = local_58 << 2;
      }
    }
    break;
  case 0x69:
    if (iVar3 == DAT_00a16440) {
      if (DAT_00a180f5 == '\0') {
        iVar3 = FUN_0047a4b0();
        if ((int)(((int)param_3 < 1) - 1 & param_3) < (iVar3 + -0xf) * DAT_0084b264 + 1) {
          local_74 = ((int)param_3 < 1) - 1 & param_3;
        }
        else {
          iVar3 = FUN_0047a4b0();
          local_74 = (iVar3 + -0xf) * DAT_0084b264 + 1;
        }
        DAT_00a17ec0 = local_74 << 2;
      }
      else {
        iVar3 = FUN_004fe844();
        if (iVar3 + -1 < (int)param_3) {
          local_60 = param_3;
        }
        else {
          iVar3 = FUN_004fe844();
          local_60 = iVar3 - 1;
        }
        FUN_0047a4b0();
        iVar3 = FUN_004fe844();
        if ((int)local_60 < iVar3) {
          iVar3 = FUN_004fe844();
          if (iVar3 + -1 < (int)param_3) {
            local_68 = param_3;
          }
          else {
            iVar3 = FUN_004fe844();
            local_68 = iVar3 - 1;
          }
          local_6c = local_68;
        }
        else {
          FUN_0047a4b0();
          local_6c = FUN_004fe844();
        }
        DAT_00a17ec0 = local_6c << 2;
      }
    }
    break;
  case 0x6e:
    FUN_004174a0(2,param_3);
    break;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x78:
    if ((int)(((int)param_3 < 0) - 1 & param_3) < 3) {
      local_78 = ((int)param_3 < 0) - 1 & param_3;
    }
    else {
      local_78 = 2;
    }
    DAT_00a117e0 = local_78;
    break;
  case 0x79:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      *(uint *)(iVar3 + 0xb0c) = param_3;
    }
  }
  return;
}


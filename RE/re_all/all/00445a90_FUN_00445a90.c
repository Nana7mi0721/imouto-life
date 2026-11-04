
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00445a90(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  char local_15;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_24 = DAT_0084b484;
  local_15 = FUN_004780e0();
  local_c = *(int *)(param_1 + 0x28);
  local_14 = *(int *)(param_1 + 0x2c);
  if (*(short *)(param_1 + 0xbc) != _DAT_00a18ab4) {
    puVar2 = (undefined1 *)FUN_004cd7c0(0);
    *puVar2 = DAT_00a18ab4;
  }
  cVar1 = FUN_004780e0();
  if (((((cVar1 == '\0') && (cVar1 = FUN_00486cd0(), cVar1 == '\0')) &&
       (*(char *)(param_1 + 0x52) == '\0')) && (DAT_00a1405c == '\0')) &&
     ((DAT_00a14062 == '\0' || ((DAT_00a14093 == '\0' && (DAT_00a140a8 == '\0')))))) {
    if (*DAT_00a1667c == '\b') {
      switch(DAT_00a14628) {
      case 1:
        if ((DAT_00a14ae0 == '\0') || (DAT_00a14ae1 == '\0')) {
          if (DAT_00a14ae0 == '\0') {
            if (DAT_00a14ae1 != '\0') {
              FUN_00479d30(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                    '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
            }
          }
          else {
            FUN_00479cf0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                  '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
          }
        }
        else {
          FUN_00479df0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 2:
        if (DAT_00a14ae0 != '\0') {
          FUN_00479cf0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 3:
        if ((DAT_00a14ae0 == '\0') || (DAT_00a14ae2 == '\0')) {
          if (DAT_00a14ae0 == '\0') {
            if (DAT_00a14ae2 != '\0') {
              FUN_00479d70(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                    '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
            }
          }
          else {
            FUN_00479cf0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                  '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
          }
        }
        else {
          FUN_00479e40(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 4:
        if (DAT_00a14ae1 != '\0') {
          FUN_00479d30(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 6:
        if (DAT_00a14ae2 != '\0') {
          FUN_00479d70(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 7:
        if ((DAT_00a14adf == '\0') || (DAT_00a14ae1 == '\0')) {
          if (DAT_00a14adf == '\0') {
            if (DAT_00a14ae1 != '\0') {
              FUN_00479d30(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                    '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
            }
          }
          else {
            FUN_00479db0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                  '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
          }
        }
        else {
          FUN_00479e90(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 8:
        if (DAT_00a14adf != '\0') {
          FUN_00479db0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 9:
        if ((DAT_00a14adf == '\0') || (DAT_00a14ae2 == '\0')) {
          if (DAT_00a14adf == '\0') {
            if (DAT_00a14ae2 != '\0') {
              FUN_00479d70(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                    '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
            }
          }
          else {
            FUN_00479db0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                  '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
          }
        }
        else {
          FUN_00479ee0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
      }
    }
    else if (*DAT_00a1667c == '\x04') {
      switch(DAT_00a1462c) {
      case 2:
        if (DAT_00a14ae0 != '\0') {
          FUN_00479cf0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 4:
        if (DAT_00a14ae1 != '\0') {
          FUN_00479d30(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 6:
        if (DAT_00a14ae2 != '\0') {
          FUN_00479d70(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
        break;
      case 8:
        if (DAT_00a14adf != '\0') {
          FUN_00479db0(CONCAT31((int3)(-(uint)*(byte *)(param_1 + 0xae) >> 8),
                                '\x01' - (*(byte *)(param_1 + 0xae) != 0)));
        }
      }
    }
  }
  local_10 = *(int *)(param_1 + 0x38);
  local_8 = *(int *)(param_1 + 0x3c);
  if ((local_c != *(int *)(param_1 + 0x28)) || (local_14 != *(int *)(param_1 + 0x2c))) {
    *(undefined1 *)(param_1 + 0x148) = 1;
  }
  FUN_00443270();
  FUN_00446730();
  if (DAT_00a18ae8 == 0) {
    for (local_1c = ((int)(*(int *)(param_1 + 0x38) + (*(int *)(param_1 + 0x38) >> 0x1f & 3U)) >> 2)
                    - ((int)(DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U)) >> 2);
        (DAT_00a180f4 != '\0' && (local_1c < 0)); local_1c = iVar3 * DAT_0084b264 + local_1c) {
      iVar3 = FUN_0047a490();
    }
    for (local_20 = ((int)(*(int *)(param_1 + 0x3c) + (*(int *)(param_1 + 0x3c) >> 0x1f & 3U)) >> 2)
                    - ((int)(DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U)) >> 2);
        (DAT_00a180f5 != '\0' && (local_20 < 0)); local_20 = iVar3 * DAT_0084b264 + local_20) {
      iVar3 = FUN_0047a4b0();
    }
    if ((local_8 < *(int *)(param_1 + 0x3c)) && ((*DAT_00a1671c - DAT_0084b264) * 2 < local_20 * 4))
    {
      FUN_00449f90(*(int *)(param_1 + 0x3c) - local_8);
    }
    if ((*(int *)(param_1 + 0x38) < local_10) && (local_1c * 4 < (*DAT_00a16718 - DAT_0084b264) * 2)
       ) {
      FUN_0044a0d0(local_10 - *(int *)(param_1 + 0x38));
    }
    if ((local_10 < *(int *)(param_1 + 0x38)) && ((*DAT_00a16718 - DAT_0084b264) * 2 < local_1c * 4)
       ) {
      FUN_0044a170(*(int *)(param_1 + 0x38) - local_10);
    }
    if ((*(int *)(param_1 + 0x3c) < local_8) && (local_20 * 4 < (*DAT_00a1671c - DAT_0084b264) * 2))
    {
      FUN_0044a2b0(local_8 - *(int *)(param_1 + 0x3c));
    }
  }
  if ((DAT_00a180f4 != '\0') &&
     (((*(int *)(param_1 + 0x28) < 0 ||
       (iVar3 = FUN_0047a490(), iVar3 * 2 <= *(int *)(param_1 + 0x28))) &&
      (*(int *)(param_1 + 0x38) == DAT_0084b264 * 2 * *(int *)(param_1 + 0x28))))) {
    if ((*(char *)(param_1 + 0x54) == '\0') || (DAT_00a18ae8 != 0)) {
      iVar4 = FUN_0047a490();
      iVar3 = *(int *)(param_1 + 0x28);
      iVar5 = FUN_0047a490();
      *(int *)(param_1 + 0x28) = (iVar3 + iVar4 * 4) % (iVar5 << 1);
      *(int *)(param_1 + 0x38) = DAT_0084b264 * 2 * *(int *)(param_1 + 0x28);
    }
    else {
      while (iVar3 = FUN_0047a490(), iVar3 * 2 <= *(int *)(param_1 + 0x28)) {
        iVar3 = FUN_0047a490();
        DAT_00a17ebc = DAT_00a17ebc + iVar3 * DAT_0084b264 * 2 * -2;
        iVar3 = FUN_0047a490();
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar3 * -2;
        iVar3 = FUN_0047a490();
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + iVar3 * DAT_0084b264 * 2 * -2;
      }
      while (*(int *)(param_1 + 0x28) < 0) {
        iVar3 = FUN_0047a490();
        DAT_00a17ebc = DAT_00a17ebc + iVar3 * DAT_0084b264 * 2 * 2;
        iVar3 = FUN_0047a490();
        *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar3 * 2;
        iVar3 = FUN_0047a490();
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + iVar3 * DAT_0084b264 * 2 * 2;
      }
    }
  }
  if (((DAT_00a180f5 != '\0') &&
      ((*(int *)(param_1 + 0x2c) < 0 ||
       (iVar3 = FUN_0047a4b0(), iVar3 * 2 <= *(int *)(param_1 + 0x2c))))) &&
     (*(int *)(param_1 + 0x3c) == DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c))) {
    if ((*(char *)(param_1 + 0x54) == '\0') || (DAT_00a18ae8 != 0)) {
      iVar4 = FUN_0047a4b0();
      iVar3 = *(int *)(param_1 + 0x2c);
      iVar5 = FUN_0047a4b0();
      *(int *)(param_1 + 0x2c) = (iVar3 + iVar4 * 4) % (iVar5 << 1);
      *(int *)(param_1 + 0x3c) = DAT_0084b264 * 2 * *(int *)(param_1 + 0x2c);
    }
    else {
      while (iVar3 = FUN_0047a4b0(), iVar3 * 2 <= *(int *)(param_1 + 0x2c)) {
        iVar3 = FUN_0047a4b0();
        DAT_00a17ec0 = DAT_00a17ec0 + iVar3 * DAT_0084b264 * 2 * -2;
        iVar3 = FUN_0047a4b0();
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + iVar3 * -2;
        iVar3 = FUN_0047a4b0();
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + iVar3 * DAT_0084b264 * 2 * -2;
      }
      while (*(int *)(param_1 + 0x2c) < 0) {
        iVar3 = FUN_0047a4b0();
        DAT_00a17ec0 = DAT_00a17ec0 + iVar3 * DAT_0084b264 * 2 * 2;
        iVar3 = FUN_0047a4b0();
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + iVar3 * 2;
        iVar3 = FUN_0047a4b0();
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + iVar3 * DAT_0084b264 * 2 * 2;
      }
    }
  }
  if ((((DAT_00a18ac4 != '\0') || (cVar1 = FUN_00486cd0(), cVar1 == '\0')) &&
      ((int)*(short *)(param_1 + 0x5e) * (int)*(short *)(param_1 + 0x5e) * 0x14 <
       *(int *)(param_1 + 100))) && (*(short *)(param_1 + 0x58) == 1)) {
    FUN_0044cf90();
  }
  if (*(char *)(param_1 + 0x52) != '\0') {
    FUN_0044cf90();
  }
  cVar1 = FUN_004780e0();
  if (cVar1 == '\0') {
    if ((local_15 == '\0') && (*(char *)(param_1 + 0x148) == '\0')) {
      local_38 = 0;
      local_37 = 0;
      local_36 = 0;
      local_35 = 0;
      local_34 = 1;
      local_39 = FUN_00444a80(&local_38);
    }
    else {
      *(undefined1 *)(param_1 + 0x148) = 0;
      local_2c = 0;
      local_2b = 0;
      local_2a = 0;
      local_29 = 1;
      local_28 = 1;
      local_2d = FUN_00444a80(&local_2c);
    }
    cVar1 = FUN_004780e0();
    if (((((cVar1 == '\0') && (cVar1 = FUN_00486cd0(), cVar1 == '\0')) &&
         ((*(char *)(param_1 + 0x52) == '\0' && (DAT_00a1405c == '\0')))) &&
        ((DAT_00a14062 == '\0' || ((DAT_00a14093 == '\0' && (DAT_00a140a8 == '\0')))))) &&
       ((DAT_00a14adc != '\0' && (DAT_00a14670 != '\0')))) {
      local_44 = 1;
      local_43 = 0;
      local_42 = 0;
      local_41 = 0;
      local_40 = 0;
      FUN_00444a80(&local_44);
      local_4c = 1;
      local_4b = 0;
      local_4a = 0;
      local_49 = 0;
      local_48 = 0;
      FUN_00444dd0(&local_4c);
    }
  }
  return;
}


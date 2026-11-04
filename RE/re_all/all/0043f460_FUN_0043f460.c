
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_0043f460(int *param_1,undefined4 param_2)

{
  char cVar1;
  tm *ptVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_2c;
  uint local_28;
  undefined1 local_24 [8];
  undefined1 local_1c [8];
  undefined1 local_14 [8];
  undefined8 local_c;
  
  if (*param_1 == 0) {
    return 0;
  }
  local_c._4_4_ = *param_1;
  switch(param_2) {
  case 0:
    local_2c = *(uint *)(local_c._4_4_ + 0x8cc);
    break;
  case 1:
    local_2c = *(uint *)(local_c._4_4_ + 0x8d0);
    break;
  case 2:
    local_2c = *(uint *)(local_c._4_4_ + 0x8d4);
    break;
  case 3:
    local_2c = *(uint *)(local_c._4_4_ + 0x8d8);
    break;
  case 4:
    local_2c = *(uint *)(local_c._4_4_ + 0x8dc);
    break;
  case 5:
    local_2c = (uint)*(short *)(local_c._4_4_ + 0x94e);
    break;
  case 6:
    local_2c = (uint)*(short *)(local_c._4_4_ + 0x950);
    break;
  case 7:
    local_2c = *(uint *)(local_c._4_4_ + 0x8ec);
    break;
  case 8:
    local_2c = *(uint *)(local_c._4_4_ + 0x918);
    break;
  case 9:
    local_2c = *(uint *)(local_c._4_4_ + 0x960);
    break;
  case 10:
    local_2c = *(uint *)(local_c._4_4_ + 0x968);
    break;
  case 0xb:
    local_2c = *(uint *)(local_c._4_4_ + 0x964);
    break;
  case 0xc:
    local_2c = DAT_00a140b4;
    break;
  case 0xd:
    cVar1 = FUN_00486cd0();
    local_2c = (uint)(cVar1 != '\0');
    break;
  case 0xe:
    local_2c = (uint)*(char *)(local_c._4_4_ + 0x96c);
    break;
  case 0xf:
    local_2c = *(uint *)(local_c._4_4_ + 0x940);
    break;
  case 0x10:
    local_2c = *(uint *)(local_c._4_4_ + 0x944);
    break;
  case 0x11:
    local_2c = *(uint *)(local_c._4_4_ + 0x8e0);
    break;
  case 0x12:
    local_2c = *(uint *)(local_c._4_4_ + 0x8e4);
    break;
  case 0x13:
    local_2c = *(uint *)(local_c._4_4_ + 0x8e8);
    break;
  case 0x14:
    local_2c = DAT_00a140c0;
    break;
  case 0x15:
    local_2c = DAT_00a18aec;
    break;
  case 0x16:
    local_2c = DAT_00a18b20;
    break;
  case 0x17:
    local_2c = DAT_00a18c80;
    break;
  case 0x18:
    local_2c = *(uint *)(local_c._4_4_ + 0x910);
    break;
  case 0x19:
    local_2c = *(uint *)(local_c._4_4_ + 0x948);
    break;
  default:
    goto switchD_0043f494_caseD_1a;
  case 0x1c:
    local_2c = *(uint *)(local_c._4_4_ + 0x9d4);
    break;
  case 0x1d:
    local_2c = *(uint *)(local_c._4_4_ + 0x8b0);
    break;
  case 0x1e:
    local_2c = *(uint *)(local_c._4_4_ + 0x8b8);
    break;
  case 0x1f:
    local_2c = *(uint *)(local_c._4_4_ + 0x8c4);
    break;
  case 0x20:
    local_2c = *(uint *)(local_c._4_4_ + 0x8c8);
    break;
  case 0x21:
    local_2c = *(uint *)(local_c._4_4_ + 0x914);
    break;
  case 0x23:
    local_2c = FUN_004780e0();
    local_2c = local_2c & 0xff;
    break;
  case 0x24:
    local_2c = (uint)*(short *)(local_c._4_4_ + 0x93c);
    break;
  case 0x25:
    local_2c = (uint)*(short *)(local_c._4_4_ + 0x954);
    break;
  case 0x27:
    local_2c = *(uint *)(local_c._4_4_ + 0x958);
    break;
  case 0x28:
    local_2c = (uint)*(short *)(local_c._4_4_ + 0x95c);
    break;
  case 0x29:
    local_2c = (uint)*(short *)(local_c._4_4_ + 0x95e);
    break;
  case 0x2a:
    local_2c = *(uint *)(local_c._4_4_ + 0xb00);
    break;
  case 0x2b:
    local_2c = DAT_00a16424;
    break;
  case 0x2c:
    local_2c = DAT_00a16428;
    break;
  case 0x2d:
    local_2c = DAT_00a1642c;
    break;
  case 0x2e:
    local_2c = DAT_00a16430;
    break;
  case 0x2f:
    local_2c = DAT_00a16434;
    break;
  case 0x30:
    local_2c = DAT_00a16438;
    break;
  case 0x31:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return *(uint *)(local_c._4_4_ + 0xafc);
    }
    goto switchD_0043f494_caseD_1a;
  case 0x32:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return *(uint *)(local_c._4_4_ + 0xb04);
    }
    goto switchD_0043f494_caseD_1a;
  case 0x33:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return DAT_00a14364;
    }
    goto switchD_0043f494_caseD_1a;
  case 0x34:
    local_2c = FUN_0042ee40(0,1,local_c._4_4_);
    break;
  case 0x35:
    local_2c = FUN_0042ee40(1,1,local_c._4_4_);
    break;
  case 0x36:
    local_2c = FUN_0042ee40(2,1,local_c._4_4_);
    break;
  case 0x37:
    local_2c = FUN_0042ee40(0,0,local_c._4_4_);
    break;
  case 0x38:
    local_2c = FUN_0042ee40(1,0,local_c._4_4_);
    break;
  case 0x39:
    local_2c = FUN_0042ee40(2,0,local_c._4_4_);
    break;
  case 0x3b:
    local_2c = *(uint *)(local_c._4_4_ + 0x9b4);
    break;
  case 0x3c:
    local_2c = *(uint *)(local_c._4_4_ + 0x9b8);
    break;
  case 0x3d:
    local_2c = *(uint *)(local_c._4_4_ + 0x928);
    break;
  case 0x3e:
    local_2c = *(uint *)(local_c._4_4_ + 0x92c);
    break;
  case 0x3f:
    local_2c = *(uint *)(local_c._4_4_ + 0x930);
    break;
  case 0x40:
    local_2c = *(uint *)(local_c._4_4_ + 0x934);
    break;
  case 0x41:
    local_2c = *(uint *)(local_c._4_4_ + 0x938);
    break;
  case 0x42:
    local_2c = *(uint *)(local_c._4_4_ + 0x91c);
    break;
  case 0x43:
    local_2c = *(uint *)(local_c._4_4_ + 0x920);
    break;
  case 0x44:
    local_2c = *(uint *)(local_c._4_4_ + 0x924);
    break;
  case 0x45:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return DAT_00a14360;
    }
    goto switchD_0043f494_caseD_1a;
  case 0x46:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return DAT_00a1435c;
    }
    goto switchD_0043f494_caseD_1a;
  case 0x47:
    local_2c = DAT_00a14620;
    break;
  case 0x48:
    local_2c = DAT_00a14624;
    break;
  case 0x49:
    local_2c = *(uint *)(local_c._4_4_ + 0x978);
    break;
  case 0x4a:
    local_2c = (uint)(*(char *)(local_c._4_4_ + 0xaf8) != '\0');
    break;
  case 0x4b:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return DAT_00a14320;
    }
  case 0x4c:
    if ((*DAT_00a16628 < 15000) || (0x3c8b < *DAT_00a16628)) {
switchD_0043f494_caseD_4d:
      FID_conflict___time32((__time32_t *)(local_14 + 4));
      local_14._4_4_ = local_14._4_4_ + DAT_00a14324;
      if (DAT_00a14320 == 1) {
        ptVar2 = _gmtime((time_t *)(local_14 + 4));
        local_38 = ptVar2->tm_year;
      }
      else {
        ptVar2 = _localtime((time_t *)(local_14 + 4));
        local_38 = ptVar2->tm_year;
      }
      local_2c = local_38 + 0x76c;
    }
    else {
      FID_conflict___time32((__time32_t *)&local_c);
      ptVar2 = _localtime(&local_c);
      local_2c = ptVar2->tm_isdst;
    }
    break;
  case 0x4d:
    goto switchD_0043f494_caseD_4d;
  case 0x4e:
    FID_conflict___time32((__time32_t *)local_14);
    local_14._0_4_ = local_14._0_4_ + DAT_00a14324;
    if (DAT_00a14320 == 1) {
      ptVar2 = _gmtime((time_t *)local_14);
      local_3c = ptVar2->tm_mon;
    }
    else {
      ptVar2 = _localtime((time_t *)local_14);
      local_3c = ptVar2->tm_mon;
    }
    local_2c = local_3c + 1;
    break;
  case 0x4f:
    FID_conflict___time32((__time32_t *)(local_1c + 4));
    local_1c._4_4_ = local_1c._4_4_ + DAT_00a14324;
    if (DAT_00a14320 == 1) {
      ptVar2 = _gmtime((time_t *)(local_1c + 4));
      local_40 = ptVar2->tm_mday;
    }
    else {
      ptVar2 = _localtime((time_t *)(local_1c + 4));
      local_40 = ptVar2->tm_mday;
    }
    local_2c = local_40;
    break;
  case 0x50:
    FID_conflict___time32((__time32_t *)local_1c);
    local_1c._0_4_ = local_1c._0_4_ + DAT_00a14324;
    if (DAT_00a14320 == 1) {
      ptVar2 = _gmtime((time_t *)local_1c);
      local_44 = ptVar2->tm_hour;
    }
    else {
      ptVar2 = _localtime((time_t *)local_1c);
      local_44 = ptVar2->tm_hour;
    }
    local_2c = local_44;
    break;
  case 0x51:
    FID_conflict___time32((__time32_t *)(local_24 + 4));
    local_24._4_4_ = local_24._4_4_ + DAT_00a14324;
    if (DAT_00a14320 == 1) {
      ptVar2 = _gmtime((time_t *)(local_24 + 4));
      local_48 = ptVar2->tm_min;
    }
    else {
      ptVar2 = _localtime((time_t *)(local_24 + 4));
      local_48 = ptVar2->tm_min;
    }
    local_2c = local_48;
    break;
  case 0x52:
    FID_conflict___time32((__time32_t *)local_24);
    local_24._0_4_ = local_24._0_4_ + DAT_00a14324;
    if (DAT_00a14320 == 1) {
      ptVar2 = _gmtime((time_t *)local_24);
      local_4c = ptVar2->tm_sec;
    }
    else {
      ptVar2 = _localtime((time_t *)local_24);
      local_4c = ptVar2->tm_sec;
    }
    local_2c = local_4c;
    break;
  case 0x53:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return DAT_00a14324;
    }
  case 0x54:
    if ((*DAT_00a16718 == 0x140) && (*DAT_00a1671c == 0xf0)) {
      local_2c = 0;
    }
    else if ((*DAT_00a16718 == 0x280) && (*DAT_00a1671c == 0x1e0)) {
      local_2c = 1;
    }
    else if ((*DAT_00a16718 == 800) && (*DAT_00a1671c == 600)) {
      local_2c = 2;
    }
    else {
      local_2c = 0xffffffff;
    }
    break;
  case 0x55:
    iVar4 = FUN_00516960();
    local_2c = (uint)(iVar4 != 1);
    break;
  case 0x57:
    puVar3 = (uint *)FUN_004ce990(0);
    local_2c = *puVar3;
    break;
  case 0x58:
    puVar3 = (uint *)FUN_004ce990(1);
    local_2c = *puVar3;
    break;
  case 0x59:
    puVar3 = (uint *)FUN_004ce990(2);
    local_2c = *puVar3;
    break;
  case 0x5a:
    puVar3 = (uint *)FUN_004ce990(3);
    local_2c = *puVar3;
    break;
  case 0x5b:
    puVar3 = (uint *)FUN_004ce990(4);
    local_2c = *puVar3;
    break;
  case 0x5f:
    local_2c = DAT_00a18bcc;
    break;
  case 0x60:
    local_2c = DAT_00a18d54;
    break;
  case 0x61:
    local_2c = DAT_00a18bd8;
    break;
  case 0x62:
    local_2c = DAT_00a18d58;
    break;
  case 100:
    local_2c = *(uint *)(local_c._4_4_ + 0xa10);
    break;
  case 0x65:
    local_2c = *(uint *)(local_c._4_4_ + 0xa14);
    break;
  case 0x66:
    local_2c = *(uint *)(local_c._4_4_ + 0xa18);
    break;
  case 0x68:
    iVar4 = DAT_00a17ebc + (DAT_00a17ebc >> 0x1f & 3U);
    iVar5 = FUN_0047a490();
    for (local_28 = (uint)(CONCAT44(iVar4 >> 0x1f,iVar4 >> 2) % (longlong)(iVar5 * DAT_0084b264));
        iVar4 = FUN_0047a490(), (iVar4 + -10) * DAT_0084b264 < (int)local_28;
        local_28 = local_28 - iVar4 * DAT_0084b264) {
      iVar4 = FUN_0047a490();
    }
    local_2c = local_28;
    break;
  case 0x69:
    iVar4 = DAT_00a17ec0 + (DAT_00a17ec0 >> 0x1f & 3U);
    iVar5 = FUN_0047a4b0();
    for (local_2c = (uint)(CONCAT44(iVar4 >> 0x1f,iVar4 >> 2) % (longlong)(iVar5 * DAT_0084b264));
        iVar4 = FUN_0047a4b0(),
        ((double)iVar4 - _DAT_007d0a48) * (double)DAT_0084b264 < (double)(int)local_2c;
        local_2c = local_2c - iVar4 * DAT_0084b264) {
      iVar4 = FUN_0047a4b0();
    }
    break;
  case 0x6c:
    local_2c = DAT_00a1434c;
    break;
  case 0x6e:
    local_2c = FUN_004174a0(1,0);
    break;
  case 0x6f:
    local_2c = FUN_0050e880();
    break;
  case 0x70:
    local_2c = DAT_00a117a8;
    break;
  case 0x71:
    local_2c = 0;
    break;
  case 0x72:
    local_2c = 0;
    break;
  case 0x73:
    local_2c = 0xde;
    break;
  case 0x74:
    local_2c = DAT_0084b230 / DAT_0084b248;
    break;
  case 0x75:
    local_2c = DAT_0084b234 / DAT_0084b248;
    break;
  case 0x76:
    local_2c = (uint)*DAT_00a16674;
    break;
  case 0x78:
    local_2c = DAT_00a117e0;
    break;
  case 0x79:
    if ((14999 < *DAT_00a16628) && (*DAT_00a16628 < 0x3c8c)) {
      return *(uint *)(local_c._4_4_ + 0xb0c);
    }
switchD_0043f494_caseD_1a:
    local_2c = 0xffffffff;
  }
  return local_2c;
}



void __fastcall FUN_004474a0(undefined4 *param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_c;
  
  if ((param_1[0x95] != -1) && (*(char *)((int)param_1 + 0xbe) == '\0')) {
    if ((int)param_1[0x94] < 1) {
      *(undefined1 *)((int)param_1 + 0xbe) = 1;
      (**(code **)*param_1)();
    }
    param_1[0x94] = param_1[0x94] - DAT_0084b244;
    if (param_1[0x95] == 0) {
      local_c = 1;
    }
    else {
      local_c = param_1[0x95];
    }
    *(short *)(param_1 + 0x11) = (short)((int)(param_1[0x96] * param_1[0x94]) / local_c);
  }
  FUN_00443270();
  if (((DAT_00a18ac4 != '\0') || (cVar2 = FUN_00486cd0(), cVar2 == '\0')) &&
     ((int)*(short *)((int)param_1 + 0x5e) * (int)*(short *)((int)param_1 + 0x5e) * 0x14 <
      (int)param_1[0x19])) {
    sVar1 = *(short *)(param_1 + 0x16);
    if (sVar1 == 1) {
      FUN_0044be30();
    }
    else if (sVar1 == 2) {
      FUN_0044bba0();
    }
    else if (sVar1 == 3) {
      FUN_0044bc00();
    }
  }
  if ((DAT_00a180f4 != '\0') &&
     ((((int)param_1[10] < 0 && (DAT_0084b264 * 2 * param_1[10] <= (int)param_1[0xe])) ||
      ((iVar3 = FUN_0047a490(), iVar3 * 2 <= (int)param_1[10] &&
       ((int)param_1[0xe] <= DAT_0084b264 * 2 * param_1[10])))))) {
    while (iVar3 = FUN_0047a490(), iVar3 * 2 <= (int)param_1[10]) {
      iVar3 = FUN_0047a490();
      param_1[10] = param_1[10] + iVar3 * -2;
      iVar3 = FUN_0047a490();
      param_1[0xe] = param_1[0xe] + iVar3 * DAT_0084b264 * 2 * -2;
    }
    while ((int)param_1[10] < 0) {
      iVar3 = FUN_0047a490();
      param_1[10] = param_1[10] + iVar3 * 2;
      iVar3 = FUN_0047a490();
      param_1[0xe] = param_1[0xe] + iVar3 * DAT_0084b264 * 2 * 2;
    }
  }
  if ((DAT_00a180f5 != '\0') &&
     ((((int)param_1[0xb] < 0 && ((int)param_1[0xf] <= DAT_0084b264 * 2 * param_1[0xb])) ||
      ((iVar3 = FUN_0047a4b0(), iVar3 * 2 <= (int)param_1[0xb] &&
       (DAT_0084b264 * 2 * param_1[0xb] <= (int)param_1[0xf])))))) {
    while (iVar3 = FUN_0047a4b0(), iVar3 * 2 <= (int)param_1[0xb]) {
      iVar3 = FUN_0047a4b0();
      param_1[0xb] = param_1[0xb] + iVar3 * -2;
      iVar3 = FUN_0047a4b0();
      param_1[0xf] = param_1[0xf] + iVar3 * DAT_0084b264 * 2 * -2;
    }
    while ((int)param_1[0xb] < 0) {
      iVar3 = FUN_0047a4b0();
      param_1[0xb] = param_1[0xb] + iVar3 * 2;
      iVar3 = FUN_0047a4b0();
      param_1[0xf] = param_1[0xf] + iVar3 * DAT_0084b264 * 2 * 2;
    }
  }
  FUN_00479bd0();
  iVar3 = FUN_004d21f0();
  if ((0 < iVar3) && (param_1[0x95] == -1)) {
    FUN_004d2250(0);
    cVar2 = FUN_00486cd0();
    if (cVar2 == '\0') {
      uVar5 = 0xffffffff;
      uVar4 = param_1[0x7d];
      param_1 = param_1 + 0x90;
      FUN_004d2250(0);
      FUN_0044ecd0(param_1,uVar4,uVar5);
    }
    FUN_004d2250(0);
    FUN_0044ef40();
  }
  return;
}


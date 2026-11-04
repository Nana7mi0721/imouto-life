
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00443270(int param_1)

{
  short sVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  
  if ((DAT_00a1fb98 == 0) && (DAT_00a1fb98 = 1, *DAT_00a16690 == '\x05')) {
    DAT_0084b3c4 = DAT_0084b3c4 / 2;
    DAT_0084b3c8 = DAT_0084b3c8 / 2;
    DAT_0084b3cc = DAT_0084b3cc / 2;
    DAT_0084b3d0 = DAT_0084b3d0 / 2;
    DAT_0084b3d4 = (DAT_0084b3d4 << 1) / 3;
    DAT_0084b3d8 = (int)(DAT_0084b3d8 * 3 + (DAT_0084b3d8 * 3 >> 0x1f & 3U)) >> 2;
  }
  cVar2 = FUN_00478410();
  if (cVar2 == '\0') {
    cVar2 = FUN_004780e0();
    if (cVar2 == '\0') {
      FUN_00443a10();
    }
    else {
      FUN_00443770();
    }
  }
  else {
    FUN_00478430();
  }
  if (0 < *(int *)(param_1 + 0xe8)) {
    *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + -1;
  }
  if (0 < *(int *)(param_1 + 0x10c)) {
    if (*(int *)(param_1 + 0x114) == 0) {
      *(int *)(param_1 + 0x110) = (*(int *)(param_1 + 0x110) + 1) % (*(int *)(param_1 + 0x10c) << 1)
      ;
    }
    else if (*(int *)(param_1 + 0x114) == 1) {
      *(int *)(param_1 + 0x110) = (*(int *)(param_1 + 0x110) + 1) % *(int *)(param_1 + 0x10c);
    }
  }
  if (*(int *)(param_1 + 0xf4) < 1) {
    *(undefined4 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xf4) & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    cVar2 = (-(uVar4 != 0) & 2U) - 1;
    if (*(int *)(param_1 + 0xfc) < *(int *)(param_1 + 0xf8)) {
      *(int *)(param_1 + 0x100) =
           (int)cVar2 *
           ((*(int *)(param_1 + 0xec) * *(int *)(param_1 + 0xfc)) / *(int *)(param_1 + 0xf8));
      *(int *)(param_1 + 0x104) =
           (int)cVar2 *
           ((*(int *)(param_1 + 0xf0) * *(int *)(param_1 + 0xfc)) / *(int *)(param_1 + 0xf8));
    }
    else {
      *(int *)(param_1 + 0x100) =
           (int)cVar2 *
           (*(int *)(param_1 + 0xec) -
           ((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xf8)) * *(int *)(param_1 + 0xec)) /
           *(int *)(param_1 + 0xf8));
      *(int *)(param_1 + 0x104) =
           (int)cVar2 *
           (*(int *)(param_1 + 0xf0) -
           ((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xf8)) * *(int *)(param_1 + 0xf0)) /
           *(int *)(param_1 + 0xf8));
    }
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
    if (*(int *)(param_1 + 0xfc) < 1) {
      *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + -1;
      *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xf8) << 1;
    }
  }
  if ((double)*(int *)(&DAT_0084b3c0 + *(short *)(param_1 + 0x5c) * 4) <
      *(double *)(param_1 + 0x140)) {
    if ((*(char *)(param_1 + 0xad) == '\0') && (DAT_0084b244 < *(int *)(param_1 + 100))) {
      *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(param_1 + 0x4c);
      *(undefined2 *)(param_1 + 0x60) = 0;
    }
    else if (*DAT_00a16690 == '\x03') {
      uVar4 = (int)*(short *)(param_1 + 0x60) + 1U & 0x80000003;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
      }
      *(short *)(param_1 + 0x60) = (short)uVar4;
      if (*(short *)(param_1 + 0x60) < 2) {
        *(short *)(param_1 + 0x4a) = *(short *)(param_1 + 0x62) + *(short *)(param_1 + 0x60);
      }
      else {
        *(short *)(param_1 + 0x4a) = *(short *)(param_1 + 0x62) - (*(short *)(param_1 + 0x60) + -2);
      }
    }
    else if (*DAT_00a16690 == '\x05') {
      uVar4 = (int)*(short *)(param_1 + 0x60) + 1U & 0x80000007;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
      }
      *(short *)(param_1 + 0x60) = (short)uVar4;
      if (*(short *)(param_1 + 0x60) < 5) {
        sVar1 = *(short *)(param_1 + 0x62);
        sVar3 = FUN_004febf1(2 - *(short *)(param_1 + 0x60));
        *(short *)(param_1 + 0x4a) = (sVar1 + 2) - sVar3;
      }
      else {
        sVar1 = *(short *)(param_1 + 0x62);
        sVar3 = FUN_004febf1(6 - *(short *)(param_1 + 0x60));
        *(short *)(param_1 + 0x4a) = sVar1 + -2 + sVar3;
      }
    }
    *(undefined8 *)(param_1 + 0x140) = _DAT_007d0a60;
  }
  if (*(int *)(param_1 + 0x70) < 1) {
    if ((*(char *)(param_1 + 0x54) == '\0') && (*(char *)(param_1 + 0x52) != '\0')) {
      FUN_0044cf90();
    }
    else if (*(char *)(param_1 + 0x57) == '\0') {
      FUN_004783f0();
    }
  }
  else {
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) - DAT_0084b244;
  }
  *(undefined1 *)(param_1 + 0x11c) = *(undefined1 *)(param_1 + 0xc2);
  *(undefined1 *)(param_1 + 0xc2) = *(undefined1 *)(param_1 + 0xc1);
  return;
}


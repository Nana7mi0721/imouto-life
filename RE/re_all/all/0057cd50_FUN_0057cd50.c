
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057cd50(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  float10 fVar4;
  float fStack_10;
  undefined1 uStack_c;
  undefined4 uStack_8;
  
  unaff_ESI[0xc] = _DAT_007d1038;
  *(undefined1 *)((int)unaff_ESI + 10) = 6;
  *(undefined1 *)((int)unaff_ESI + 0xb) = 6;
  *(undefined1 *)((int)unaff_ESI + 0x13) = 6;
  *(undefined1 *)((int)unaff_ESI + 9) = 5;
  *(undefined1 *)(unaff_ESI + 3) = 0x1b;
  *(undefined1 *)((int)unaff_ESI + 0xd) = 0x1b;
  *(undefined1 *)((int)unaff_ESI + 0x11) = 4;
  fVar1 = (float)_DAT_00829840;
  unaff_ESI[6] = (float)(int)unaff_EDI[1] / fVar1;
  unaff_ESI[7] = (float)(int)unaff_EDI[2] / fVar1;
  fVar1 = (float)unaff_EDI[5];
  if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
    fVar4 = (float10)FUN_0056d570((double)(float)unaff_EDI[5]);
    iVar3 = (int)ROUND((double)(fVar4 * (float10)_DAT_008053c8));
    if (iVar3 < -8) {
      iVar3 = -8;
    }
    *(undefined1 *)(unaff_ESI + 4) = 8;
    if (iVar3 < 0) {
      cVar2 = (char)iVar3 + '\b';
    }
    else {
      cVar2 = '\b';
    }
    *(char *)((int)unaff_ESI + 0x12) = cVar2;
    fVar1 = (float)unaff_EDI[4];
  }
  else {
    fVar4 = (float10)FUN_0056d570((double)(float)unaff_EDI[5]);
    iVar3 = (int)ROUND((double)(fVar4 * (float10)_DAT_007d8bf8));
    if (iVar3 < -8) {
      *(undefined1 *)(unaff_ESI + 4) = 0;
      *(undefined1 *)((int)unaff_ESI + 0x12) = 8;
      fVar1 = (float)unaff_EDI[4] * (float)unaff_EDI[5];
    }
    else if (iVar3 < 0) {
      *(char *)(unaff_ESI + 4) = (char)iVar3 + '\b';
      *(undefined1 *)((int)unaff_ESI + 0x12) = 8;
      fVar1 = (float)unaff_EDI[4] * (float)unaff_EDI[5];
    }
    else {
      *(undefined1 *)(unaff_ESI + 4) = 8;
      *(undefined1 *)((int)unaff_ESI + 0x12) = 8;
      fVar1 = (float)unaff_EDI[4] * (float)unaff_EDI[5];
    }
  }
  unaff_ESI[10] = fVar1;
  fVar1 = (float)_DAT_007d1010;
  fStack_10 = (float)unaff_EDI[7] * fVar1;
  if (fStack_10 < _DAT_007d8bf4) {
    if (fStack_10 <= 1.0) {
      fStack_10 = 1.0;
    }
  }
  else {
    fStack_10 = _DAT_007d8bf0;
  }
  uStack_8 = (undefined4)(longlong)ROUND(fStack_10);
  unaff_ESI[1] = uStack_8;
  fStack_10 = fVar1 * (float)unaff_EDI[9];
  if ((!NAN(_DAT_007d8bec) && !NAN(fStack_10)) &&
      _DAT_007d8bec < fStack_10 != (_DAT_007d8bec == fStack_10)) {
    fStack_10 = _DAT_007d8be8;
  }
  uStack_c = (undefined1)(int)ROUND(fStack_10);
  *(undefined1 *)(unaff_ESI + 2) = uStack_c;
  fVar1 = (float)_DAT_00829840;
  unaff_ESI[8] = (float)(int)unaff_EDI[6] / fVar1;
  unaff_ESI[9] = (float)(int)unaff_EDI[8] / fVar1;
  uStack_c = (undefined1)(int)ROUND(((float)unaff_EDI[10] * (float)_DAT_008053e8) / fVar1);
  *(undefined1 *)((int)unaff_ESI + 0xe) = uStack_c;
  *(undefined1 *)((int)unaff_ESI + 0xf) = uStack_c;
  unaff_ESI[0xb] = unaff_EDI[0xb];
  unaff_ESI[5] = unaff_EDI[0xc];
  *unaff_ESI = *unaff_EDI;
  unaff_ESI[0xd] = 0;
  return;
}


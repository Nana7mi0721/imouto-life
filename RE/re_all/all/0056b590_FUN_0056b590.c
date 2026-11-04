
void FUN_0056b590(void)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  short *unaff_ESI;
  
  if (DAT_00aaf320 == 0) {
    FUN_0052c670();
  }
  else {
    FUN_0056cf70();
  }
  iVar2 = 0;
  sVar1 = *unaff_ESI;
  while (sVar1 != 0) {
    iVar2 = iVar2 + 1;
    sVar1 = unaff_ESI[iVar2];
  }
  if ((unaff_ESI[iVar2 + -1] != 0x5c) && (unaff_ESI[iVar2 + -1] != 0x2f)) {
    FUN_0056d040();
    iVar2 = 0;
    sVar1 = *unaff_ESI;
    while (sVar1 != 0) {
      iVar2 = iVar2 + 1;
      sVar1 = unaff_ESI[iVar2];
    }
  }
  FUN_0056cf70(unaff_ESI + iVar2,in_EAX + iVar2 * -2,&DAT_00aaff24);
  return;
}



void __fastcall FUN_0044ed30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_c;
  int local_8;
  
  if (DAT_00a1809c != '\0') {
    FUN_00449ee0();
  }
  if (DAT_00a14058 < 0) {
    for (local_8 = 0; iVar2 = FUN_004d29a0(), local_8 < iVar2; local_8 = local_8 + 1) {
      iVar2 = FUN_004d2a00(local_8);
      if ((*(char *)(iVar2 + 0x1f1) != '\0') &&
         (iVar2 = FUN_004d2a00(local_8), *(int *)(iVar2 + 0x254) == -1)) {
        iVar2 = FUN_004d2a00(local_8);
        if (*(int *)(iVar2 + 0x1e8) != 1) {
          FUN_004d2a00(local_8);
          FUN_00479ad0();
          FUN_004d2a00(local_8);
          FUN_00486dd0();
        }
        iVar2 = FUN_004d2a00(local_8);
        FUN_004cead0(iVar2 + 0x240);
        uVar4 = 0xffffffff;
        iVar2 = FUN_004d2a00(local_8);
        FUN_0044ecd0(param_1 + 0x80c,*(undefined4 *)(iVar2 + 0x24),uVar4);
        return;
      }
    }
    for (local_c = 0; iVar2 = FUN_004cfab0(), local_c < iVar2; local_c = local_c + 1) {
      FUN_004cfaf0(local_c);
      cVar1 = FUN_00486cf0();
      if (cVar1 != '\0') {
        iVar2 = FUN_004cfaf0(local_c);
        FUN_004cead0(iVar2 + 0x30);
        puVar3 = (undefined4 *)FUN_004cfaf0(local_c);
        FUN_0044ecd0(param_1 + 0x80c,0xffffffff,*puVar3);
        return;
      }
    }
  }
  else {
    iVar2 = FUN_004cfb40(DAT_00a14058);
    FUN_004cead0(iVar2 + 0x30);
    FUN_0044ecd0(param_1 + 0x80c,*(undefined4 *)(param_1 + 0x14),DAT_00a14058);
    DAT_00a14058 = -1;
  }
  return;
}


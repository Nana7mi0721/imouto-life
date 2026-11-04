
void __fastcall FUN_005fef90(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (*DAT_00aba168)();
  iVar2 = (iVar2 - *(int *)(param_1 + 0xfc)) * 10000;
  if ((iVar2 < *(int *)(param_1 + 0xf4) * 2) || (iVar2 < *(int *)(param_1 + 0xf8) * 2)) {
    iVar1 = iVar2 + *(int *)(param_1 + 0xf4) * 3;
    *(int *)(param_1 + 0xf4) = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
  }
  *(int *)(param_1 + 0xf8) = iVar2;
  FUN_005feef0();
  return;
}


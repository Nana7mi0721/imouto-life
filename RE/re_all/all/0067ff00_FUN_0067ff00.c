
void FUN_0067ff00(int param_1)

{
  int iVar1;
  
  FUN_0067ff70(param_1,param_1 + 0x94,*(undefined4 *)(param_1 + 0xb1c));
  FUN_0067ff70(param_1,param_1 + 0x988,*(undefined4 *)(param_1 + 0xb28));
  FUN_0067f930(param_1,param_1 + 0xb30);
  iVar1 = 0x12;
  do {
    if (*(short *)(param_1 + 0xa7e + (uint)(byte)(&DAT_00821d58)[iVar1] * 4) != 0) break;
    iVar1 = iVar1 + -1;
  } while (2 < iVar1);
  *(int *)(param_1 + 0x16a8) = *(int *)(param_1 + 0x16a8) + iVar1 * 3 + 0x11;
  return;
}


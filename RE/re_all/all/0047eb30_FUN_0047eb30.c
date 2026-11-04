
undefined1 __thiscall FUN_0047eb30(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (((*(char *)(param_1 + 0x1894) == '\0') &&
      ((param_2 < 0 || (iVar1 = FUN_0047a490(), iVar1 * 2 + -1 <= param_2)))) ||
     ((*(char *)(param_1 + 0x1895) == '\0' &&
      ((param_3 < 0 || (iVar1 = FUN_0047a4b0(), iVar1 * 2 <= param_3)))))) {
    return 0;
  }
  return 1;
}


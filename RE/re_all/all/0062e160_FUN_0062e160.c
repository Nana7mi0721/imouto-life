
void __thiscall FUN_0062e160(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
      if ((((*(int *)(iVar1 + 0xe8) == 2) && (iVar1 != 0)) && (*(int *)(iVar1 + 0xd4) != 2)) &&
         ((*(uint *)(iVar1 + 200) >> 1 & 1) != 0)) {
        FUN_0063b850(param_2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
  }
  return;
}


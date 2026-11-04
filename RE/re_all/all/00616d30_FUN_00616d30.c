
int __thiscall FUN_00616d30(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x29c);
  if (iVar1 == 4) {
    iVar1 = FUN_00616900(param_2);
    iVar2 = *(int *)(param_1 + 0x70 + iVar1 * 0xa4);
    if ((iVar2 != 0) && (DAT_00f3f3e0 != (code *)0x0)) {
      (*DAT_00f3f3e0)(iVar2);
      *(undefined4 *)(param_1 + iVar1 * 0xa4 + 0x70) = 0;
    }
  }
  else {
    *(int *)(param_1 + 0x29c) = iVar1 + 1;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  puVar3 = (undefined4 *)(param_1 + 4 + iVar1 * 0xa4);
  for (iVar2 = 0x29; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  return iVar1;
}


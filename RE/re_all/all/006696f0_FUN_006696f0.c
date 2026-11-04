
undefined1 FUN_006696f0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (iVar3 = *(int *)(param_1 + 600), iVar3 == 0))
  {
    return 0;
  }
  iVar2 = *(uint *)(param_1 + 0x25c) + iVar3 * 4;
  uVar4 = iVar3 + -5 + iVar2;
  if (*param_2 != *(int *)(iVar3 + -5 + iVar2)) {
    do {
      if (uVar4 <= *(uint *)(param_1 + 0x25c)) {
        return 0;
      }
      piVar1 = (int *)(uVar4 - 5);
      uVar4 = uVar4 - 5;
    } while (*param_2 != *piVar1);
  }
  return *(undefined1 *)(uVar4 + 4);
}



undefined4 FUN_005517a0(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  FUN_0057e620(param_1);
  iVar1 = param_1[0x13];
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -1;
    if ((*(int *)(iVar1 + 0xc) < 1) && (-1 < *(int *)(iVar1 + 0xc))) {
      FUN_0056e1d0(iVar1);
    }
    param_1[0x13] = 0;
  }
  *param_1 = 0;
  return 0;
}


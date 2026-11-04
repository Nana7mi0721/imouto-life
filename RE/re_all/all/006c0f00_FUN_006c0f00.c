
int FUN_006c0f00(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 2;
    iVar1 = FUN_006c1190(param_1);
    if (iVar1 < 0) goto LAB_006c0f3e;
  }
  *(undefined4 *)(param_1 + 0x5c) = 3;
  iVar1 = FUN_006c0f60(param_1);
  if (-1 < iVar1) {
    return 0;
  }
LAB_006c0f3e:
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_006c0080(param_1);
  return iVar1;
}


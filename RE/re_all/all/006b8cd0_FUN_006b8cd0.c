
undefined4 FUN_006b8cd0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  int local_4;
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) ||
     (iVar1 = *(int *)(*param_1 + 0x3c), iVar1 == 0)) {
    return 0xffffffff;
  }
  iVar1 = FUN_006b9780(*(undefined4 *)(iVar1 + 8),param_2,&local_8);
  if (iVar1 < 0) {
    return 0xffffffe8;
  }
  param_1[2] = local_8;
  param_1[3] = local_4;
  return 0;
}



undefined4 FUN_00608520(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_00602330(*(int *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (param_2 == 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffff7;
    return 0;
  }
  iVar1 = FUN_005fce60(param_2);
  *(int *)(param_1 + 0x3c) = iVar1;
  if (iVar1 == 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffff7;
    return 0x8007000e;
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
  return 0;
}


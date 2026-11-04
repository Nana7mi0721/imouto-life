
undefined4 FUN_005bb490(float param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_00ef1b8c + 8);
  if ((param_1 != *(float *)(iVar1 + 0xe0)) || (DAT_00ef7324 != 0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    *(float *)(iVar1 + 0xe0) = param_1;
    *(float *)(iVar1 + 0xe4) = param_1;
    *(float *)(iVar1 + 0xe8) = param_1;
    *(float *)(iVar1 + 0xec) = param_1;
    *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
  }
  return 0;
}


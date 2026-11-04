
undefined4 FUN_005b93f0(undefined4 *param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_00ef1b8c + 8);
  *(undefined4 *)(iVar1 + 0xb0) = *param_1;
  *(undefined4 *)(iVar1 + 0xb4) = param_1[4];
  *(undefined4 *)(iVar1 + 0xb8) = param_1[8];
  *(undefined4 *)(iVar1 + 0xbc) = param_1[0xc];
  *(undefined4 *)(iVar1 + 0xc0) = param_1[1];
  *(undefined4 *)(iVar1 + 0xc4) = param_1[5];
  *(undefined4 *)(iVar1 + 200) = param_1[9];
  *(undefined4 *)(iVar1 + 0xcc) = param_1[0xd];
  *(undefined4 *)(iVar1 + 0xd0) = param_1[2];
  *(undefined4 *)(iVar1 + 0xd4) = param_1[6];
  *(undefined4 *)(iVar1 + 0xd8) = param_1[10];
  *(undefined4 *)(iVar1 + 0xdc) = param_1[0xe];
  *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
  return 0;
}


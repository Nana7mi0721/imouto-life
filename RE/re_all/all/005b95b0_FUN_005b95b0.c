
undefined4 FUN_005b95b0(undefined4 *param_1)

{
  int iVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(DAT_00ef1b8c + 8);
  *(undefined4 *)(iVar1 + 0x40) = *param_1;
  *(undefined4 *)(iVar1 + 0x44) = param_1[4];
  *(undefined4 *)(iVar1 + 0x48) = param_1[8];
  *(undefined4 *)(iVar1 + 0x4c) = param_1[0xc];
  *(undefined4 *)(iVar1 + 0x50) = param_1[1];
  *(undefined4 *)(iVar1 + 0x54) = param_1[5];
  *(undefined4 *)(iVar1 + 0x58) = param_1[9];
  *(undefined4 *)(iVar1 + 0x5c) = param_1[0xd];
  *(undefined4 *)(iVar1 + 0x60) = param_1[2];
  *(undefined4 *)(iVar1 + 100) = param_1[6];
  *(undefined4 *)(iVar1 + 0x68) = param_1[10];
  *(undefined4 *)(iVar1 + 0x6c) = param_1[0xe];
  *(undefined4 *)(iVar1 + 0x70) = param_1[3];
  *(undefined4 *)(iVar1 + 0x74) = param_1[7];
  *(undefined4 *)(iVar1 + 0x78) = param_1[0xb];
  *(undefined4 *)(iVar1 + 0x7c) = param_1[0xf];
  *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
  return 0;
}


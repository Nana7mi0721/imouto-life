
undefined4 FUN_005b9640(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  puVar1 = *(undefined4 **)(DAT_00ef1b8c + 8);
  *puVar1 = *param_1;
  puVar1[1] = param_1[4];
  puVar1[2] = param_1[8];
  puVar1[3] = param_1[0xc];
  puVar1[4] = param_1[1];
  puVar1[5] = param_1[5];
  puVar1[6] = param_1[9];
  puVar1[7] = param_1[0xd];
  puVar1[8] = param_1[2];
  puVar1[9] = param_1[6];
  puVar1[10] = param_1[10];
  puVar1[0xb] = param_1[0xe];
  puVar1[0xc] = param_1[3];
  puVar1[0xd] = param_1[7];
  puVar1[0xe] = param_1[0xb];
  puVar1[0xf] = param_1[0xf];
  *(undefined4 *)(DAT_00ef1b8c + 0xc) = 1;
  return 0;
}



undefined4 FUN_00585710(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  *param_1 = local_40[0];
  param_1[1] = local_30;
  param_1[2] = local_20;
  param_1[3] = local_10;
  param_1[4] = local_40[1];
  param_1[5] = local_2c;
  param_1[6] = local_1c;
  param_1[7] = local_c;
  param_1[8] = local_40[2];
  param_1[9] = local_28;
  param_1[10] = local_18;
  param_1[0xb] = local_8;
  param_1[0xc] = local_40[3];
  param_1[0xd] = local_24;
  param_1[0xe] = local_14;
  param_1[0xf] = local_4;
  return 0;
}


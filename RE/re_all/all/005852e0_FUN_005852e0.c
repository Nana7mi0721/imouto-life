
undefined4 FUN_005852e0(undefined4 *param_1,double *param_2,double *param_3)

{
  int iVar1;
  double *pdVar2;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  local_88 = param_2[3] * param_3[0xc] +
             param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  local_80 = param_3[0xd] * param_2[3] +
             param_3[9] * param_2[2] + param_3[1] * *param_2 + param_3[5] * param_2[1];
  local_78 = param_3[0xe] * param_2[3] +
             param_2[2] * param_3[10] + *param_2 * param_3[2] + param_2[1] * param_3[6];
  local_70 = param_2[3] * param_3[0xf] +
             param_2[2] * param_3[0xb] + param_3[3] * *param_2 + param_3[7] * param_2[1];
  local_68 = param_3[0xc] * param_2[7] +
             param_2[6] * param_3[8] + param_2[5] * param_3[4] + param_2[4] * *param_3;
  local_60 = param_3[0xd] * param_2[7] +
             param_2[6] * param_3[9] + param_2[4] * param_3[1] + param_2[5] * param_3[5];
  local_58 = param_3[0xe] * param_2[7] +
             param_2[6] * param_3[10] + param_2[4] * param_3[2] + param_2[5] * param_3[6];
  local_50 = param_3[0xf] * param_2[7] +
             param_2[6] * param_3[0xb] + param_3[3] * param_2[4] + param_3[7] * param_2[5];
  local_48 = param_3[0xc] * param_2[0xb] +
             param_2[10] * param_3[8] + param_2[9] * param_3[4] + param_2[8] * *param_3;
  local_40 = param_3[0xd] * param_2[0xb] +
             param_2[10] * param_3[9] + param_2[8] * param_3[1] + param_2[9] * param_3[5];
  local_38 = param_3[0xe] * param_2[0xb] +
             param_2[10] * param_3[10] + param_2[8] * param_3[2] + param_2[9] * param_3[6];
  local_30 = param_3[0xf] * param_2[0xb] +
             param_2[10] * param_3[0xb] + param_3[3] * param_2[8] + param_3[7] * param_2[9];
  local_28 = param_3[0xc] * param_2[0xf] +
             param_2[0xe] * param_3[8] + param_2[0xd] * param_3[4] + param_2[0xc] * *param_3;
  local_20 = param_3[0xd] * param_2[0xf] +
             param_2[0xe] * param_3[9] + param_2[0xc] * param_3[1] + param_2[0xd] * param_3[5];
  local_18 = param_3[0xe] * param_2[0xf] +
             param_2[0xe] * param_3[10] + param_2[0xc] * param_3[2] + param_2[0xd] * param_3[6];
  local_10 = param_3[0xf] * param_2[0xf] +
             param_2[0xe] * param_3[0xb] + param_3[3] * param_2[0xc] + param_3[7] * param_2[0xd];
  if (param_1 != (undefined4 *)0x0) {
    pdVar2 = &local_88;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *(undefined4 *)pdVar2;
      pdVar2 = (double *)((int)pdVar2 + 4);
      param_1 = param_1 + 1;
    }
  }
  return 0;
}


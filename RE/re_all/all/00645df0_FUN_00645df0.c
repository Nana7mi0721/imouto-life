
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00645df0(undefined4 param_1,int param_2,float *param_3,float *param_4)

{
  int iVar1;
  float fVar2;
  float10 fVar3;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_64 [25];
  
  fVar3 = (float10)FUN_0063cea0(1,0,2,1);
  local_94 = (float)fVar3;
  fVar3 = (float10)FUN_0063cea0(1,2,2,0);
  local_88 = (float)fVar3;
  fVar3 = (float10)FUN_0063cea0(1,1,2,2);
  local_6c = (float)fVar3;
  FUN_005fc500(&local_6c,&local_88,&local_94);
  fVar3 = (float10)FUN_005fcc30(&local_d0);
  local_d4 = (float)((float10)_DAT_00804108 / fVar3);
  fVar3 = (float10)FUN_0063cea0(0,0,1,1);
  local_b4 = (float)(fVar3 * (float10)local_d4);
  fVar3 = (float10)FUN_0063cea0(0,1,2,0);
  local_8c = (float)(fVar3 * (float10)local_d4);
  local_ac = local_c8 * local_d4;
  fVar3 = (float10)FUN_0063cea0(0,2,1,0);
  local_64[0] = (float)(fVar3 * (float10)local_d4);
  fVar3 = (float10)FUN_0063cea0(0,0,2,2);
  local_a4 = (float)(fVar3 * (float10)local_d4);
  local_84 = local_cc * local_d4;
  fVar3 = (float10)FUN_0063cea0(0,1,1,2);
  local_9c = (float)(fVar3 * (float10)local_d4);
  fVar3 = (float10)FUN_0063cea0(0,2,2,1);
  local_68 = (float)(fVar3 * (float10)local_d4);
  local_bc = local_d0 * local_d4;
  FUN_005fcc50(&local_bc,&local_68,&local_9c,&local_84,&local_a4,local_64,&local_ac,&local_8c,
               &local_b4);
  iVar1 = param_2 + 0x20;
  fVar3 = (float10)FUN_005fccf0(iVar1);
  local_d4 = (float)fVar3;
  fVar3 = (float10)FUN_005fccd0(iVar1);
  local_70 = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(iVar1);
  local_b8 = (float)fVar3;
  iVar1 = param_2 + 0x10;
  fVar3 = (float10)FUN_005fccf0(iVar1);
  local_b0 = (float)fVar3;
  fVar3 = (float10)FUN_005fccd0(iVar1);
  local_a8 = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(iVar1);
  local_a0 = (float)fVar3;
  fVar3 = (float10)FUN_005fccf0(param_2);
  local_98 = (float)fVar3;
  fVar3 = (float10)FUN_005fccd0(param_2);
  local_90 = (float)fVar3;
  fVar3 = (float10)FUN_005fccb0(param_2);
  local_c0 = (float)fVar3;
  FUN_005fcc50(&local_c0,&local_90,&local_98,&local_a0,&local_a8,&local_b0,&local_b8,&local_70,
               &local_d4);
  FUN_0061abb0(&local_80);
  fVar3 = (float10)FUN_0061a2f0(&local_80);
  local_c0 = (float)((float10)_DAT_00804108 / SQRT(fVar3));
  FUN_0061a880(&local_c0);
  fVar3 = (float10)FUN_006c5580();
  *param_4 = (float)(fVar3 + fVar3);
  *param_3 = local_80;
  param_3[1] = local_7c;
  param_3[2] = local_78;
  param_3[3] = 0.0;
  param_3[3] = 0.0;
  fVar2 = param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3;
  if (fVar2 < _DAT_0080410c) {
    *param_3 = 1.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    param_3[3] = 0.0;
    return;
  }
  fVar2 = _DAT_00804108 / SQRT(fVar2);
  *param_3 = fVar2 * *param_3;
  param_3[1] = fVar2 * param_3[1];
  param_3[2] = fVar2 * param_3[2];
  return;
}


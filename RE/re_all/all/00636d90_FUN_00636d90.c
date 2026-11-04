
void FUN_00636d90(float *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  undefined4 uVar8;
  float local_3c;
  float local_38;
  float *local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined1 local_20 [4];
  float local_1c;
  float local_18;
  undefined1 local_10 [16];
  
  pfVar7 = param_3;
  pfVar6 = param_2;
  pfVar5 = param_1;
  local_34 = param_2 + 4;
  fVar3 = ((param_3[0x1d] - param_3[0x1e] * param_3[0x15]) -
          (param_1[4] * *param_3 +
          param_3[4] * *param_1 +
          param_1[5] * param_3[1] +
          param_1[6] * param_3[2] + param_3[5] * param_1[1] + param_3[6] * param_1[2]) *
          param_3[0x17]) -
          (param_3[8] * *local_34 +
          ((param_2[5] * param_3[9] +
           ((param_2[6] * param_3[10] - param_3[6] * param_2[2]) - param_3[5] * param_2[1])) -
          param_3[4] * *param_2)) * param_3[0x17];
  fVar4 = fVar3 + param_3[0x15];
  if (param_3[0x1f] <= fVar4) {
    param_3[0x15] = fVar4;
    param_3 = (float *)fVar3;
  }
  else {
    fVar3 = param_3[0x15];
    param_3[0x15] = param_3[0x1f];
    param_3 = (float *)(param_3[0x1f] - fVar3);
  }
  pfVar1 = param_1 + 0xc;
  pfVar2 = param_1 + 0xd;
  param_1 = (float *)(pfVar7[6] * param_1[0xe] * (float)param_3);
  local_38 = (float)param_3;
  param_2 = (float *)(pfVar7[5] * *pfVar2 * (float)param_3);
  local_3c = pfVar7[4] * *pfVar1 * (float)param_3;
  FUN_005fc500(&local_3c,&param_2,&param_1);
  FUN_00612f50(local_20);
  FUN_0060fe40(local_20,pfVar5 + 8,&local_38);
  uVar8 = FUN_005fc560(&local_30,pfVar7 + 0xc,local_20);
  FUN_00612f50(uVar8);
  local_1c = -pfVar7[5];
  local_18 = -pfVar7[6];
  local_30 = -pfVar7[4] * pfVar6[0xc];
  local_2c = local_1c * pfVar6[0xd];
  local_24 = 0;
  local_28 = local_18 * pfVar6[0xe];
  uVar8 = FUN_0060fe40(local_20,&local_30,&param_3);
  FUN_00612f50(uVar8);
  FUN_0060fe40(local_20,pfVar6 + 8,&param_3);
  uVar8 = FUN_005fc560(local_10,pfVar7 + 0x10,local_20);
  FUN_00612f50(uVar8);
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00636f70(int param_1,float param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 uVar5;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  float local_c;
  float local_8;
  
  pfVar4 = param_3;
  fVar3 = param_2;
  if (param_3[0x21] != _DAT_007d5344) {
    DAT_00f3f814 = DAT_00f3f814 + 1;
    fVar1 = ((param_3[0x21] - param_3[0x1e] * param_3[0x14]) -
            (*(float *)(param_1 + 0x58) * *param_3 +
            *(float *)(param_1 + 0x48) * param_3[4] +
            *(float *)(param_1 + 0x5c) * param_3[1] +
            *(float *)(param_1 + 0x60) * param_3[2] +
            *(float *)(param_1 + 0x4c) * param_3[5] + *(float *)(param_1 + 0x50) * param_3[6]) *
            param_3[0x17]) -
            (*(float *)((int)param_2 + 0x58) * param_3[8] +
            ((*(float *)((int)param_2 + 0x5c) * param_3[9] +
             ((*(float *)((int)param_2 + 0x60) * param_3[10] -
              *(float *)((int)param_2 + 0x50) * param_3[6]) -
             *(float *)((int)param_2 + 0x4c) * param_3[5])) -
            param_3[4] * *(float *)((int)param_2 + 0x48))) * param_3[0x17];
    fVar2 = fVar1 + param_3[0x14];
    if (param_3[0x1f] <= fVar2) {
      param_3[0x14] = fVar2;
      param_3 = (float *)fVar1;
    }
    else {
      fVar1 = param_3[0x14];
      param_3[0x14] = param_3[0x1f];
      param_3 = (float *)(param_3[0x1f] - fVar1);
    }
    local_24 = (float)param_3;
    if (*(int *)(param_1 + 0x44) != 0) {
      param_2 = pfVar4[6] * *(float *)(param_1 + 0x38) * (float)param_3;
      local_2c = pfVar4[5] * *(float *)(param_1 + 0x34) * (float)param_3;
      local_28 = pfVar4[4] * *(float *)(param_1 + 0x30) * (float)param_3;
      FUN_005fc500(&local_28,&local_2c,&param_2);
      FUN_00612f50(local_10);
      FUN_0060fe40(local_10,param_1 + 0x20,&local_24);
      uVar5 = FUN_005fc560(&local_20,pfVar4 + 0xc,local_10);
      FUN_00612f50(uVar5);
    }
    local_c = -pfVar4[5];
    local_8 = -pfVar4[6];
    local_20 = -pfVar4[4] * *(float *)((int)fVar3 + 0x30);
    local_1c = local_c * *(float *)((int)fVar3 + 0x34);
    local_14 = 0;
    local_18 = local_8 * *(float *)((int)fVar3 + 0x38);
    FUN_0063aab0(&local_20,pfVar4 + 0x10,param_3);
  }
  return;
}


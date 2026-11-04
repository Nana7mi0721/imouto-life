
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00626d70(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 uVar5;
  float *pfVar6;
  float10 fVar7;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float fStack_50;
  float fStack_4c;
  float afStack_48 [6];
  undefined1 local_30 [16];
  undefined1 local_20 [8];
  undefined1 auStack_18 [24];
  
  pfVar4 = param_3;
  fVar3 = _DAT_00804108 /
          SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *param_3 = fVar3 * *param_2;
  param_3[1] = fVar3 * fVar1;
  local_54 = 0;
  param_3[2] = fVar3 * fVar2;
  param_3[3] = 0.0;
  local_60 = -*param_3;
  local_5c = -param_3[1];
  local_58 = -param_3[2];
  fVar7 = (float10)FUN_005fcc30(&local_60);
  param_2 = (float *)(float)fVar7;
  fVar7 = (float10)FUN_005fcc30(&local_60);
  param_3 = (float *)(float)fVar7;
  fVar7 = (float10)FUN_005fcc30(&local_60);
  local_64 = (float)fVar7;
  FUN_005fc500(&local_64,&param_3,&param_2);
  uVar5 = (**(code **)(param_1 + 0x78))(local_20,local_30);
  FUN_005fc8d0(afStack_48,uVar5);
  pfVar6 = (float *)(**(code **)(param_1 + 0x78))(auStack_18,pfVar4);
  fVar1 = pfVar6[1];
  fVar2 = pfVar6[2];
  pfVar4[4] = *pfVar6 - fStack_50;
  pfVar4[5] = fVar1 - fStack_4c;
  pfVar4[6] = fVar2 - afStack_48[0];
  pfVar4[7] = 0.0;
  return;
}


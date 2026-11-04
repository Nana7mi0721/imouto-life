
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00528360(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  uint uVar9;
  float10 fVar10;
  undefined1 local_84;
  undefined1 local_70;
  undefined1 local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (((int)param_5 < 1) || (param_5 == 1)) {
    uVar8 = FUN_005287d0(param_1,param_2,param_3,param_4);
    return uVar8;
  }
  if (param_1 == param_3) {
    uVar9 = param_5 & 0x80000001;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
    }
    if (uVar9 == 1) {
      param_1 = param_1 - (int)param_5 / 2;
      uVar8 = FUN_0051d7b0(param_1,param_2,param_1 + param_5,param_4);
      return uVar8;
    }
  }
  if (param_2 == param_4) {
    uVar9 = param_5 & 0x80000001;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
    }
    if (uVar9 == 1) {
      param_2 = param_2 - (int)param_5 / 2;
      uVar8 = FUN_0051d7b0(param_1,param_2,param_3,param_2 + param_5);
      return uVar8;
    }
  }
  if (DAT_00a37d78 == 0) {
    fVar2 = (float)(param_4 - param_2);
    fVar3 = (float)(param_1 - param_3);
    fVar10 = (float10)FUN_0056d670(fVar2 * fVar2 + fVar3 * fVar3);
    fVar1 = (float)((float10)(int)param_5 * (float10)_DAT_00804a60 * ((float10)1 / fVar10));
    fVar2 = fVar1 * fVar2;
    fVar1 = fVar1 * fVar3;
    FUN_0050e270((float)param_2 - fVar1,1);
    FUN_0050e270((float)param_1 - fVar2);
    uVar8 = FUN_0050e270((float)param_4 - fVar1);
    uVar8 = FUN_0050e270((float)param_3 - fVar2,uVar8);
    uVar8 = FUN_0050e270((float)param_4 + fVar1,uVar8);
    uVar8 = FUN_0050e270((float)param_3 + fVar2,uVar8);
    FUN_0050e270((float)param_2 + fVar1,uVar8);
    uVar8 = FUN_0050e270((float)param_1 + fVar2);
    FUN_0051d610(uVar8);
    return 0;
  }
  fVar2 = (float)param_1;
  fVar3 = (float)param_2;
  fVar4 = (float)param_3;
  fVar5 = (float)param_4;
  fVar6 = fVar5 - fVar3;
  fVar7 = -(fVar4 - fVar2);
  fVar10 = (float10)FUN_0056d670(fVar6 * fVar6 + fVar7 * fVar7);
  fVar1 = (float)((float10)(int)param_5 * (float10)_DAT_00804a60 * ((float10)1 / fVar10));
  fVar6 = fVar1 * fVar6;
  fVar1 = fVar1 * fVar7;
  FUN_00544000();
  local_48 = 0;
  local_44 = 0;
  local_50 = fVar2 + fVar6;
  local_40 = CONCAT13(0xff,CONCAT21(CONCAT11(local_54,local_70),local_84));
  local_c = 0;
  local_8 = 0;
  local_4 = local_40;
  local_20 = 0;
  local_1c = 0;
  local_18 = local_40;
  local_34 = 0;
  local_30 = 0;
  local_2c = local_40;
  local_4c = fVar3 + fVar1;
  local_3c = fVar4 + fVar6;
  local_38 = fVar5 + fVar1;
  local_28 = fVar2 - fVar6;
  local_24 = fVar3 - fVar1;
  local_14 = fVar4 - fVar6;
  local_10 = fVar5 - fVar1;
  FUN_00520930(&local_50,4,5,0xfffffffb,0,0);
  return 0;
}


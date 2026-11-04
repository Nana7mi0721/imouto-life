
void FUN_005df960(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
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
  
  iVar2 = param_2;
  iVar1 = *(int *)(param_2 + 8);
  local_44 = *(undefined4 *)(iVar1 + 0x180);
  local_40 = *(undefined4 *)(iVar1 + 0x184);
  local_3c = *(undefined4 *)(iVar1 + 0x188);
  local_38 = 0x3f800000;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0;
  local_10 = 0;
  local_30 = 0;
  local_8 = 0;
  local_28 = 0;
  local_14 = 0;
  local_c = 0;
  local_34 = 0;
  local_2c = 0;
  DAT_00a38de4 = 1;
  DAT_00e39a00 = 1;
  FUN_005a7a00(&local_44);
  local_54 = param_3;
  local_50 = param_3;
  local_4c = param_3;
  local_48 = param_3;
  FUN_0059cb80(&DAT_00ddb600,0,2,0x2a,&local_54,1,0);
  FUN_0059a970(2);
  *param_1 = *(undefined4 *)(iVar1 + 400);
  param_1[2] = *(undefined4 *)(iVar1 + 0x194);
  param_1[1] = *(undefined4 *)(iVar1 + 0x198);
  param_2 = *(int *)(param_2 + 0xb4);
  if (param_2 == -1) {
    param_2 = *(int *)(iVar1 + 0x1a0);
  }
  param_1[5] = (int)ROUND(*(float *)(iVar2 + 0xa0) * (float)param_2) << 0x18 | 0xffffff;
  iVar2 = *(int *)(iVar2 + 0xb0);
  if (iVar2 == -1) {
    iVar2 = *(int *)(iVar1 + 0x19c);
  }
  switch(iVar2) {
  case 0:
    param_1[3] = 0;
    param_1[6] = DAT_00e796a8;
    param_1[7] = DAT_00e796ac;
    param_1[8] = DAT_00e796b0;
    goto switchD_005dface_caseD_3;
  case 1:
  case 10:
    param_1[6] = 5;
    param_1[7] = 6;
    break;
  case 2:
    param_1[6] = 5;
    param_1[7] = 2;
    break;
  default:
    goto switchD_005dface_caseD_3;
  case 4:
  case 0xb:
    param_1[6] = 1;
    param_1[7] = 3;
  }
  param_1[8] = 1;
  param_1[3] = 1;
switchD_005dface_caseD_3:
  param_1[0xc] = 1;
  FUN_0059a900(0);
  FUN_0059b2b0(0);
  return;
}


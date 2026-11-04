
int FUN_006b6f00(int param_1,int param_2,int param_3,int param_4,float *param_5,int param_6,
                int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar1 = (int *)param_5;
  piVar5 = (int *)param_5;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar3 = 0;
  iVar4 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  *param_5 = (float)param_3;
  param_5[1] = (float)param_4;
  if (param_6 <= param_4) {
    param_4 = param_6 + -1;
  }
  if (param_3 <= param_4) {
    param_5 = (float *)(param_1 + param_3 * 4);
    do {
      iVar2 = FUN_006b70a0(param_5);
      if (iVar2 != 0) {
        if (*(float *)((param_2 - param_1) + (int)param_5) + *(float *)(param_7 + 0x458) < *param_5)
        {
          local_14 = local_14 + iVar2;
          iVar4 = iVar4 + param_3;
          local_10 = local_10 + param_3 * param_3;
          local_c = local_c + iVar2 * iVar2;
          local_8 = local_8 + iVar2 * param_3;
          local_4 = local_4 + 1;
        }
        else {
          local_24 = local_24 + iVar2;
          local_28 = local_28 + param_3;
          local_20 = local_20 + param_3 * param_3;
          local_1c = local_1c + iVar2 * iVar2;
          local_18 = local_18 + iVar2 * param_3;
          iVar3 = iVar3 + 1;
        }
      }
      param_3 = param_3 + 1;
      param_5 = param_5 + 1;
    } while (param_3 <= param_4);
  }
  piVar1[2] = local_28;
  piVar1[3] = local_24;
  piVar1[4] = local_20;
  piVar1[5] = local_1c;
  piVar1[6] = local_18;
  piVar1[9] = local_14;
  piVar1[10] = local_10;
  piVar1[7] = iVar3;
  piVar1[8] = iVar4;
  piVar1[0xb] = local_c;
  piVar1[0xc] = local_8;
  piVar1[0xd] = local_4;
  return iVar3;
}


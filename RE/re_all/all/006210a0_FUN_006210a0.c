
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_006210a0(int *param_1,float *param_2,float *param_3,float *param_4,float param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  
  if ((((*param_2 <= *param_3) && (param_2[1] <= param_3[1])) && (param_2[2] <= param_3[2])) &&
     ((param_3[4] <= param_2[4] && (param_3[5] <= param_2[5])))) {
    if (param_3[6] <= param_2[6]) {
      return 0;
    }
  }
  *param_3 = *param_3 - param_5;
  param_3[1] = param_3[1] - param_5;
  param_3[2] = param_3[2] - param_5;
  param_3[4] = param_5 + param_3[4];
  param_3[5] = param_5 + param_3[5];
  param_3[6] = param_5 + param_3[6];
  if (*param_4 <= _DAT_007d5344) {
    *param_3 = *param_3 + *param_4;
  }
  else {
    param_3[4] = *param_4 + param_3[4];
  }
  if (param_4[1] <= _DAT_007d5344) {
    param_3[1] = param_3[1] + param_4[1];
  }
  else {
    param_3[5] = param_3[5] + param_4[1];
  }
  if (param_4[2] <= _DAT_007d5344) {
    param_3[2] = param_4[2] + param_3[2];
  }
  else {
    param_3[6] = param_3[6] + param_4[2];
  }
  iVar2 = FUN_00620e10(param_1,param_2);
  if (iVar2 != 0) {
    iVar3 = param_1[2];
    if (iVar3 < 0) {
      iVar2 = *param_1;
    }
    else {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          iVar1 = *(int *)(iVar2 + 0x20);
          if (iVar1 == 0) break;
          iVar4 = iVar4 + 1;
          iVar2 = iVar1;
        } while (iVar4 < iVar3);
      }
    }
  }
  pfVar5 = param_2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *param_3;
    param_3 = param_3 + 1;
    pfVar5 = pfVar5 + 1;
  }
  FUN_00620c20(param_1,iVar2,param_2);
  return 1;
}


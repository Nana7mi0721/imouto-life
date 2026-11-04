
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007997a0(int param_1,float *param_2,int param_3,int param_4,int param_5,float *param_6,
                 int param_7)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int local_8;
  
  if (0 < param_5) {
    local_8 = param_5;
    pfVar2 = param_2;
    do {
      if (0 < param_4) {
        pfVar3 = pfVar2;
        iVar4 = param_4;
        pfVar5 = param_6;
        do {
          fVar1 = *pfVar5 * *pfVar5;
          pfVar5 = pfVar5 + (int)(48000 / (longlong)param_7);
          *(float *)((param_3 - (int)param_2) + (int)pfVar3) =
               *pfVar3 * fVar1 +
               (_DAT_00804108 - fVar1) * *(float *)((param_1 - (int)param_2) + (int)pfVar3);
          pfVar3 = pfVar3 + param_5;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      pfVar2 = pfVar2 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}


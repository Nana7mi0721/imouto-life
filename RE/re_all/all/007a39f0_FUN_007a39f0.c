
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_007a39f0(int *param_1,float *param_2,float *param_3,undefined4 param_4,float *param_5)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  
  iVar1 = *param_1;
  iVar2 = param_1[6];
  iVar4 = 0;
  pfVar5 = param_2;
  do {
    iVar6 = 0;
    if (7 < param_1[7]) {
      if (iVar1 == 0) {
        iVar6 = FUN_007a2250(iVar2,1);
      }
      else if (_DAT_007d5344 <= *pfVar5) {
        iVar6 = 0;
        FUN_007a25b0(iVar2,0,1);
      }
      else {
        iVar6 = 1;
        FUN_007a25b0(iVar2,1,1);
      }
      param_1[7] = param_1[7] + -8;
    }
    if (iVar1 == 0) {
      if (iVar6 == 0) {
        fVar3 = _DAT_00804108;
      }
      else {
        fVar3 = _DAT_007d5340;
      }
      *pfVar5 = fVar3;
    }
    iVar4 = iVar4 + 1;
    pfVar5 = param_3;
  } while (iVar4 < (int)((param_3 != (float *)0x0) + 1));
  if (param_5 != (float *)0x0) {
    *param_5 = *param_2;
  }
  return 1;
}


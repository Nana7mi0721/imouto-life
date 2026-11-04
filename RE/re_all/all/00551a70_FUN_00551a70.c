
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00551a70(int *param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  int iVar5;
  float10 fVar6;
  
  uVar1 = _DAT_007d52d8;
  if (*param_1 != 0) {
    if (DAT_00a83c64 != 0) {
      iVar5 = param_1[2];
      fVar2 = (float)_DAT_00829840;
      if (iVar5 < -9999) {
        param_1[0x19] = 0;
      }
      else if (iVar5 < 0) {
        dVar4 = _DAT_008053a0;
        if (DAT_00a83c58 != 0) {
          dVar4 = _DAT_0081ec08;
        }
        fVar6 = (float10)FUN_0056d500(_DAT_007d52d8,((float)iVar5 / (float)dVar4) / fVar2);
        iVar5 = FUN_0050e240((double)((fVar6 / (float10)_DAT_007d6148) * (float10)_DAT_008052e8));
        fVar2 = (float)_DAT_00829840;
        param_1[0x19] = iVar5;
        uVar1 = _DAT_007d52d8;
      }
      else {
        param_1[0x19] = 0x100;
      }
      iVar5 = param_1[1];
      if (iVar5 == -10000) {
        param_1[0x18] = -0x100;
        return 0;
      }
      if (iVar5 == 10000) {
        param_1[0x18] = 0x100;
        return 0;
      }
      if (iVar5 == 0) {
        param_1[0x18] = 0;
        return 0;
      }
      if (DAT_00a83c58 == 0) {
        if (iVar5 < 0) {
          iVar5 = -iVar5;
        }
        fVar3 = (float)-iVar5 / (float)_DAT_008053a0;
      }
      else {
        if (iVar5 < 0) {
          iVar5 = -iVar5;
        }
        fVar3 = (float)-iVar5 / (float)_DAT_0081ec08;
      }
      fVar6 = (float10)FUN_0056d500(uVar1,fVar3 / fVar2);
      iVar5 = FUN_0050e240((double)((fVar6 / (float10)_DAT_007d6148) * (float10)_DAT_008052e8));
      if (param_1[1] < 0) {
        iVar5 = -iVar5;
      }
      param_1[0x18] = iVar5;
      return 0;
    }
    iVar5 = FUN_0057ea30();
    if (-1 < iVar5) {
      return 0;
    }
  }
  return 0xffffffff;
}


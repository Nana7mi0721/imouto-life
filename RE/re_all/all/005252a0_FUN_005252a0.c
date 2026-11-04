
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005252a0(float param_1,float param_2,float param_3,float param_4,int param_5,float param_6,
            double param_7,float param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int unaff_ESI;
  uint uVar10;
  bool bVar11;
  float10 fVar12;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar9 = (int)param_3;
  iVar1 = (int)param_2;
  local_2c = (float)param_7;
  dVar5 = (double)CONCAT44(param_9,param_8);
  if (local_2c <= 0.0) {
    param_7 = _DAT_00804678;
  }
  if ((int)param_3 < (int)param_1) {
    param_3 = param_1;
    param_1 = (float)iVar9;
  }
  iVar9 = (int)param_4;
  if ((int)param_4 < (int)param_2) {
    param_2 = param_4;
    iVar9 = iVar1;
  }
  iVar1 = *(int *)(unaff_ESI + 0x60);
  iVar7 = (int)param_6 % *(int *)(unaff_ESI + 100);
  FUN_0056d4d0((float)dVar5,&param_8,&param_6);
  local_14 = local_2c * (float)*(int *)(unaff_ESI + 0x60) * param_6;
  local_18 = (float)*(int *)(unaff_ESI + 100) * param_8 * local_2c;
  FUN_0056d4d0((float)dVar5 + (float)_DAT_007d56b8,&local_34,&local_30);
  local_28 = local_2c * (float)*(int *)(unaff_ESI + 0x60) * local_30;
  local_24 = (float)*(int *)(unaff_ESI + 100) * local_34 * local_2c;
  local_20 = (float)((int)param_3 - (int)param_1);
  local_1c = (float)(iVar9 - (int)param_2);
  fVar12 = (float10)FUN_0056d670(local_20 * local_20 + local_1c * local_1c);
  param_4 = (float)*(int *)(unaff_ESI + 100);
  if (*(int *)(unaff_ESI + 0x60) <= *(int *)(unaff_ESI + 100)) {
    param_4 = (float)*(int *)(unaff_ESI + 0x60);
  }
  param_4 = (float)(int)ROUND((double)(fVar12 / ((float10)(int)param_4 * (float10)param_7) +
                                      (float10)_DAT_00829868));
  uVar6 = (uint)param_4 & 0x80000001;
  bVar11 = uVar6 == 0;
  if ((int)uVar6 < 0) {
    bVar11 = (uVar6 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (bVar11) {
    param_4 = (float)((int)param_4 + 1);
  }
  uVar6 = (uint)param_4;
  _local_10 = CONCAT44(DAT_00a38198,DAT_00a38194);
  local_8 = DAT_00a3819c;
  param_7 = (double)CONCAT44(param_7._4_4_,(float)(int)param_1 + local_20 * (float)_DAT_00804a60);
  fVar4 = (float)_DAT_00804a60 * local_1c;
  local_4 = DAT_00a381a0;
  FUN_005217e0(param_1,param_2,param_3,iVar9);
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  fVar3 = local_2c * (float)(-((*(int *)(unaff_ESI + 0x60) * (int)param_4) / 2) - param_5 % iVar1);
  fVar2 = local_2c * (float)(-((*(int *)(unaff_ESI + 100) * (int)param_4) / 2) - iVar7);
  param_1 = fVar3 * param_8 + fVar2 * param_6 + fVar4 + (float)(int)param_2;
  param_2 = (param_6 * fVar3 - param_8 * fVar2) + param_7._0_4_;
  if (0 < (int)param_4) {
    uVar8 = (uint)param_4;
    do {
      param_3 = param_2;
      param_4 = param_1;
      uVar10 = uVar6;
      while( true ) {
        fVar2 = param_4 + local_18;
        fVar4 = param_3 + local_14;
        FUN_00568f00(param_3,param_4,fVar4,fVar2,param_3 + local_28,param_4 + local_24,
                     local_28 + fVar4,local_24 + fVar2);
        uVar10 = uVar10 - 1;
        if (uVar10 == 0) break;
        param_3 = fVar4;
        param_4 = fVar2;
      }
      uVar8 = uVar8 - 1;
      param_2 = local_28 + param_2;
      param_1 = local_24 + param_1;
    } while (uVar8 != 0);
  }
  FUN_005217e0(local_10,uStack_c,local_8,local_4);
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  return 0;
}


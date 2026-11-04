
void __fastcall FUN_004c7d60(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_30;
  undefined4 local_14 [4];
  
  if (*param_1 != DAT_00a18a94) {
    FUN_004c8410();
  }
  if (DAT_00a14340 != '\0') {
    FUN_004c87e0();
  }
  if ((DAT_00a18a94 != -1) && (param_1[1] != -1)) {
    if (DAT_00a117bc == 0) {
      FUN_005160d0(0,0xff);
    }
    else if (DAT_00a117bc == 1) {
      FUN_005160d0(1,0xfe);
    }
    if (DAT_0084b248 * DAT_00a18174 == 100) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3,
                   (int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3,0,0,
                   param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),
                   param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),*puVar1,uVar9,
                   uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30(0,0,param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),
                   param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),
                   (int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3,
                   (int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3,*puVar1,uVar9,uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30(0,(int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3,
                   param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),0,
                   (int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3,
                   param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),*puVar1,uVar9,
                   uVar10,uVar11);
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      FUN_00526e30((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3,0,0,
                   param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),
                   param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),
                   (int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3,*puVar1,uVar9,uVar10,uVar11);
    }
    else {
      if ((3 < param_1[8]) && (param_1[8] < 8)) {
        param_1[8] = 8;
      }
      if ((3 < param_1[9]) && (param_1[9] < 8)) {
        param_1[9] = 8;
      }
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      local_14[0] = FUN_0052a120(0,0,param_1[6] -
                                     ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),
                                 param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),
                                 *puVar1);
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      local_14[1] = FUN_0052a120(param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),
                                 param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),
                                 (int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3,
                                 (int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3,*puVar1);
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      local_14[2] = FUN_0052a120(param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),0
                                 ,(int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3,
                                 param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3),
                                 *puVar1);
      uVar8 = 0;
      FUN_004cde80(param_1[1]);
      puVar1 = (undefined4 *)FUN_004ce990(uVar8);
      local_14[3] = FUN_0052a120(0,param_1[7] - ((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3)
                                 ,param_1[6] - ((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3),
                                 (int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3,*puVar1);
      iVar2 = (-DAT_00a1816c * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar4 = ((int)(param_1[8] * DAT_0084b248 + (param_1[8] * DAT_0084b248 >> 0x1f & 7U)) >> 3) +
              ((((int)(param_1[8] + (param_1[8] >> 0x1f & 7U)) >> 3) - DAT_00a1816c) * DAT_0084b248
              * (DAT_00a18174 + -100)) / 100;
      iVar5 = param_1[6] * DAT_0084b248 +
              ((param_1[6] - DAT_00a1816c) * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar3 = (-DAT_00a18170 * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      iVar6 = ((int)(param_1[9] * DAT_0084b248 + (param_1[9] * DAT_0084b248 >> 0x1f & 7U)) >> 3) +
              ((((int)(param_1[9] + (param_1[9] >> 0x1f & 7U)) >> 3) - DAT_00a18170) * DAT_0084b248
              * (DAT_00a18174 + -100)) / 100;
      iVar7 = param_1[7] * DAT_0084b248 +
              ((param_1[7] - DAT_00a18170) * DAT_0084b248 * (DAT_00a18174 + -100)) / 100;
      FUN_0051f060(iVar4,iVar6,iVar5,iVar7,local_14[0],0);
      FUN_0051f060(iVar2,iVar3,iVar4,iVar6,local_14[1],0);
      FUN_0051f060(iVar2,iVar6,iVar4,iVar7,local_14[2],0);
      FUN_0051f060(iVar4,iVar3,iVar5,iVar6,local_14[3],0);
      for (local_30 = 0; local_30 < 4; local_30 = local_30 + 1) {
        FUN_00515700(local_14[local_30],0);
      }
    }
  }
  return;
}


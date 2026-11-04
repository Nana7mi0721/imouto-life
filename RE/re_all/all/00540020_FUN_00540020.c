
undefined4
FUN_00540020(undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,short *param_12,int param_13)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if ((((param_12 == (short *)0x0) || (*param_12 == 0)) || (param_13 == 0)) || (DAT_00a37fd0 != 0))
  {
    return 0;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar6 = FUN_0052eda0(param_9);
  if (iVar6 == 0) {
    FUN_0056bb10(&DAT_007d5cdc);
    return 0xffffffff;
  }
  iVar1 = *(int *)(iVar6 + 0x93628);
  if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
    FUN_005198b0();
  }
  uVar5 = DAT_00a381a0;
  uVar4 = DAT_00a3819c;
  uVar3 = DAT_00a38198;
  uVar8 = DAT_00a38194;
  if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (iVar1 != 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (DAT_00ca39f4 == 0) {
      if (iVar1 == 0) {
        uVar8 = FUN_0053f260(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_12,
                             param_13,param_8,iVar6,param_10,param_11);
        return uVar8;
      }
      uVar8 = FUN_0053e750(param_1,param_2,0,0,1);
      return uVar8;
    }
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057b170(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
  }
  if (bVar2) {
    FUN_00519580();
    uVar7 = FUN_0053e750(param_1,param_2,0,0,1,param_3,param_4,param_5,param_6,param_7,param_12,
                         param_13,param_8,iVar6,param_10,param_11);
    FUN_00519650();
  }
  else if (iVar1 == 0) {
    uVar7 = FUN_0053f260(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_12,param_13,
                         param_8,iVar6,param_10,param_11);
  }
  else {
    uVar7 = FUN_0053e750(param_1,param_2,0,0,1,param_3,param_4,param_5,param_6,param_7,param_12,
                         param_13,param_8,iVar6,param_10,param_11);
  }
  if (DAT_00ca39f4 != 0) {
    FUN_0057ae10(uVar8,uVar3,uVar4,uVar5);
  }
  return uVar7;
}


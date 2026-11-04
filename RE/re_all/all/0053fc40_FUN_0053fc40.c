
undefined4
FUN_0053fc40(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,short *param_5,
            int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  if ((((param_5 != (short *)0x0) && (*param_5 != 0)) && (param_6 != 0)) && (DAT_00a37fd0 == 0)) {
    if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
      FUN_0050e770();
    }
    iVar2 = FUN_0052eda0();
    if (iVar2 == 0) {
      FUN_0056bb10();
      return 0xffffffff;
    }
    if ((DAT_00a381c4 == 0) && (DAT_00a37d78 != 0)) {
      FUN_005198b0();
    }
    if (((DAT_00a380cc == 3) && (DAT_00a37d8c == 0)) && (*(int *)(iVar2 + 0x93628) != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (DAT_00ca39f4 == 0) {
        if (*(int *)(iVar2 + 0x93628) == 0) {
          FUN_0050e270(param_2,param_3,param_4,param_5,param_6,param_7,iVar2,param_9,param_10);
          uVar4 = FUN_0050e270(param_1);
          uVar4 = FUN_0053ede0(uVar4);
          return uVar4;
        }
        uVar4 = FUN_0050e270(param_2,param_1,param_2,0,param_3,param_4,param_5,param_6,param_7,iVar2
                             ,param_9,param_10);
        uVar4 = FUN_0050e270(param_1,uVar4);
        uVar4 = FUN_0053e6a0(uVar4);
        return uVar4;
      }
    }
    iVar3 = FUN_0050e270();
    uVar4 = FUN_0050e270();
    iVar5 = DAT_00a3819c;
    if (param_10 == 0) {
      iVar6 = FUN_00536eb0(param_8);
      iVar6 = FUN_0050e240((double)iVar6 * param_4);
      iVar7 = FUN_0050e270();
      iVar6 = iVar6 + 3 + iVar7;
    }
    else {
      iVar5 = FUN_00536eb0(param_8);
      iVar6 = FUN_0050e240((double)iVar5 * param_4);
      iVar5 = FUN_0050e270();
      iVar5 = iVar6 + 3 + iVar5;
      iVar6 = DAT_00a381a0;
    }
    if (iVar3 < DAT_00a3819c) {
      if (DAT_00ca39f4 != 0) {
        FUN_0057b170(iVar3,uVar4,iVar5,iVar6);
      }
      if (bVar1) {
        FUN_00519580();
        uVar8 = FUN_0050e270(param_2,param_1,param_2,0,param_3,param_4,param_5,param_6,param_7,iVar2
                             ,param_9,param_10);
        uVar8 = FUN_0050e270(param_1,uVar8);
        uVar8 = FUN_0053e6a0(uVar8);
        FUN_00519650();
      }
      else if (*(int *)(iVar2 + 0x93628) == 0) {
        FUN_0050e270(param_2,param_3,param_4,param_5,param_6,param_7,iVar2,param_9,param_10);
        uVar8 = FUN_0050e270(param_1);
        uVar8 = FUN_0053ede0(uVar8);
      }
      else {
        uVar8 = FUN_0050e270(param_2,param_1,param_2,0,param_3,param_4,param_5,param_6,param_7,iVar2
                             ,param_9,param_10);
        uVar8 = FUN_0050e270(param_1,uVar8);
        uVar8 = FUN_0053e6a0(uVar8);
      }
      if (DAT_00ca39f4 != 0) {
        FUN_0057ae10(iVar3,uVar4,iVar5,iVar6);
      }
      return uVar8;
    }
  }
  return 0;
}


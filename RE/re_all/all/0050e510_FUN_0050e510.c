
undefined4 FUN_0050e510(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_364;
  int local_360;
  int local_35c;
  int local_358;
  undefined1 local_354 [108];
  undefined1 local_2e8 [744];
  
  uVar1 = DAT_00a24d40;
  if (DAT_00a21098 == 1) {
    return 0;
  }
  if (DAT_00a23d24 == 0) {
    return 0xffffffff;
  }
  DAT_00a24d40 = 1;
  iVar2 = FUN_00518000(DAT_00a23d30);
  if (iVar2 == 0) {
    DAT_00a23d30 = FUN_005282a0(&DAT_00a238f0,0,1,0);
    if (DAT_00a23d30 < 0) {
      DAT_00a24d40 = uVar1;
      return 0xffffffff;
    }
  }
  DAT_00a24d44 = 1;
  FUN_0051a1d0(local_2e8);
  FUN_0052a4a0(0xfffffffe);
  FUN_005160a0(1);
  FUN_00516710(0);
  FUN_005167a0(&local_364,&local_360);
  FUN_005194a0(local_354,0x20,0,0);
  uVar3 = FUN_005243b0(local_354,local_364,local_360,0,0,0,0,0);
  FUN_00521db0(0,0,local_364,local_360,uVar3,1);
  FUN_00515880(DAT_00a23d30,&local_35c,&local_358);
  if ((local_35c == local_364) && (local_358 == local_360)) {
    FUN_0051e930(0,0,DAT_00a23d30,0);
  }
  else {
    FUN_0051f060(0,0,local_364,local_360,DAT_00a23d30,0);
  }
  FUN_00527180();
  FUN_0051e930(0,0,uVar3,0);
  FUN_00515700(uVar3,0);
  FUN_0052b2d0(local_2e8);
  DAT_00a24d40 = uVar1;
  DAT_00a24d44 = 0;
  return 0;
}



undefined4 FUN_005de2d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = param_1;
  local_8 = param_2;
  local_4 = 1;
  FUN_005d52f0(DAT_00f3a1a0,0,&local_18,DAT_00ca39d4,DAT_00ca39d8,0,0);
  local_28 = 0;
  local_24 = 0;
  local_20 = param_1;
  local_1c = param_2;
  FUN_005caf30(DAT_00f3a194,DAT_00f3a198,&local_28,DAT_00f3a188,DAT_00f3a190,&local_28,0,0,0,0,0,0,0
               ,0);
  iVar1 = 0;
  do {
    if ((&DAT_00f1370c)[iVar1] == DAT_00f3a194) {
      FUN_005c2b20(DAT_00f3a188,DAT_00f3a190,iVar1);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  FUN_005d1f40(DAT_00f3a19c);
  FUN_005d1f20(DAT_00f3a198);
  FUN_005d1ee0(DAT_00f3a194);
  DAT_00f3a19c = 0;
  DAT_00f3a198 = 0;
  DAT_00f3a194 = 0;
  return 0;
}


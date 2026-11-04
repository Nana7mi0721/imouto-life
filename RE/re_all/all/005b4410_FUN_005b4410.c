
undefined4
FUN_005b4410(undefined4 param_1,uint param_2,int param_3,int param_4,uint param_5,int param_6,
            undefined4 param_7,undefined4 param_8,int param_9)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  iVar2 = FUN_005d35f0();
  if ((iVar2 != 0) && (DAT_00e79688 != 1)) {
    FUN_005d3930();
    DAT_00e79688 = 1;
    DAT_00e399fc = 0;
  }
  if (DAT_00f3a04c != 0) {
    if (DAT_00e39a54 == 0) {
      if (DAT_00e39a50 == 0) goto LAB_005b44b9;
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    DAT_00e39a1c = 1;
    DAT_00e39a00 = 1;
    if (DAT_00e39a50 != 0) {
      DAT_00e39a18 = 1;
    }
    DAT_00e39a50 = 0;
  }
LAB_005b44b9:
  param_5 = -(uint)(param_6 != 0) & 0x880 | param_5;
  uVar3 = param_5 | 0x5078;
  if (param_4 == 0) {
    if (DAT_00e39a4c == 0) goto LAB_005b4531;
    iVar2 = 0;
  }
  else {
    uVar3 = param_5 | 0xd078;
    if (*(char *)(*(int *)(param_4 + 0x4c) + 10) != '\0') {
      uVar3 = param_5 | 0x1d078;
    }
    if (*(char *)(*(int *)(param_4 + 0x4c) + 0x12) != '\0') {
      uVar3 = uVar3 | 0x20000;
    }
    piVar1 = (int *)**(undefined4 **)(param_4 + 0x100 + param_9 * 0x78);
    if (DAT_00e39a4c == *piVar1) goto LAB_005b4531;
    iVar2 = *piVar1;
  }
  FUN_0059bcf0(iVar2);
LAB_005b4531:
  if (((DAT_00a3d360 != 0) || (DAT_00e39a00 != 0)) || (DAT_00e399fc != uVar3)) {
    FUN_005a7f60();
  }
  FUN_005a7ce0();
  if (param_3 == 4) {
    param_2 = (int)param_2 / 3;
  }
  else if (param_3 == 2) {
    param_2 = (int)param_2 / 2;
  }
  else if ((param_3 == 6) || (param_3 == 5)) {
    param_2 = param_2 - 2;
  }
  else if (param_3 == 3) {
    param_2 = param_2 - 1;
  }
  else {
    param_2 = ~-(uint)(param_3 != 1) & param_2;
  }
  FUN_005d3b40(param_3,param_2,param_1,0x1c);
  DAT_00a37de4 = DAT_00a37de4 + 1;
  return 0;
}


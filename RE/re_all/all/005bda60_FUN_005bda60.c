
undefined4
FUN_005bda60(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (param_4 == 0) {
    if (DAT_00ef1b58 == 0) {
      uVar1 = DAT_00ee9bc0;
      iVar2 = DAT_00ee9b90;
    }
    else {
      uVar1 = DAT_00ef1b60;
      iVar2 = DAT_00ef1b58;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_4 + 0x4c) + 0x3c + param_8 * 0x1c);
    uVar1 = *(undefined4 *)(iVar2 + 8);
    iVar2 = *(int *)(iVar2 + 4);
  }
  iVar2 = FUN_005b8ce0(iVar2,uVar1,param_5,param_6,param_1,param_2,&DAT_00ef1b78);
  if (iVar2 < 0) {
    FUN_0056bb10(&DAT_007fd7e8);
    return 0xffffffff;
  }
  return 0;
}


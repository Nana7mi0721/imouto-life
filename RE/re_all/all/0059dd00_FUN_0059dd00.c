
undefined4 FUN_0059dd00(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_005fc460(*(undefined4 *)(param_1 + 0x38));
  iVar2 = *(int *)(param_2 + 0x4c);
  local_10 = 0;
  local_c = 0;
  local_8 = *(undefined4 *)(iVar2 + 0x48);
  local_4 = *(undefined4 *)(iVar2 + 0x4c);
  iVar2 = FUN_005d4b60(**(undefined4 **)(iVar2 + 0x3c),0,&local_14);
  if (iVar2 == 0) {
    FUN_005d3850(uVar1,&local_10,local_14,&local_10,0);
    FUN_005d3370(local_14);
  }
  return 0;
}


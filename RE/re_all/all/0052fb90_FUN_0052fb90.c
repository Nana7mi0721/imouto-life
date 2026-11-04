
undefined4 FUN_0052fb90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = param_3;
  if (param_1 == 0) {
    iVar1 = FUN_0056e030(0x10000000,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x16af);
  }
  else {
    iVar1 = param_1;
  }
  local_10 = param_2;
  local_18 = iVar1;
  iVar2 = FUN_00596760(&local_18,1,param_4);
  if (param_1 == 0) {
    FUN_0056e1d0(iVar1);
  }
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  return local_14;
}



undefined4 FUN_0052f840(undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  local_c = ~-(uint)(in_EAX != 0) & param_2;
  local_14 = 0;
  local_8 = 0;
  if (param_4 == 0) {
    if (unaff_EBX == 0) {
      iVar2 = FUN_0056e030(0x10000000,"..\\..\\..\\..\\Source\\Library\\Main\\DxFont.cpp",0x16af);
    }
    else {
      iVar2 = unaff_EBX;
    }
    local_10 = param_1;
    local_18 = iVar2;
    iVar1 = FUN_00596760(&local_18);
    if (unaff_EBX == 0) {
      FUN_0056e1d0(iVar2);
    }
  }
  else {
    local_18 = 0;
    local_10 = 0;
    iVar1 = FUN_00596760(&local_18,1,param_3);
  }
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  if (param_4 == 0) {
    local_8 = local_14;
  }
  return local_8;
}


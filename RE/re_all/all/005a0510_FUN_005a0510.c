
int FUN_005a0510(int param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if (DAT_00e804fc == param_1) {
    if (DAT_00e39a54 == 0) {
      return 0;
    }
  }
  else if (DAT_00e39a54 == 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  DAT_00e804fc = param_1;
  DAT_00e39a00 = 1;
  if (DAT_00e804f8 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = 0x3f800000;
  }
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    local_c = 0x3f800000;
  }
  local_8 = 0;
  local_4 = 0;
  FUN_0059cb80(&DAT_00ddb600,0,0,0x2b,&local_10,1,1);
  iVar1 = FUN_005d3a70(0x92,-(param_1 != 0) & 2);
  return -(uint)(iVar1 != 0);
}


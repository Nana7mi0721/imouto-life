
int FUN_005a05e0(int param_1)

{
  int iVar1;
  uint local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if ((param_1 == DAT_00e79874) && (DAT_00e39a54 == 0)) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  DAT_00e79874 = param_1;
  DAT_00e39a00 = 1;
  FUN_00597e70();
  local_4 = (uint)(param_1 != 0);
  FUN_0059cb80(&DAT_00ddb600,2,0,3,&local_4,1,1);
  iVar1 = FUN_005d3a70(0x1c,param_1);
  return -(uint)(iVar1 != 0);
}


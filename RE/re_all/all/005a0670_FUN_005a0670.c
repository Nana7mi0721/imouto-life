
int FUN_005a0670(int param_1)

{
  int iVar1;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if ((param_1 == DAT_00e79878) && (DAT_00e39a54 == 0)) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00a37dc8 != 0) {
    local_10 = (uint)(param_1 == 3);
    local_c = (uint)(param_1 == 1);
    local_8 = (uint)(param_1 == 2);
    local_4 = (uint)(param_1 != 0);
    FUN_0059cb80(&DAT_00ddb600,2,0,0,&local_10,4,1);
  }
  DAT_00e79878 = param_1;
  FUN_00597e70();
  iVar1 = FUN_005d3a70(0x8c,param_1);
  return -(uint)(iVar1 != 0);
}


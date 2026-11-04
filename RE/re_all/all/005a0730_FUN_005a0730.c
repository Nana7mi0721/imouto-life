
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005a0730(uint param_1)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0;
  }
  if ((param_1 == DAT_00e7987c) && (DAT_00e39a54 == 0)) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  local_8 = (float)_DAT_0081ec30;
  local_10 = (float)(param_1 >> 0x10 & 0xff) / local_8;
  local_c = (float)(param_1 >> 8 & 0xff) / local_8;
  local_8 = (float)(param_1 & 0xff) / local_8;
  local_4 = 0x3f800000;
  FUN_0059cb80(&DAT_00ddb600,3,0,8,&local_10,1,1);
  DAT_00e7987c = param_1;
  iVar1 = FUN_005d3a70(0x22,param_1);
  return -(uint)(iVar1 != 0);
}


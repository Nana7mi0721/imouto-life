
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005a0940(float param_1)

{
  int iVar1;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if ((DAT_00f3a04c == 0) || ((_DAT_00e79888 == param_1 && (DAT_00e39a54 == 0)))) {
    return 0;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  _DAT_00e79888 = param_1;
  local_10 = _DAT_00e79884 / (_DAT_00e79884 - _DAT_00e79880);
  local_c = (float)_DAT_00805148 / (_DAT_00e79884 - _DAT_00e79880);
  local_8 = param_1;
  local_4 = _DAT_007fc510;
  FUN_0059cb80(&DAT_00ddb600,0,0,10,&local_10,1,1);
  iVar1 = FUN_005d3a70(0x26,param_1);
  return -(uint)(iVar1 != 0);
}


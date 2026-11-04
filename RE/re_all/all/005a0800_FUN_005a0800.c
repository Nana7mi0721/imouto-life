
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a0800(float param_1,float param_2)

{
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c != 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if ((_DAT_00e79880 != param_1) || (DAT_00e39a54 == 1)) {
      _DAT_00e79880 = param_1;
      FUN_005d3a70(0x24,param_1);
      local_10 = _DAT_00e79884 / (_DAT_00e79884 - _DAT_00e79880);
      local_c = (float)_DAT_00805148 / (_DAT_00e79884 - _DAT_00e79880);
      local_8 = _DAT_00e79888;
      local_4 = _DAT_007fc510;
      FUN_0059cb80(&DAT_00ddb600,0,0,10,&local_10,1,1);
    }
    if ((_DAT_00e79884 != param_2) || (DAT_00e39a54 == 1)) {
      _DAT_00e79884 = param_2;
      FUN_005d3a70(0x25,param_2);
      local_10 = _DAT_00e79884 / (_DAT_00e79884 - _DAT_00e79880);
      local_c = (float)_DAT_00805148 / (_DAT_00e79884 - _DAT_00e79880);
      local_8 = _DAT_00e79888;
      local_4 = _DAT_007fc510;
      FUN_0059cb80(&DAT_00ddb600,0,0,10,&local_10,1,1);
      return 0;
    }
  }
  return 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00516450(float param_1,float param_2)

{
  if ((param_1 != _DAT_00a380ac) || (param_2 != _DAT_00a380b0)) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    _DAT_00a380ac = param_1;
    _DAT_00a380b0 = param_2;
    if (DAT_00a37d78 != 0) {
      FUN_00567cb0(param_1,param_2);
      return 0;
    }
  }
  return 0;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052ea50(undefined4 param_1,int param_2)

{
  _DAT_00a49750 = param_1;
  if (param_2 == 0) {
    _DAT_00a49754 = 0;
    return 0;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  FUN_00576f40(DAT_00aba250,&DAT_00a49754,0x2000,param_2);
  return 0;
}


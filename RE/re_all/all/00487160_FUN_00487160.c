
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00487160(int param_1,undefined4 param_2,undefined *param_3,undefined4 param_4)

{
  if (((int)param_3 < 1600000) || (1699999 < (int)param_3)) {
    if ((0x8c3a6f < (int)param_3) && ((int)param_3 < 9200000)) {
      param_3 = &DAT_008adae0 + (int)param_3 % 10 + *(int *)(param_1 + 0x14) * 10;
    }
  }
  else {
    param_3 = &DAT_00e4e1c0 + (int)param_3 % 100 + *(int *)(param_1 + 0x18) * 100;
  }
  _DAT_00a16444 = *(undefined4 *)(param_1 + 0x10);
  FUN_0043be80(param_2,param_3,param_4,0);
  return param_2;
}


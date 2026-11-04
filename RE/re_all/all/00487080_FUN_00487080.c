
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __thiscall FUN_00487080(int param_1,undefined *param_2)

{
  if (999999 < (int)param_2) {
    if (((int)param_2 < 1100000) || (1199999 < (int)param_2)) {
      if (((int)param_2 < 1600000) || (1699999 < (int)param_2)) {
        if ((0x8c3a6f < (int)param_2) && ((int)param_2 < 9200000)) {
          param_2 = &DAT_008adae0 + (int)param_2 % 10 + *(int *)(param_1 + 0x14) * 10;
        }
      }
      else {
        param_2 = &DAT_00e4e1c0 + (int)param_2 % 100 + *(int *)(param_1 + 0x18) * 100;
      }
    }
    else {
      param_2 = (undefined *)(*(int *)(param_1 + 0x14) * 10 + 1000000 + (int)param_2 % 10);
    }
    _DAT_00a16444 = *(undefined4 *)(param_1 + 0x10);
    param_2 = (undefined *)FUN_0043b320(param_2,0,0);
  }
  return param_2;
}


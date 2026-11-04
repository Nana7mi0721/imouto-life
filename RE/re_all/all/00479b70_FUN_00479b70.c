
undefined4 * __thiscall FUN_00479b70(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  FUN_004cb840(param_2 + 1);
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  *(undefined1 *)((int)param_1 + 0x21) = *(undefined1 *)((int)param_2 + 0x21);
  *(undefined1 *)((int)param_1 + 0x22) = *(undefined1 *)((int)param_2 + 0x22);
  *(undefined1 *)((int)param_1 + 0x23) = *(undefined1 *)((int)param_2 + 0x23);
  return param_1;
}


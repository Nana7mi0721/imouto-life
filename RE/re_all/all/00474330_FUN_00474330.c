
int __thiscall FUN_00474330(int param_1,int param_2)

{
  uint local_8;
  
  FUN_004d2fc0(param_2);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1) {
    *(undefined4 *)(param_1 + 0x14 + local_8 * 4) = *(undefined4 *)(param_2 + 0x14 + local_8 * 4);
  }
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_2 + 0x94);
  return param_1;
}


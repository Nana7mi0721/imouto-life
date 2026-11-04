
undefined4 FUN_005fc490(int param_1,double *param_2)

{
  *param_2 = (double)*(uint *)(param_1 + 0x438) / (double)*(uint *)(param_1 + 0x43c);
  *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 0x4d0);
  *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(param_1 + 0x428);
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 0x42c);
  return 0;
}



undefined4 FUN_005f9610(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x468) == 0) {
    FUN_006aaf00(param_1 + 0x52,param_2,param_2 >> 0x1f);
  }
  else {
    FUN_005f9670(param_1 + 0x52);
  }
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(undefined4 *)(param_1 + 0x458) = 0;
  *(uint *)(param_1 + 0x45c) = (uint)*(ushort *)(param_1 + 0x44) * param_2;
  return 0;
}


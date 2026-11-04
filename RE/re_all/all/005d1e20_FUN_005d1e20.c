
undefined4 FUN_005d1e20(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = **(undefined4 **)(param_1 + 0x10);
  local_c = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
  local_8 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 8);
  local_4 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc);
  (**(code **)(*DAT_00f3a074 + 200))(DAT_00f3a074,*(undefined4 *)(param_1 + 0xc),&local_10);
  return 0;
}


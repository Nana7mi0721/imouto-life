
undefined4 FUN_005fb0b0(int param_1,int param_2)

{
  if (param_2 < 1) {
    return 0;
  }
  FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xf4e);
  *(int *)(param_1 + 0x4d4) = *(int *)(param_1 + 0x4d4) + param_2;
  if (*(int *)(param_1 + 0x4d0) <= *(int *)(param_1 + 0x4d4)) {
    *(int *)(param_1 + 0x4d4) = *(int *)(param_1 + 0x4d4) - *(int *)(param_1 + 0x4d0);
  }
  *(undefined4 *)(param_1 + 0x4d8) =
       *(undefined4 *)(*(int *)(param_1 + 0x4bc) + *(int *)(param_1 + 0x4d4) * 4);
  *(undefined4 *)(param_1 + 0x92c) = 0;
  *(undefined4 *)(param_1 + 0x940) = 0;
  *(undefined4 *)(param_1 + 0x950) = 0;
  FUN_0056dac0(param_1);
  return 0;
}


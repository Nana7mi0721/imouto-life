
undefined4 FUN_005faf90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xef1);
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (*(int *)(param_1 + 0x4d0) <= param_2) {
    param_2 = *(int *)(param_1 + 0x4d0) + -1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x4bc) + param_2 * 4);
  if (iVar1 == *(int *)(param_1 + 0x4d8)) {
    FUN_0056dac0(param_1);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x92c) = 0;
  *(undefined4 *)(param_1 + 0x940) = 0;
  *(undefined4 *)(param_1 + 0x950) = 0;
  *(undefined4 *)(param_1 + 0x224) = 1;
  FUN_0056dac0(param_1);
  FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xf17);
  iVar2 = *(int *)(param_1 + 0x220);
  FUN_0056dac0(param_1);
  while (iVar2 != 4) {
    FUN_0056da20(0);
    FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xf17);
    iVar2 = *(int *)(param_1 + 0x220);
    FUN_0056dac0(param_1);
  }
  FUN_0056da60(param_1,s_D__DxLib_Develop_Source_Library__00a05f80,0xf27);
  *(int *)(param_1 + 0x4d8) = iVar1;
  *(int *)(param_1 + 0x4d4) = param_2;
  *(int *)(param_1 + 0x234) = iVar1;
  *(undefined4 *)(param_1 + 0x22c) = 1;
  *(undefined4 *)(param_1 + 0x224) = 0;
  FUN_0056dac0(param_1);
  return 0;
}


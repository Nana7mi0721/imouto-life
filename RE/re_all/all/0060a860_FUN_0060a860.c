
undefined4 FUN_0060a860(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = param_1 + 0x34;
  FUN_0056da60(iVar1,s_D__DxLib_Develop_Source_Library__00a06048,0x3a25);
  if (*(int *)(param_1 + 8) == 0) {
    FUN_0056dac0(iVar1);
    return 0x80004005;
  }
  if (*(int *)(param_1 + 0xc) == param_2) {
    *param_3 = *(undefined4 *)(param_1 + 0x20);
    (**(code **)(**(int **)(param_1 + 0xc) + 8))(*(int **)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    FUN_0056dac0(iVar1);
    return 0;
  }
  FUN_0056dac0(iVar1);
  return 0x80004005;
}


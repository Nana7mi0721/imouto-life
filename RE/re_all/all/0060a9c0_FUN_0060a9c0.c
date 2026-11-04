
undefined4 FUN_0060a9c0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x254) == 0) {
    return 0;
  }
  FUN_0056da60(param_1 + 0x34,s_D__DxLib_Develop_Source_Library__00a06048,0x3aba);
  *(undefined4 *)(param_1 + 0x25c) = 1;
  FUN_0056dac0(param_1 + 0x34);
  iVar1 = *(int *)(param_1 + 0x260);
  while (iVar1 == 0) {
    Sleep(2);
    iVar1 = *(int *)(param_1 + 0x260);
  }
  CloseHandle(*(HANDLE *)(param_1 + 600));
  *(undefined4 *)(param_1 + 600) = 0;
  *(undefined4 *)(param_1 + 0x254) = 0;
  return 0;
}



void FUN_0061feb0(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 0x28) != 0) {
    FUN_0061feb0(param_1,*(undefined4 *)(param_2 + 0x24));
    FUN_0061feb0(param_1,*(undefined4 *)(param_2 + 0x28));
  }
  if (param_2 == *param_1) {
    *param_1 = 0;
  }
  FUN_00646b80(param_1[1]);
  param_1[1] = param_2;
  return;
}


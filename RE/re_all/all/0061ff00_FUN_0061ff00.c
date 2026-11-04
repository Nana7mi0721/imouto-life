
void __fastcall FUN_0061ff00(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x28) != 0) {
      FUN_0061feb0(param_1,*(undefined4 *)(iVar1 + 0x24));
      FUN_0061feb0(param_1,*(undefined4 *)(iVar1 + 0x28));
    }
    if (iVar1 == *param_1) {
      *param_1 = 0;
    }
    FUN_00646b80(param_1[1]);
    param_1[1] = iVar1;
  }
  FUN_00646b80(param_1[1]);
  param_1[1] = 0;
  param_1[2] = -1;
  if (param_1[8] != 0) {
    if ((char)param_1[9] != '\0') {
      FUN_00646b80(param_1[8]);
    }
    param_1[8] = 0;
  }
  *(undefined1 *)(param_1 + 9) = 1;
  param_1[8] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0;
  return;
}



void __thiscall FUN_00640d70(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x233) != '\0') {
    *param_2 = 0;
    param_2[1] = 0;
    return;
  }
  *param_2 = 3;
  param_2[1] = 3;
  FUN_00643fa0(*(int *)(param_1 + 0x14) + 4,*(int *)(param_1 + 0x18) + 4,
               *(int *)(param_1 + 0x14) + 0x100,*(int *)(param_1 + 0x18) + 0x100);
  if (*(char *)(param_1 + 0x232) != '\0') {
    iVar1 = *param_2;
    iVar2 = param_2[1];
    *param_2 = iVar1 + 1;
    param_2[1] = iVar2 + -1;
    if ((*(float *)(param_1 + 0x1e0) < *(float *)(param_1 + 0x1ec)) &&
       (*(float *)(param_1 + 0x1e4) < *(float *)(param_1 + 0x1ec))) {
      *param_2 = iVar1 + 2;
      param_2[1] = iVar2 + -2;
    }
  }
  if (*(char *)(param_1 + 0x231) != '\0') {
    *param_2 = *param_2 + 1;
    param_2[1] = param_2[1] + -1;
  }
  return;
}


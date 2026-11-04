
void __thiscall FUN_0062f1e0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0xd8) = *param_2;
  *(undefined4 *)(param_1 + 0xdc) = param_2[1];
  *(undefined4 *)(param_1 + 0xe0) = param_2[2];
  *(undefined4 *)(param_1 + 0xe4) = param_2[3];
  if (0 < *(int *)(param_1 + 200)) {
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xd0) + iVar2 * 4) + 0xd4);
      if ((iVar1 != 2) && (iVar1 != 5)) {
        FUN_0063bb60(param_2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 200));
  }
  return;
}


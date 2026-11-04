
void FUN_0060e430(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x29c) < 1) {
    *(undefined4 *)(param_1 + 0x29c) = 0;
    return;
  }
  iVar1 = param_1 + 4;
  do {
    FUN_006168d0(iVar1);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xa4;
  } while (iVar2 < *(int *)(param_1 + 0x29c));
  *(undefined4 *)(param_1 + 0x29c) = 0;
  return;
}


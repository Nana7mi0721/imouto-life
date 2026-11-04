
void FUN_0079c5b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0x924);
  iVar2 = 0;
  iVar3 = 0;
  if (iVar1 < 1) {
    *(undefined4 *)(param_1 + 0x1034) = 0;
    *(undefined4 *)(param_1 + 0x1038) = 0x307880;
    return;
  }
  puVar4 = (undefined2 *)(param_1 + 0xfd4);
  do {
    iVar2 = iVar2 + (int)(0x7fff / (longlong)(iVar1 + 1));
    iVar3 = iVar3 + 1;
    *puVar4 = (short)iVar2;
    puVar4 = puVar4 + 1;
  } while (iVar3 < *(int *)(param_1 + 0x924));
  *(undefined4 *)(param_1 + 0x1034) = 0;
  *(undefined4 *)(param_1 + 0x1038) = 0x307880;
  return;
}


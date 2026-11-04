
void __thiscall FUN_006171e0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(param_1 + 0x70 + param_2 * 0xa4);
  puVar4 = (undefined4 *)(param_1 + 4 + param_2 * 0xa4);
  if ((iVar2 != 0) && (DAT_00f3f3e0 != (code *)0x0)) {
    (*DAT_00f3f3e0)(iVar2);
    puVar4[0x1b] = 0;
  }
  iVar2 = *(int *)(param_1 + 0x29c) + -1;
  if (param_2 != iVar2) {
    puVar1 = (undefined4 *)(param_1 + iVar2 * 0xa4);
    puVar3 = puVar1;
    for (iVar2 = 0x29; puVar3 = puVar3 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    *(undefined1 *)(puVar1 + 0x1e) = 0;
    puVar1[0x1f] = 0;
    puVar1[0x20] = 0;
    puVar1[0x21] = 0;
  }
  *(int *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + -1;
  return;
}


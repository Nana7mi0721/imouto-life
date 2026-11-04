
void __thiscall FUN_00797490(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 < param_3) {
    iVar1 = param_2 * 0x20;
    puVar3 = (undefined4 *)(param_4 + iVar1);
    param_3 = param_3 - param_2;
    do {
      if (puVar3 != (undefined4 *)0x0) {
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar1);
        puVar5 = puVar3;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      iVar1 = iVar1 + 0x20;
      puVar3 = puVar3 + 8;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


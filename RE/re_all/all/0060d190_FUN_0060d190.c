
void __thiscall FUN_0060d190(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 8) < param_2) {
    if (param_2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00646b30(param_2 << 4,0x10);
    }
    iVar4 = *(int *)(param_1 + 4);
    if (0 < iVar4) {
      puVar3 = (undefined4 *)(iVar1 + 8);
      do {
        if (puVar3 != (undefined4 *)0x8) {
          puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + (-8 - iVar1) + (int)puVar3);
          puVar3[-2] = *puVar2;
          puVar3[-1] = puVar2[1];
          *puVar3 = puVar2[2];
          puVar3[1] = puVar2[3];
        }
        puVar3 = puVar3 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      if (*(char *)(param_1 + 0x10) != '\0') {
        FUN_00646b80(*(int *)(param_1 + 0xc));
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined1 *)(param_1 + 0x10) = 1;
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}


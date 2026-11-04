
void __thiscall FUN_00793310(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (*(int *)(param_1 + 8) < param_2) {
    if (param_2 == 0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = (undefined4 *)FUN_00646b30(param_2 << 4,0x10);
    }
    iVar4 = *(int *)(param_1 + 4);
    if (0 < iVar4) {
      iVar3 = 0;
      puVar2 = puVar1;
      do {
        if (puVar2 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3);
          *puVar2 = *puVar5;
          puVar2[1] = puVar5[1];
          puVar2[2] = puVar5[2];
          puVar2[3] = puVar5[3];
        }
        iVar3 = iVar3 + 0x10;
        puVar2 = puVar2 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      if (*(char *)(param_1 + 0x10) != '\0') {
        FUN_00646b80(*(int *)(param_1 + 0xc));
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    *(undefined4 **)(param_1 + 0xc) = puVar1;
    *(undefined1 *)(param_1 + 0x10) = 1;
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}


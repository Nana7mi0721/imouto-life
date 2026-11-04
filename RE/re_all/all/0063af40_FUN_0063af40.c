
void __thiscall FUN_0063af40(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_4;
  
  if (*(int *)(param_1 + 8) < param_2) {
    if (param_2 == 0) {
      local_4 = (undefined4 *)0x0;
    }
    else {
      local_4 = (undefined4 *)FUN_00646b30(param_2 * 0x88,0x10);
    }
    iVar4 = *(int *)(param_1 + 4);
    if (0 < iVar4) {
      iVar3 = 0;
      puVar1 = local_4;
      do {
        if (puVar1 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3);
          puVar6 = puVar1;
          for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
        }
        iVar3 = iVar3 + 0x88;
        puVar1 = puVar1 + 0x22;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      if (*(char *)(param_1 + 0x10) != '\0') {
        FUN_00646b80(*(int *)(param_1 + 0xc));
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    *(undefined1 *)(param_1 + 0x10) = 1;
    *(undefined4 **)(param_1 + 0xc) = local_4;
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}


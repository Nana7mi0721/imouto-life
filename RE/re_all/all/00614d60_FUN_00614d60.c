
void __thiscall FUN_00614d60(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 4);
  if (iVar6 <= param_2) {
    if ((iVar6 < param_2) && (*(int *)(param_1 + 8) < param_2)) {
      if (param_2 == 0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)FUN_00646b30(param_2 * 8,0x10);
      }
      iVar1 = *(int *)(param_1 + 4);
      iVar4 = 0;
      if (0 < iVar1) {
        puVar5 = puVar3;
        do {
          if (puVar5 != (undefined4 *)0x0) {
            iVar2 = *(int *)(param_1 + 0xc);
            *puVar5 = *(undefined4 *)(iVar2 + iVar4 * 8);
            puVar5[1] = *(undefined4 *)(iVar2 + 4 + iVar4 * 8);
          }
          iVar4 = iVar4 + 1;
          puVar5 = puVar5 + 2;
        } while (iVar4 < iVar1);
      }
      if (*(int *)(param_1 + 0xc) != 0) {
        if (*(char *)(param_1 + 0x10) != '\0') {
          FUN_00646b80(*(int *)(param_1 + 0xc));
        }
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      *(undefined4 **)(param_1 + 0xc) = puVar3;
      *(undefined1 *)(param_1 + 0x10) = 1;
      *(int *)(param_1 + 8) = param_2;
    }
    for (; iVar6 < param_2; iVar6 = iVar6 + 1) {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar6 * 8);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = *param_3;
        puVar3[1] = param_3[1];
      }
    }
  }
  *(int *)(param_1 + 4) = param_2;
  return;
}


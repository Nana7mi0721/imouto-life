
int __thiscall FUN_0063ac90(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_c;
  undefined4 *local_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    if (iVar1 == 0) {
      local_c = 1;
    }
    else {
      local_c = iVar1 * 2;
    }
    if (*(int *)(param_1 + 8) < local_c) {
      if (local_c == 0) {
        local_8 = (undefined4 *)0x0;
      }
      else {
        local_8 = (undefined4 *)FUN_00646b30(local_c * 0x68,0x10);
      }
      iVar4 = *(int *)(param_1 + 4);
      if (0 < iVar4) {
        iVar3 = 0;
        puVar7 = local_8;
        do {
          if (puVar7 != (undefined4 *)0x0) {
            puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3);
            puVar6 = puVar7;
            for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar6 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar6 = puVar6 + 1;
            }
          }
          iVar3 = iVar3 + 0x68;
          puVar7 = puVar7 + 0x1a;
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
      *(undefined4 **)(param_1 + 0xc) = local_8;
      *(int *)(param_1 + 8) = local_c;
    }
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  puVar7 = (undefined4 *)(iVar1 * 0x68 + *(int *)(param_1 + 0xc));
  if (puVar7 != (undefined4 *)0x0) {
    for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *param_2;
      param_2 = param_2 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  return iVar1 * 0x68 + *(int *)(param_1 + 0xc);
}


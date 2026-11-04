
void __thiscall FUN_00792720(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x3c) != '\0') {
    FUN_00793ee0(param_3,param_4,0x3f800000);
    FUN_007929c0(param_2,0,*(undefined4 *)(param_1 + 0x38),0);
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x98)) {
      iVar4 = 0;
      do {
        puVar1 = (undefined2 *)(*(int *)(param_1 + 0xa0) + iVar4);
        iVar4 = iVar4 + 0x20;
        puVar2 = (undefined2 *)(*(int *)(puVar1 + 6) * 0x10 + *(int *)(param_1 + 0x88));
        iVar3 = iVar3 + 1;
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        puVar1[3] = puVar2[3];
        puVar1[4] = puVar2[4];
        puVar1[5] = puVar2[5];
      } while (iVar3 < *(int *)(param_1 + 0x98));
    }
  }
  return;
}


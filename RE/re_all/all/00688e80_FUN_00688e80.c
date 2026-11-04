
void FUN_00688e80(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0xd8);
  iVar4 = 0;
  *(undefined4 **)(param_1 + 0x1b0) = puVar1;
  *puVar1 = &LAB_00688f20;
  if (*(char *)(param_1 + 0xc9) == '\0') {
    puVar1 = puVar1 + 0x10;
    iVar4 = 4;
    do {
      puVar1[4] = 0;
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    return;
  }
  puVar2 = (undefined4 *)
           (*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,*(int *)(param_1 + 0x24) << 8);
  *(undefined4 **)(param_1 + 0x8c) = puVar2;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      puVar5 = puVar2;
      for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0xffffffff;
        puVar5 = puVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 0x40;
    } while (iVar4 < *(int *)(param_1 + 0x24));
  }
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  return;
}


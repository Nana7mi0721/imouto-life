
void FUN_00692710(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = (int)param_1;
  iVar1 = *(int *)((int)param_1 + 0x198);
  FUN_00691f60(param_1);
  FUN_00692100(0xff,param_1);
  FUN_00692100(param_2 + 0xd0,param_1);
  param_2 = 0;
  if (0 < *(int *)((int)param_1 + 0x114)) {
    param_1 = (int *)((int)param_1 + 0x118);
    puVar5 = (undefined4 *)(iVar1 + 0x34);
    do {
      iVar2 = *param_1;
      if ((*(int *)(iVar3 + 0x15c) == 0) && (*(int *)(iVar3 + 0x164) == 0)) {
        puVar6 = *(undefined4 **)(iVar1 + 0x4c + *(int *)(iVar2 + 0x14) * 4);
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        puVar5[-4] = 0;
        *puVar5 = 0;
      }
      if (*(int *)(iVar3 + 0x160) != 0) {
        puVar6 = *(undefined4 **)(iVar1 + 0x8c + *(int *)(iVar2 + 0x18) * 4);
        for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
      }
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      puVar5 = puVar5 + 1;
    } while (param_2 < *(int *)(iVar3 + 0x114));
  }
  *(undefined4 *)(iVar1 + 0x10) = 0x10000;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0xb;
  *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
  return;
}


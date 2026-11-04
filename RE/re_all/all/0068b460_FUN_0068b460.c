
void FUN_0068b460(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iStack_4;
  
  piVar3 = param_1;
  iVar1 = param_1[0x6c];
  cVar4 = (**(code **)(param_1[0x6b] + 8))(param_1);
  if (cVar4 == '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x19;
    (**(code **)*param_1)(param_1);
  }
  iStack_4 = 0;
  if (0 < param_1[0x4c]) {
    param_1 = param_1 + 0x4d;
    puVar6 = (undefined4 *)(iVar1 + 0x24);
    do {
      iVar2 = *param_1;
      if ((*(char *)((int)piVar3 + 0xc9) == '\0') || ((piVar3[0x5e] == 0 && (piVar3[0x60] == 0)))) {
        puVar7 = *(undefined4 **)(iVar1 + 0x38 + *(int *)(iVar2 + 0x14) * 4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
        puVar6[-4] = 0;
        *puVar6 = 0;
      }
      if (*(char *)((int)piVar3 + 0xc9) == '\0') {
        iVar5 = piVar3[100];
      }
      else {
        iVar5 = piVar3[0x5e];
      }
      if (iVar5 != 0) {
        puVar7 = *(undefined4 **)(iVar1 + 0x78 + *(int *)(iVar2 + 0x18) * 4);
        for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
        }
      }
      iStack_4 = iStack_4 + 1;
      param_1 = param_1 + 1;
      puVar6 = puVar6 + 1;
    } while (iStack_4 < piVar3[0x4c]);
  }
  *(undefined4 *)(iVar1 + 0x10) = 0xfffffff0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(int *)(iVar1 + 0x34) = piVar3[0x3f];
  return;
}


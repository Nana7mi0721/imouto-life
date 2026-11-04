
undefined4 FUN_00682a80(int *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  puVar3 = (undefined4 *)param_1[6];
  iVar7 = puVar3[1];
  puVar5 = (undefined1 *)*puVar3;
  if (iVar7 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    puVar5 = (undefined1 *)*puVar3;
    iVar7 = puVar3[1];
  }
  iVar7 = iVar7 + -1;
  uVar1 = *puVar5;
  puVar5 = puVar5 + 1;
  if (iVar7 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    puVar5 = (undefined1 *)*puVar3;
    iVar7 = puVar3[1];
  }
  iVar7 = iVar7 + -1;
  puVar6 = puVar5 + 1;
  if (CONCAT11(uVar1,*puVar5) != 4) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    (**(code **)*param_1)(param_1);
  }
  if (iVar7 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar3;
    iVar7 = puVar3[1];
  }
  iVar7 = iVar7 + -1;
  uVar1 = *puVar6;
  puVar6 = puVar6 + 1;
  if (iVar7 == 0) {
    cVar4 = (*(code *)puVar3[3])(param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    puVar6 = (undefined1 *)*puVar3;
    iVar7 = puVar3[1];
  }
  uVar2 = *puVar6;
  *(undefined4 *)(*param_1 + 0x14) = 0x54;
  *(uint *)(*param_1 + 0x18) = (uint)CONCAT11(uVar1,uVar2);
  (**(code **)(*param_1 + 4))(param_1,1);
  param_1[0x3f] = (uint)CONCAT11(uVar1,uVar2);
  puVar3[1] = iVar7 + -1;
  *puVar3 = puVar6 + 1;
  return 1;
}


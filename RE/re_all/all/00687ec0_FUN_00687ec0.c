
void FUN_00687ec0(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x74);
  *(undefined4 **)(param_1 + 0x1a0) = puVar2;
  *puVar2 = &LAB_00687fe0;
  puVar2[2] = FUN_00688060;
  puVar2[0x1c] = 0;
  if (param_2 == '\0') {
    puVar4 = (undefined4 *)(**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    puVar5 = puVar2 + 8;
    iVar8 = 10;
    puVar7 = puVar4;
    do {
      *puVar5 = puVar7;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 0x20;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    if (*(int *)(param_1 + 400) == 0) {
      for (iVar8 = 0x140; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    puVar2[1] = FUN_0060b400;
    puVar2[3] = &LAB_006880b0;
    puVar2[4] = 0;
    return;
  }
  _param_2 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    piVar9 = (int *)(*(int *)(param_1 + 0xc4) + 0xc);
    puVar5 = puVar2 + 0x12;
    do {
      iVar8 = *piVar9;
      iVar6 = iVar8;
      if (*(char *)(param_1 + 0xc9) != '\0') {
        iVar6 = iVar8 * 3;
      }
      iVar1 = *(int *)(param_1 + 4);
      uVar3 = FUN_006848c0(piVar9[5],iVar8,iVar6);
      uVar3 = FUN_006848c0(piVar9[4],piVar9[-1],uVar3);
      uVar3 = (**(code **)(iVar1 + 0x14))(param_1,1,1,uVar3);
      *puVar5 = uVar3;
      _param_2 = _param_2 + 1;
      puVar5 = puVar5 + 1;
      piVar9 = piVar9 + 0x16;
    } while (_param_2 < *(int *)(param_1 + 0x24));
  }
  puVar2[1] = &LAB_00688310;
  puVar2[3] = &LAB_00688530;
  puVar2[4] = puVar2 + 0x12;
  return;
}


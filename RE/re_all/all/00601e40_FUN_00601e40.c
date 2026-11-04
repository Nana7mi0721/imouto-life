
undefined4 __thiscall FUN_00601e40(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_EBX;
  int *unaff_EDI;
  undefined4 **ppuVar6;
  int **ppiVar7;
  int *apiStack_34 [2];
  int iStack_2c;
  undefined4 *apuStack_28 [4];
  undefined4 *puStack_18;
  int *piStack_14;
  int local_4;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  local_4 = param_1;
  if (piVar1 != (int *)0x0) {
    if (*(int *)(param_1 + 0x28) == 0) {
      iStack_2c = 0;
    }
    else {
      iStack_2c = *(int *)(param_1 + 0x28) + 0xc;
    }
    iVar3 = *piVar1;
    ppuVar6 = apuStack_28;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppuVar6 = (undefined4 *)*param_2;
      param_2 = param_2 + 1;
      ppuVar6 = ppuVar6 + 1;
    }
    apiStack_34[0] = (int *)0x601e72;
    apiStack_34[1] = piVar1;
    uVar2 = (**(code **)(iVar3 + 0xc))();
    return uVar2;
  }
  apuStack_28[3] = *(undefined4 **)(param_1 + 0x18);
  uVar2 = 0x80040216;
  if (apuStack_28[3] != (undefined4 *)0x0) {
    piStack_14 = &local_4;
    puStack_18 = &DAT_0085ea04;
    apuStack_28[2] = (undefined4 *)0x601e94;
    (**(code **)*apuStack_28[3])();
    if (unaff_EDI != (int *)0x0) {
      if (*(int *)(param_1 + 0x28) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x28) + 0xc;
      }
      iVar4 = *unaff_EDI;
      ppiVar7 = apiStack_34;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppiVar7 = (int *)*unaff_EBX;
        unaff_EBX = unaff_EBX + 1;
        ppiVar7 = ppiVar7 + 1;
      }
      uVar2 = (**(code **)(iVar4 + 0xc))(unaff_EDI,iVar3);
      (**(code **)(*apiStack_34[1] + 8))(apiStack_34[1]);
    }
  }
  return uVar2;
}


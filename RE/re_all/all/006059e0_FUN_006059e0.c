
void FUN_006059e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_24 [6];
  
  iVar1 = **(int **)(param_1 + 0x90);
  puVar3 = &param_3;
  puVar4 = auStack_24;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar1 = (**(code **)(iVar1 + 0x40))();
  if (iVar1 == 1) {
    FUN_00601e40(auStack_24 + 6);
  }
  return;
}


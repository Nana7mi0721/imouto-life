
void FUN_0068c290(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x1c);
  *(undefined4 **)(param_1 + 0x1a4) = puVar2;
  *puVar2 = &LAB_0068c320;
  puVar2[2] = 0;
  puVar2[3] = 0;
  if (*(char *)(param_1 + 0x4a) != '\0') {
    uVar3 = *(undefined4 *)(param_1 + 0x11c);
    puVar2[4] = uVar3;
    if (param_2 != '\0') {
      iVar1 = *(int *)(param_1 + 4);
      uVar3 = FUN_006848c0(*(undefined4 *)(param_1 + 0x60),uVar3,uVar3);
      uVar3 = (**(code **)(iVar1 + 0x10))
                        (param_1,1,0,*(int *)(param_1 + 100) * *(int *)(param_1 + 0x5c),uVar3);
      puVar2[2] = uVar3;
      return;
    }
    uVar3 = (**(code **)(*(int *)(param_1 + 4) + 8))
                      (param_1,1,*(int *)(param_1 + 100) * *(int *)(param_1 + 0x5c),uVar3);
    puVar2[3] = uVar3;
  }
  return;
}


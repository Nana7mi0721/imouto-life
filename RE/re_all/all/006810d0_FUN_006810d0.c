
void FUN_006810d0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0xa8);
  *(undefined4 **)(param_1 + 0x1ac) = puVar1;
  *puVar1 = FUN_00683120;
  puVar1[1] = &LAB_00681690;
  puVar1[2] = FUN_00683090;
  puVar1[6] = FUN_006815f0;
  puVar1[0x17] = 0;
  puVar2 = puVar1 + 0x18;
  iVar3 = 0x10;
  do {
    puVar2[-0x11] = FUN_006815f0;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1[7] = &LAB_00681140;
  puVar1[0x15] = &LAB_00681140;
  FUN_00683120(param_1);
  return;
}


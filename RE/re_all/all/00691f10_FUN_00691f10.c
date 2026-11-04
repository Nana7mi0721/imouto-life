
void FUN_00691f10(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0xd0);
  *(undefined4 **)(param_1 + 0x198) = puVar1;
  *puVar1 = &LAB_00692140;
  puVar1[2] = FUN_00691f60;
  puVar2 = puVar1 + 0x23;
  iVar3 = 0x10;
  do {
    puVar2[-0x10] = 0;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)(puVar1 + 0x33) = 0x71;
  return;
}


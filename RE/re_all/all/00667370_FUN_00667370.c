
void FUN_00667370(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x465;
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x98) + 72000);
  do {
    puVar1[-0xe] = 0xffffffff;
    puVar1[-0xc] = 0xffffffff;
    puVar1[-10] = 0xffffffff;
    puVar1[-8] = 0xffffffff;
    puVar1[-6] = 0xffffffff;
    puVar1[-4] = 0xffffffff;
    puVar1[-2] = 0xffffffff;
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + -0x10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 1;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + -2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


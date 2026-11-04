
void FUN_006905e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x8c);
  *(undefined4 **)(param_1 + 0x198) = puVar1;
  *puVar1 = &LAB_00690630;
  puVar2 = puVar1 + 0xb;
  iVar3 = 4;
  do {
    puVar2[4] = 0;
    *puVar2 = 0;
    puVar2[0xc] = 0;
    puVar2[8] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (*(char *)(param_1 + 0xfc) != '\0') {
    puVar1[0x22] = 0;
  }
  return;
}


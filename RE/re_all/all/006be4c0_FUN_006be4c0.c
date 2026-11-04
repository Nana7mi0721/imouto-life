
uint FUN_006be4c0(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint local_10 [4];
  
  puVar2 = local_10;
  iVar3 = 4;
  do {
    uVar1 = FUN_006bf0c0(param_1,8);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return ((local_10[3] << 8 | local_10[2]) << 8 | local_10[1]) << 8 | local_10[0];
}


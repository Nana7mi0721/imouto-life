
void FUN_005408d0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_00a52820 < 1) {
    param_1[10] = DAT_00a52820;
    param_1[0xb] = param_2;
    return;
  }
  puVar1 = param_1;
  do {
    *puVar1 = *(undefined4 *)(((int)&DAT_00a527f8 - (int)param_1) + (int)puVar1);
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < DAT_00a52820);
  param_1[10] = DAT_00a52820;
  param_1[0xb] = param_2;
  return;
}



void FUN_0066c900(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_328 [202];
  
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = param_1;
    puVar3 = local_328;
    for (iVar1 = 0xca; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = param_1;
    for (iVar1 = 0xca; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    FUN_0066cb60(local_328,param_1);
    FUN_00668cb0(local_328);
  }
  return;
}


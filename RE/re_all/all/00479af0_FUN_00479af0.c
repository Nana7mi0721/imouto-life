
int __thiscall FUN_00479af0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_00479b70(param_2);
  puVar2 = (undefined4 *)(param_2 + 0x24);
  puVar3 = (undefined4 *)(param_1 + 0x24);
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00473ea0(param_2 + 0x4c);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
  FUN_004cead0(param_2 + 0x68);
  FUN_004cd5b0(param_2 + 0x78);
  return param_1;
}


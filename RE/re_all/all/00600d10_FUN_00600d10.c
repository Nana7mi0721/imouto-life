
undefined4 __thiscall FUN_00600d10(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puStack_c;
  
  puVar2 = param_2;
  puStack_c = &param_2;
  *param_2 = 0;
  piVar1 = (int *)param_1[6];
  iVar3 = (**(code **)(*piVar1 + 0x18))();
  if (iVar3 < 0) {
    return 0x80004001;
  }
  puVar4 = &DAT_0085e9e4;
  iVar3 = (**(code **)*param_1)(param_1,&DAT_0085e9e4,&puStack_c);
  (**(code **)(*piVar1 + 8))(piVar1);
  if (iVar3 < 0) {
    return 0x80004001;
  }
  *puVar2 = puVar4;
  return 0;
}


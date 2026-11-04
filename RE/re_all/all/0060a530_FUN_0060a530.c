
void __fastcall FUN_0060a530(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_00803ea4;
  FUN_0060a9c0(param_1);
  piVar1 = (int *)param_1[0xc];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0xc] = 0;
  }
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[3] = 0;
  }
  FUN_0056da50(param_1 + 0xd);
  FUN_0056d380(param_1 + 0xd,0,0x220);
  return;
}


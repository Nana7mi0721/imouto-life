
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005639a0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  
  piVar1 = (int *)FUN_005636b0(param_2);
  if (piVar1 == (int *)0x0) {
    return 0x80070057;
  }
  param_2 = 0;
  iVar2 = (**(code **)*piVar1)(piVar1,&DAT_0085ef94,&param_2);
  if (-1 < iVar2) {
    _DAT_00aae0c4 = _DAT_00aae0c4 + -1;
    if (_DAT_00aae0c4 == 0) {
      if (DAT_00aa6ffc != 0) {
        FUN_0056e1d0(DAT_00aa6ffc);
        DAT_00aa6ffc = 0;
      }
      DAT_00aa7000 = 0;
    }
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return 0;
}


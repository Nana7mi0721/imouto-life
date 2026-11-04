
undefined4 FUN_00563940(undefined4 param_1,undefined4 param_2)

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
    FUN_00563700();
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return 0;
}


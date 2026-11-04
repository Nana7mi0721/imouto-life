
undefined4 FUN_005a0b10(int *param_1)

{
  int iVar1;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((((*param_1 == DAT_00e80604) && (param_1[2] == DAT_00e8060c)) && (param_1[1] == DAT_00e80608))
     && (param_1[3] == DAT_00e80610)) {
    if (DAT_00e39a54 == 0) {
      return 0;
    }
  }
  else if (DAT_00e39a54 == 0) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
  }
  iVar1 = FUN_005d35f0();
  if ((iVar1 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  FUN_005d3af0(param_1);
  DAT_00e80604 = *param_1;
  DAT_00e80608 = param_1[1];
  DAT_00e8060c = param_1[2];
  DAT_00e80610 = param_1[3];
  return 0;
}



undefined4 FUN_005a09f0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if ((((*param_1 == DAT_00e80b60) && (param_1[1] == DAT_00e80b64)) && (param_1[2] == DAT_00e80b68))
     && (param_1[3] == DAT_00e80b6c)) {
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
  iVar1 = FUN_005d39d0(param_1);
  if (iVar1 == 0) {
    DAT_00e80b60 = *param_1;
    DAT_00e80b64 = param_1[1];
    DAT_00e80b68 = param_1[2];
    DAT_00e80b6c = param_1[3];
    DAT_00e80b70 = param_1[4];
    DAT_00e80b74 = param_1[5];
    return 0;
  }
  uVar2 = FUN_0056bca0(&DAT_007fc518,iVar1);
  return uVar2;
}


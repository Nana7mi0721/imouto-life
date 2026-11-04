
undefined4 FUN_00567690(undefined4 param_1)

{
  if (DAT_00a49730 != 0) {
switchD_005676a3_default:
    return 0xffffffff;
  }
  switch(param_1) {
  case 0:
    DAT_00a37d7c = 1;
    FUN_00567690(1);
    if (DAT_00a49730 != 1) {
      DAT_00aaf0e0 = 1;
      return 0;
    }
    break;
  case 1:
    FUN_0059d6d0(0);
    return 0;
  case 2:
    FUN_0059d6d0(1);
    return 0;
  case 3:
    DAT_00a37d7c = 0;
    DAT_00aaf0e0 = 0;
    break;
  default:
    goto switchD_005676a3_default;
  }
  return 0;
}


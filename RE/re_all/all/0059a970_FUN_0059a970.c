
undefined4 FUN_0059a970(int param_1)

{
  char cVar1;
  
  if (DAT_00f3a04c != 0) {
    if (DAT_00e39a54 == 0) {
      if (DAT_00e79844 == param_1) {
        return 0;
      }
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
    }
    if (param_1 == 2) {
      cVar1 = '\x02';
    }
    else {
      cVar1 = (param_1 != 0) * '\x02' + '\x01';
    }
    FUN_005d3a70(0x16,cVar1);
    DAT_00e79844 = param_1;
    DAT_00e39a00 = 1;
  }
  return 0;
}

